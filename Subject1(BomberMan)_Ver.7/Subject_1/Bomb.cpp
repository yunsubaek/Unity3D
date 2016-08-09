#include "Bomb.h"
#include "Update.h"
#include "Singleton.h"
#include <time.h>

void Bomb::Player_Bomb_Attack(int i)
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4]	= { -1,1,0,0 };
	int idy[4]	= { 0,0,-1,1 };
	int x		= S->Player_Bomb_list[i]->Get_X();
	int y		= S->Player_Bomb_list[i]->Get_Y();

	S->Map[y][x] = 0;

	for (int j = 0; j < 4; j++)
	{
		if (S->Player_Bomb_Size == 0)break;

		int n_y = y + idx[j];
		int n_x = x + idy[j];

		if (S->Map[n_y][n_x] == T_player)
		{
			S->End_Flag = true;
			Update().Output();
			printf("Game Over!");
			return;
		}
		else if (S->Map[n_y][n_x] == T_monster)
		{
			S->Map[n_y][n_x] = T_empty;
			for (int k = 0; k < S->Monster_Size; k++)
			{
				int m_x = S->Monster_list[k]->Get_X();
				int m_y = S->Monster_list[k]->Get_Y();

				if (m_x != n_x || m_y != n_y) continue;

				S->Monster_list.erase(S->Monster_list.begin() + k);
				S->Monster_Size--;
				break;
			}
		}
		else if (S->Map[n_y][n_x] == T_breakable_wall || S->Map[n_y][n_x] == T_bomb_item) S->Map[n_y][n_x] = T_empty;
		else if (S->Map[n_y][n_x] == T_boss)
		{
			boss->Set_HP(boss->Get_HP() - 1);
			if (boss->Get_HP() == 0) Update().Win();
			S->Current_Boss_HP--;
		}
	}
}

void Bomb::Player_Bomb_Cnt()
{
	Singleton *S = &Singleton::getSingleton();

	int Cnt;

	for (int i = 0; i < S->Player_Bomb_Size; i++)
	{
		S->Player_Bomb_list[i]->Get_Cnt() < 0 ? Cnt = 0 : Cnt = S->Player_Bomb_list[i]->Get_Cnt();
		S->Player_Bomb_list[i]->Set_Cnt(++Cnt);
		if (S->Player_Bomb_list[i]->Get_Cnt() == Bomb_delay)
		{
			Player_Bomb_Attack(i);
			S->Player_Bomb_list.erase(S->Player_Bomb_list.begin() + i);
			S->Player_Bomb_Size--;
			break;
		}
	}
}

void Bomb::Boss_Bomb_Attack()
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { -1,1,0,0 };
	int idy[4] = { 0,0,-1,1 };
	int x = S->Boss_Bomb->Get_X();
	int y = S->Boss_Bomb->Get_Y();

	S->Map[y][x] = 0;

	for (int j = 0; j < 4; j++)
	{
		int n_y = y + idy[j];
		int n_x = x + idx[j];

		if (S->Map[n_y][n_x] == T_player)
		{
			S->End_Flag = true;
			Update().Output();
			printf("Game Over!");
			return;
		}
		else if (S->Map[n_y][n_x] == T_breakable_wall || S->Map[n_y][n_x] == T_bomb_item) S->Map[n_y][n_x] = T_empty;
	}
}

void Bomb::Boss_Bomb_Cnt()
{
	Singleton *S = &Singleton::getSingleton();

	S->Boss_Bomb->Get_Cnt() < 0 ? S->Boss_Bomb->Set_Cnt(0) : S->Boss_Bomb->Set_Cnt(S->Boss_Bomb->Get_Cnt() + 1);

	if (S->Boss_Bomb->Get_Cnt() == Bomb_delay)
	{
		Boss_Bomb_Attack();
		S->Boss_Bomb = 0;
		S->Boss_Bomb_Size--;
	}
}

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

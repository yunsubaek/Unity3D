#include "Bomb.h"
#include "Update.h"
#include "Singleton.h"

void Bomb::Bomb_Attack(int i)
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { -1,1,0,0 };
	int idy[4] = { 0,0,-1,1 };
	int x = S->Bomb_list[i]->Get_X();
	int y = S->Bomb_list[i]->Get_Y();

	S->Map[y][x] = 0;

	for (int j = 0; j < 4; j++)
	{
		if (S->Bomb_Size == 0)break;
		int n_y = y + idx[j];
		int n_x = x + idy[j];
		if (S->Map[n_y][n_x] == T_player)
		{
			S->End_Flag = true;
			Update().Output();
			printf("Game Over!");
			system("PAUSE");
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
		else if (S->Map[n_y][n_x] == T_breakable_wall) S->Map[n_y][n_x] = T_empty;
	}
}

void Bomb::Bomb_Cnt()
{
	Singleton *S = &Singleton::getSingleton();
	int Cnt;
	for (int i = 0; i < S->Bomb_Size; i++)
	{
		S->Bomb_list[i]->Get_Cnt() < 0 ? Cnt = 0 : Cnt = S->Bomb_list[i]->Get_Cnt();
		S->Bomb_list[i]->Set_Cnt(++Cnt);
		if (S->Bomb_list[i]->Get_Cnt() == Bomb_delay)
		{
			Bomb_Attack(i);
			S->Bomb_list.erase(S->Bomb_list.begin() + i);
			S->Bomb_Size--;
			break;
		}
	}
}

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

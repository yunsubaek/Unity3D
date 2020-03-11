#include "Monster.h"
#include "Update.h"
#include "Singleton.h"
#include "Bomb.h"
#include <time.h>
#include <iostream>

void Monster::Monster_Add_Bomb(Object *monster)
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int idx[4] = { 0,-1,0,1 };
	int idy[4] = { -1,0,1,0 };

	int j = (rand() + t) % 4;

	Bomb *bomb = new Bomb();

	int n_x = idx[j] + monster->Get_X();
	int n_y = idy[j] + monster->Get_Y();

	if (S->Map[n_y][n_x] == T_empty || S->Map[n_y][n_x] == T_bomb_item)
	{
		S->Map[n_y][n_x] = T_bomb, bomb->Set_X(n_x), bomb->Set_Y(n_y);
		monster->Monster_Bomb = bomb;
	}
	else Monster_Add_Bomb(monster);
}

void Monster::Monster_Init()
{
	for (int i = 0; i < Init_Monster_Cnt; i++)	Monster_Add();
}

void Monster::Monster_Add()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int rand_x = (rand() + t) % (Map_Width - 2);
	int rand_y = (rand() + t) % (Map_Height - 2);

	if (rand_x == 1 && rand_y == 1) return;
	if (S->Map[rand_y][rand_x] == T_empty)
	{
		Monster *monster = new Monster();
		monster->Frame_Cnt = 0;
		monster->Pos_x = rand_x;
		monster->Pos_y = rand_y;
		monster->Have_Bomb = false;

		S->Monster_Size++;
		S->Monster_list.push_back(monster);
		S->Map[rand_y][rand_x] = T_monster;
	}
	else Monster_Add();
}

void Monster::Monster_Attack()
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { 1,-1,0,0 };
	int idy[4] = { 0,0,1,-1 };

	for (int i = 0; i < S->Monster_Size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int new_x = idx[j] + S->Monster_list[i]->Get_X();
			int new_y = idy[j] + S->Monster_list[i]->Get_Y();
			if (S->Map[new_y][new_x] == T_player)
			{
				S->End_Flag = true;
				Update().Output();
				printf("Game Over!");
				return;
			}
		}
	}
}

void Monster::Monster_Move()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	for (int i = 0; i < S->Monster_Size; i++)
	{
		int random = (rand() + t) % 4;

		int x = S->Monster_list[i]->Get_X();
		int y = S->Monster_list[i]->Get_Y();

		S->Map[y][x] = T_empty;

		if (random == D_up)
		{
			if (S->Map[y - 1][x] == T_empty) y -= 1;
			else if (S->Map[y - 1][x] == T_bomb_item) y -= 1, S->Monster_list[i]->Have_Bomb = true;
		}
		else if (random == D_left)
		{
			if (S->Map[y][x - 1] == T_empty) x -= 1;
			else if (S->Map[y][x - 1] == T_bomb_item) x -= 1, S->Monster_list[i]->Have_Bomb = true;
		}
		else if (random == D_down)
		{
			if (S->Map[y + 1][x] == T_empty) y += 1;
			else if (S->Map[y + 1][x] == T_bomb_item) y += 1, S->Monster_list[i]->Have_Bomb = true;
		}
		else if (random == D_right)
		{
			if (S->Map[y][x + 1] == T_empty) x += 1;
			else if (S->Map[y][x + 1] == T_bomb_item) x += 1, S->Monster_list[i]->Have_Bomb = true;
		}

		S->Monster_list[i]->Set_X(x);
		S->Monster_list[i]->Set_Y(y);
		S->Map[y][x] = T_monster;
		if (S->Monster_list[i]->Have_Bomb)
		{
			if (S->Monster_list[i]->Get_Cnt() == 0) Monster_Add_Bomb(S->Monster_list[i]);
			else if (S->Monster_list[i]->Get_Cnt() >= Bomb_delay) Monster_Bomb_Attack(S->Monster_list[i]);
			S->Monster_list[i]->Set_Cnt(S->Monster_list[i]->Get_Cnt() + 1);
		}
	}
}

void Monster::Monster_Bomb_Attack(Object *monster)
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { -1,1,0,0 };
	int idy[4] = { 0,0,-1,1 };
	int x = monster->Monster_Bomb->Get_X();
	int y = monster->Monster_Bomb->Get_Y();

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
	monster->Set_Cnt(-1);
	monster->Monster_Bomb = 0;
	S->Map[y][x] = 0;
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
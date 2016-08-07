#include "Monster.h"
#include "Update.h"
#include "Singleton.h"
#include <time.h>
#include <iostream>

void Monster::Monster_Init()
{
	for (int i = 0; i < Init_Monster_Cnt; i++)
	{
		Monster_Add();
	}
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

		S->Monster_Size++;
		S->Monster_list.push_back(monster);
		S->Map[rand_y][rand_x] = T_monster;
	}
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
				system("PAUSE");
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
		int rand_x = (rand() + t);
		int rand_y = (rand() + t);
		
		int x = S->Monster_list[i]->Get_X();
		int y = S->Monster_list[i]->Get_Y();

		S->Map[y][x] = T_empty;

		if ((rand_x % 2 == 1) && (rand_y % 2 == 1) && (S->Map[y][x - 1] == T_empty))		x -= 1;
		else if ((rand_x % 2 == 1) && (rand_y % 2 == 0) && (S->Map[y - 1][x] == T_empty))	y -= 1;
		else if ((rand_x % 2 == 0) && (rand_y % 2 == 1) && (S->Map[y + 1][x] == T_empty))	y += 1;
		else if ((rand_x % 2 == 0) && (rand_y % 2 == 0) && (S->Map[y][x + 1] == T_empty))	x += 1;

		S->Monster_list[i]->Set_X(x);
		S->Monster_list[i]->Set_Y(y);
		S->Map[y][x] = T_monster;
	}
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
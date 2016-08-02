#include "Monster.h"
#include "Update.h"
#include "Singleton.h"
#include <time.h>
#include <iostream>

void Monster::Monster_Init()
{
	time_t t;
	time(&t);

	Monster *monster = new Monster();

	int rand_x = (rand() + t) % 27;
	int rand_y = (rand() + t) % 17;

	if (rand_x == 1 && rand_y == 1)return;
	if (Singleton::getInstance()->Map[rand_y][rand_x] == 0)
	{
		Singleton::getInstance()->Monster_Size++;
		monster->Frame_Cnt = 0;
		monster->Pos_x = rand_x;
		monster->Pos_y = rand_y;

		Singleton::getInstance()->Monster_list.push_back(monster);
		Singleton::getInstance()->Map[rand_y][rand_x] = 3;
	}
}

void Monster::Monster_Attack(vector<Object*> *Monster_list)
{
	int idx[4] = { 1,-1,0,0 };
	int idy[4] = { 0,0,1,-1 };

	for (int i = 0; i < Singleton::getInstance()->Monster_Size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//몬스터와 사용자가 옆자리 -> 종료
			if (Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y + idx[j]][(*Monster_list)[i]->Pos_x + idy[j]] == 2)
			{
				Update().Output();
				printf("Game Over!");
				system("PAUSE");
				Singleton::getInstance()->End_Flag = true;
				return;
			}
		}
	}
}

void Monster::Monster_Move(vector<Object*> *Monster_list)
{
	time_t t;
	time(&t);

	for (int i = 0; i < Singleton::getInstance()->Monster_Size; i++) 
	{
		int rand_x = (rand() + t);
		int rand_y = (rand() + t);

		if ((rand_x % 2 == 1) && (rand_y % 2 == 1) && (Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x - 1] == 0))
		{
			Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x] = 0;
			(*Monster_list)[i]->Pos_x -= 1;
		}
		else if ((rand_x % 2 == 1) && (rand_y % 2 == 0) && (Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y - 1][(*Monster_list)[i]->Pos_x] == 0))
		{
			Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x] = 0;
			(*Monster_list)[i]->Pos_y -= 1;
		}
		else if ((rand_x % 2 == 0) && (rand_y % 2 == 1) && (Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y + 1][(*Monster_list)[i]->Pos_x] == 0))
		{
			Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x] = 0;
			(*Monster_list)[i]->Pos_y += 1;
		}
		else if ((rand_x % 2 == 0) && (rand_y % 2 == 0) && (Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x + 1] == 0))
		{
			Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x] = 0;
			(*Monster_list)[i]->Pos_x += 1;
		}
		Singleton::getInstance()->Map[(*Monster_list)[i]->Pos_y][(*Monster_list)[i]->Pos_x] = 3;
	}
}

Monster::Monster()
{
}

Monster::~Monster()
{
}

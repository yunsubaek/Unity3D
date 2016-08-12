#include "Singleton.h"
#include "Declareh.h"
#include "Breakable_Wall.h"
#include "UnBreakable_Wall.h"
#include "Item.h"
#include "Monster.h"
#include "Boss.h"
#include <time.h>

void Singleton::Start_Map()
{
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			UnBreakable_Wall *wall = new UnBreakable_Wall(i, j);

			if (i == 0 || i == Map_Height - 1)		obj_list.push_back(wall);
			else if (j == 0 || j == Map_Width - 1)	obj_list.push_back(wall);
			else if (i % 2 == 0 && j % 2 == 0)		obj_list.push_back(wall);
		}
	}

	for (int i = 0; i < Init_Breakable_Wall_Cnt; i++)
	{
		Breakable_Wall *b_wall = new Breakable_Wall(Rand_X(), Rand_Y());
		obj_list.push_back(b_wall);
	}

	for (int i = 0; i < Init_Monster_Cnt; i++)
	{
		Monster *monster = new Monster(Rand_X(), Rand_Y());
		obj_list.push_back(monster);
	}

	for (int i = 0; i < Init_Item_Cnt; i++)
	{
		Item *item = new Item(Rand_X(), Rand_Y());
		obj_list.push_back(item);
	}

	Boss *boss = new Boss(Boss_X, Boss_Y);
	obj_list.push_back(boss);
}

void Singleton::Print(Object player)
{
	system("cls");
	printf("Player Cnt	= %d\n", player.Get_Frame_Cnt());
	printf("Boss HP		= %d\n", Boss_Current_HP);
	printf("Bomb		= %d/%d\n", Current_Place_bomb, Able_to_place_bomb);
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			int temp = Search(i, j);
			if (temp != -1)
			{
				printf("%s", obj_list[temp]->Get_Shape());
			}
			else printf("%s", SPACE);
		}
		printf("\n");
	}
}

void Singleton::Delete(int i)
{
	obj_list.erase(obj_list.begin() + i);
}

void Singleton::Update()
{
	for (int i = 0; i < obj_list.size(); i++) obj_list[i]->Update();
}

int Singleton::Rand_X()
{
	time_t t;
	time(&t);

	return (rand() + t) % Map_Width;
}

int Singleton::Rand_Y()
{
	time_t t;
	time(&t);

	return (rand() + t) % Map_Height;
}

int Singleton::Rand_Dir()
{
	time_t t;
	time(&t);

	return (rand() + t) % 4;
}

int Singleton::Search(int x, int y)
{
	for (int i = 0; i < obj_list.size(); i++)
	{
		if (obj_list[i]->Get_X() != x || obj_list[i]->Get_Y() != y)continue;
		return i;
	}
	return -1;
}

void Singleton::Win()
{
	End_Flag = true;
	system("cls");
	printf("                                                                    \n");
	printf("                                                                    \n");
	printf("                                                                    \n");
	printf("   0     0    000000    0      0      0       0   00000   0     0   \n");
	printf("    0   0    0      0   0      0      0       0     0     00    0   \n");
	printf("     0 0     0      0   0      0      0   0   0     0     0 0   0   \n");
	printf("      0      0      0   0      0      0   0   0     0     0  0  0   \n");
	printf("      0      0      0   0      0      0   0   0     0     0   0 0   \n");
	printf("      0      0      0   0      0       0 0 0 0      0     0    00   \n");
	printf("      0       000000     000000         0   0     00000   0     0   \n");
	printf("                                                                    \n");
	printf("                                                                    \n");
	printf("                                                                    \n");
	system("PAUSE");
}

void Singleton::Lose()
{
	End_Flag = true;
	system("cls");
	printf("                                                                           \n");
	printf("                                                                           \n");
	printf("                                                                           \n");
	printf("   0     0    00000    0     0      0         00000     00000    0000000   \n");
	printf("    0   0    0     0   0     0      0        0     0   0         0         \n");
	printf("     0 0     0     0   0     0      0        0     0   0         0         \n");
	printf("      0      0     0   0     0      0        0     0    000000   0000000   \n");
	printf("      0      0     0   0     0      0        0     0         0   0         \n");
	printf("      0      0     0   0     0      0        0     0         0   0         \n");
	printf("      0       00000     00000       000000    00000     00000    0000000   \n");
	printf("                                                                           \n");
	printf("                                                                           \n");
	printf("                                                                           \n");
	system("PAUSE");
}

Singleton & Singleton::getSingleton()
{
	static Singleton instance;
	return instance;
}

Player* Singleton::Make_Player()
{
	Player *player = new Player(Start_X, Start_Y);
	Current_Place_bomb = 0;
	obj_list.push_back(player);
	return player;
}
#pragma warning(disable:4996)
#include "Update.h"
#include "Player.h"
#include "Singleton.h"
#include <iostream>

void Update::State()
{
	char state[20];

	printf("게임을 시작하려면 'Start'를 입력 후 엔터를 누르세요.\n");
	while (scanf("%s", &state))
	{
		system("cls");
		if (!strcmp(state, "Start"))
		{
			printf("Start Game!\n");
			break;
		}
		else printf("게임을 시작하려면 'Start'를 입력 후 엔터를 누르세요.\n");
	}
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			if ((i == j) && (j == 1))							 printf("▽");
			else if (Singleton::getInstance()->Map[i][j] == 1)   printf("■");
			else if (Singleton::getInstance()->Map[i][j] == 3)   printf("○");
			else if (Singleton::getInstance()->Map[i][j] == 4)   printf("◇");
			else if (Singleton::getInstance()->Map[i][j] == 5)   printf("□");
			else												 printf("　");
		}
		printf("\n");
	}
}

void Update::Output()
{
	system("cls");
	//프레임 카운트
	printf("Player Frame : %d\t\tPlayer Position : (%d,%d)\n", Singleton::getInstance()->player->Frame_Cnt, Singleton::getInstance()->player->Pos_y - 1, Singleton::getInstance()->player->Pos_x - 1);
	printf("Monster : %d\t\t\tBomb : %d\n", Singleton::getInstance()->Monster_Size, Singleton::getInstance()->Bomb_Size);
	//몬스터는 갯수만큼 프레임 카운트
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			//파괴 불가능한 벽
			if (Singleton::getInstance()->Map[i][j] == 1)           printf("■");
			//사용자 위치를 찍음
			else if (Singleton::getInstance()->Map[i][j] == 2)
			{
				if (Singleton::getInstance()->Look_Dir == 1)        Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("△") : printf("▲");
				else if (Singleton::getInstance()->Look_Dir == 2)   Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("◁") : printf("◀");
				else if (Singleton::getInstance()->Look_Dir == 3)   Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("▽") : printf("▼");
				else if (Singleton::getInstance()->Look_Dir == 4)   Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("▷") : printf("▶");
			}
			else if (Singleton::getInstance()->Map[i][j] == 3)      Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("○") : printf("●");
			else if (Singleton::getInstance()->Map[i][j] == 4)      Singleton::getInstance()->player->Frame_Cnt % 2 == 0 ? printf("◇") : printf("◆");
			else if (Singleton::getInstance()->Map[i][j] == 5)      printf("□");
			else													printf("　");
		}
		printf("\n");
	}
	printf("\n");
}

Update::Update()
{
}

Update::~Update()
{
}

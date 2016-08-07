#pragma warning(disable:4996)
#include "Update.h"

void Update::State()
{
	Singleton *S = &Singleton::getSingleton();
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
			if ((i == j) && (j == 1))						printf("▽");
			else if (S->Map[i][j] == T_unbreakable_wall)	printf("■");
			else if (S->Map[i][j] == T_monster)				printf("○");
			else if (S->Map[i][j] == T_bomb)				printf("◇");
			else if (S->Map[i][j] == T_breakable_wall)		printf("□");
			else											printf("　");
		}
		printf("\n");
	}
}

void Update::Output()
{
	Singleton *S = &Singleton::getSingleton();
	int Frame_Cnt = player->Get_Cnt();
	int Look_Dir = player->Look_Dir;
	system("cls");
	if (!S->End_Flag)
	{
		printf("Player Frame : %d\t\tPlayer Position : (%d,%d)\n", player->Get_Cnt(), player->Get_Y() - 1, player->Get_X() - 1);
		printf("Monster : %d\t\t\tBomb : %d\n", S->Monster_Size, S->Bomb_Size);
	}
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			if (S->Map[i][j] == T_unbreakable_wall)			printf("■");
			else if (S->Map[i][j] == T_player)
			{
				if (Look_Dir == D_up)						Frame_Cnt % 2 == 0 ? printf("△") : printf("▲");
				else if (Look_Dir == D_left)				Frame_Cnt % 2 == 0 ? printf("◁") : printf("◀");
				else if (Look_Dir == D_down)				Frame_Cnt % 2 == 0 ? printf("▽") : printf("▼");
				else if (Look_Dir == D_right)				Frame_Cnt % 2 == 0 ? printf("▷") : printf("▶");
			}	
			else if (S->Map[i][j] == T_monster)				Frame_Cnt % 2 == 0 ? printf("○") : printf("●");
			else if (S->Map[i][j] == T_bomb)				Frame_Cnt % 2 == 0 ? printf("◇") : printf("◆");
			else if (S->Map[i][j] == T_breakable_wall)		printf("□");
			else											printf("　");
		}
		printf("\n");
	}
	printf("\n");
}

void Update::Win()
{
	Singleton::getSingleton().End_Flag = true;
	system("cls");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("**0*******0***00000****0*****0***\n");
	printf("**0*******0*****0******00****0***\n");
	printf("**0***0***0*****0******0*0***0***\n");
	printf("**0***0***0*****0******0**0**0***\n");
	printf("**0***0***0*****0******0***0*0***\n");
	printf("***0*0*0*0******0******0****00***\n");
	printf("****0***0*****00000****0*****0***\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*********************************\n");
	system("PAUSE");
}

Update::Update()
{
}

Update::~Update()
{
}

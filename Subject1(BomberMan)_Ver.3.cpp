//빈 공간에만 추가되도록 설정
//0:빈공간,1:파괴불가능벽,2:사용자,3:몬스터,4:폭탄,5:파괴가능벽
#pragma warning(disable:4996)
#include<iostream>
#include<time.h>
#include<conio.h>
#include<vector>
#include<list>
#include"Object.h"
using namespace std;

#pragma region Declare
void Output();

const int Map_Height = 19;
const int Map_Weight = 29;

class Monster;
class Bomb;

static vector<Monster>		Monster_list;
static vector<Bomb>			Bomb_list;

char state[20];
char Move_Dir;

int Look_Dir;
int idx[4]						= { 1,-1,0,0 };
int idy[4]						= { 0,0,1,-1 };
int Map[Map_Height][Map_Weight] = { 0 };
int Monster_Size				= Monster_list.size();
int Bomb_Size					= Bomb_list.size();

bool End_Flag = false;
#pragma endregion

class Object
{
public:
	int Pos_x;
	int Pos_y;
	int Frame_Cnt;
};
class Monster :public Object
{
public:
	void Monster_Init(time_t t)
	{
		Monster monster;
		int rand_x = (rand() + t) % 27;
		int rand_y = (rand() + t) % 17;
		if (rand_x == 1 && rand_y == 1)return;
		if (Map[rand_y][rand_x] == 0)
		{
			Monster_Size++;
			monster.Pos_x = rand_x;
			monster.Pos_y = rand_y;
			Monster_list.push_back(monster);
			Map[rand_y][rand_x] = 3;
		}
	}
	void Monster_Attack()
	{
		for (int i = 0; i < Monster_Size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//몬스터와 사용자가 옆자리 -> 종료
				if (Map[Monster_list[i].Pos_y + idx[j]][Monster_list[i].Pos_x + idy[j]] == 2)
				{
					Output();
					printf("Game Over!");
					system("PAUSE");
					End_Flag = true;
					return;
				}
			}
		}
	}
	void Monster_Move(time_t t)
	{
		for (int i = 0; i < Monster_Size; i++) {
			int rand_x = (rand() + t);
			int rand_y = (rand() + t);
			if ((rand_x % 2 == 1) && (rand_y % 2 == 1) && (Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x - 1] == 0))
			{
				Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] = 0;
				Monster_list[i].Pos_x -= 1;
			}
			else if ((rand_x % 2 == 1) && (rand_y % 2 == 0) && (Map[Monster_list[i].Pos_y - 1][Monster_list[i].Pos_x] == 0))
			{
				Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] = 0;
				Monster_list[i].Pos_y -= 1;
			}
			else if ((rand_x % 2 == 0) && (rand_y % 2 == 1) && (Map[Monster_list[i].Pos_y + 1][Monster_list[i].Pos_x] == 0))
			{
				Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] = 0;
				Monster_list[i].Pos_y += 1;
			}
			else if ((rand_x % 2 == 0) && (rand_y % 2 == 0) && (Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x + 1] == 0))
			{
				Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] = 0;
				Monster_list[i].Pos_x += 1;
			}
			Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] = 3;
		}
	}
};
class Bomb :public Object
{
public:
	void Bomb_Attack(int i)
	{
		Map[Bomb_list[i].Pos_y][Bomb_list[i].Pos_x] = 0;
		for (int j = 0; j < 4; j++)
		{
			if (Bomb_Size == 0)break;
			int new_y = Bomb_list[i].Pos_y + idx[j];
			int new_x = Bomb_list[i].Pos_x + idy[j];
			if (Map[new_y][new_x] == 2)
			{
				Output();
				printf("Game Over!");
				system("PAUSE");
				End_Flag = true;
				return;
			}
			else if (Map[new_y][new_x] == 3)
			{
				Map[new_y][new_x] = 0;
				for (int k = 0; k < Monster_Size; k++)
				{
					if (Monster_list[k].Pos_x != new_x || Monster_list[k].Pos_y != new_y) continue;
					Monster_list.erase(Monster_list.begin() + k);
					Monster_Size--;
					break;
				}
			}
			else if (Map[new_y][new_x] == 5) Map[new_y][new_x] = 0;
		}
	}
	void Bomb_Cnt()
	{
		for (int i = 0; i < Bomb_Size; i++)
		{
			Bomb_list[i].Frame_Cnt++;
			if (Bomb_list[i].Frame_Cnt == 5)
			{
				Bomb_Attack(i);
				Bomb_list.erase(Bomb_list.begin() + i);
				Bomb_Size--;
				break;
			}
		}
	}
};
class Player :public Object
{
public:
	Player Player_Move(Player player, char move_dir)
	{
		if ((Move_Dir == 'W') || (Move_Dir == 'w'))
		{
			if (Look_Dir == 1 && Map[player.Pos_y - 2][player.Pos_x - 1] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_y--;
			}
			else Look_Dir = 1;
		}
		else if ((Move_Dir == 'A') || (Move_Dir == 'a'))
		{
			if (Look_Dir == 2 && Map[player.Pos_y - 1][player.Pos_x - 2] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_x--;
			}
			else Look_Dir = 2;
		}
		else if ((Move_Dir == 'S') || (Move_Dir == 's'))
		{
			if (Look_Dir == 3 && Map[player.Pos_y][player.Pos_x - 1] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_y++;
			}
			else Look_Dir = 3;
		}
		else if ((Move_Dir == 'D') || (Move_Dir == 'd'))
		{
			if (Look_Dir == 4 && Map[player.Pos_y - 1][player.Pos_x] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_x++;
			}
			else Look_Dir = 4;
		}
		else if (Move_Dir == '1')
		{
			Bomb bomb;
			bomb.Frame_Cnt = -1;
			//바라보는 방향의 정보
			if (Look_Dir == 1 && Map[player.Pos_y - 2][player.Pos_x - 1] == 0)
				Map[player.Pos_y - 2][player.Pos_x - 1] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 1, bomb.Pos_y = player.Pos_y - 2;
			else if (Look_Dir == 2 && Map[player.Pos_y - 1][player.Pos_x - 2] == 0)
				Map[player.Pos_y - 1][player.Pos_x - 2] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 2, bomb.Pos_y = player.Pos_y - 1;
			else if (Look_Dir == 3 && Map[player.Pos_y][player.Pos_x - 1] == 0)
				Map[player.Pos_y][player.Pos_x - 1] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 1, bomb.Pos_y = player.Pos_y;
			else if (Look_Dir == 4 && Map[player.Pos_y - 1][player.Pos_x] == 0)
				Map[player.Pos_y - 1][player.Pos_x] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x, bomb.Pos_y = player.Pos_y - 1;
			//바라보는 방향에 폭탄이 없으면 설치
			if (bomb.Frame_Cnt != -1)
			{
				Bomb_Size++;
				Bomb_list.push_back(bomb);
			}
		}
		//프레임만 증가
		else if (Move_Dir == '2');
		else printf("잘못된 키 입력입니다.");
		//사용자 위치 초기화
		Map[player.Pos_y - 1][player.Pos_x - 1] = 2;
		return player;
	}
};

Player				player;
Monster				monster;
Bomb				bomb;

void Map_Init()
{
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Weight; j++)
		{
			//맨 윗줄, 맨 아랫줄의 경우 1
			if (i == 0 || i == Map_Height - 1)
			{
				Map[i][j] = 1;
			}
			//맨 왼쪽, 맨 오른쪽의 경우 1
			else if (j == 0 || j == Map_Weight - 1)
			{
				Map[i][j] = 1;
			}
			//나머지 경우
			else
			{
				if (i % 2 == 0 && j % 2 == 0)
				{
					Map[i][j] = 1;
				}
			}
		}
	}
}
void Breakable_Wall_Init(time_t t)
{
	for (int i = 0; i < 20; i++)
	{
		int rand_x = (rand() + t) % 27;
		int rand_y = (rand() + t) % 17;
		if (rand_x == 1 && rand_y == 1)continue;
		if (Map[rand_y][rand_x] == 0)
		{
			Map[rand_y][rand_x] = 5;
		}
	}
}
void State()
{
	printf("게임을 시작하려면 'Start'를 입력 후 엔터를 누르세요.\n");
	while (scanf("%s", &state))
	{
		system("cls");
		printf("게임을 시작하려면 'Start'를 입력 후 엔터를 누르세요.\n");
		if (!strcmp(state, "Start"))
		{
			printf("Start Game!\n");
			break;
		}
	}
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Weight; j++)
		{
			if ((i == j) && (j == 1))  printf("▽");
			else if (Map[i][j] == 1)   printf("■");
			else if (Map[i][j] == 3)   printf("○");
			else if (Map[i][j] == 4)   printf("◇");
			else if (Map[i][j] == 5)   printf("□");
			else					   printf("　");
		}
		printf("\n");
	}
}
void Output()
{
	system("cls");
	//프레임 카운트
	printf("player.Frame_Cnt : %d\t\tPlayer Position : (%d,%d)\n", player.Frame_Cnt, player.Pos_y - 1, player.Pos_x - 1);
	printf("Monster : %d\t\t\tBomb : %d\n", Monster_Size, Bomb_Size);
	//몬스터는 갯수만큼 프레임 카운트
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Weight; j++)
		{
			//파괴 불가능한 벽
			if (Map[i][j] == 1)           printf("■");
			//사용자 위치를 찍음
			else if (Map[i][j] == 2)
			{
				if (Look_Dir == 1)        player.Frame_Cnt % 2 == 0 ? printf("△") : printf("▲");
				else if (Look_Dir == 2)   player.Frame_Cnt % 2 == 0 ? printf("◁") : printf("◀");
				else if (Look_Dir == 3)   player.Frame_Cnt % 2 == 0 ? printf("▽") : printf("▼");
				else if (Look_Dir == 4)   player.Frame_Cnt % 2 == 0 ? printf("▷") : printf("▶");
			}
			else if (Map[i][j] == 3)      player.Frame_Cnt % 2 == 0 ? printf("○") : printf("●");
			else if (Map[i][j] == 4)      player.Frame_Cnt % 2 == 0 ? printf("◇") : printf("◆");
			else if (Map[i][j] == 5)      printf("□");
			else						  printf("　");
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	time_t t;
	time(&t);

	player.Pos_x = 2;		player.Pos_y = 2;		player.Frame_Cnt = 0;
	
	Map_Init();
	for(int i = 0 ; i < 10;i++)	monster.Monster_Init(t);
	Breakable_Wall_Init(t);
	State();

	while (Move_Dir = _getch())
	{
		player.Frame_Cnt++;
		//20초마다 몬스터 추가
		if (player.Frame_Cnt % 20 == 0)	monster.Monster_Init(t);
		//사용자
		player = player.Player_Move(player, Move_Dir);
		//몬스터
		monster.Monster_Move(t);
		monster.Monster_Attack();
		//폭탄
		bomb.Bomb_Cnt();
		//종료 확인
		if (End_Flag)return 0;
		//출력
		Output();
	}
	return 0;
}

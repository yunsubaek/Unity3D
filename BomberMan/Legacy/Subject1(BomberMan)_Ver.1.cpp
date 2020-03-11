//���� 10�� ���� ���� ���� �� ���� vector�� ����.������ �� 20�� ���� ���� ����, ��ź��ġ
//�� �������� �߰��ǵ��� ����,������ ����
//space.erase(space.begin() + num);�� ���� ���� �ִ�.
//0:�����,1:�ı��Ұ��ɺ�,2:�����,3:����,4:��ź,5:�ı����ɺ�
#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<time.h>
#include<conio.h>
#include<vector>
#include<list>
#define Map_Height 19
#define Map_Weight 29

using namespace std;

class Object
{
public:
	int Pos_x;
	int Pos_y;
};
class Player :public Object
{
public:
	int Cnt;
};
class Monster :public Object
{
public:
	bool Alive;
};
class Bomb :public Object
{
public:
	int Frame_Cnt;
};

vector<Monster>		Monster_list;
vector<Bomb>		Bomb_list;
Player				player;

char state[20];
char KeyBoard_Input;
int Look_Dir;
int idx[4] = { 1,-1,0,0 };
int idy[4] = { 0,0,1,-1 };
int Map[Map_Height][Map_Weight] = { 0 };
int Monster_Size = Monster_list.size();
int Bomb_Size = Bomb_list.size();

void Map_Init()
{
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Weight; j++)
		{
			//�� ����, �� �Ʒ����� ��� 1
			if (i == 0 || i == Map_Height - 1)
			{
				Map[i][j] = 1;
			}
			//�� ����, �� �������� ��� 1
			else if (j == 0 || j == Map_Weight - 1)
			{
				Map[i][j] = 1;
			}
			//������ ���
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
void Monster_Init(time_t t)
{
	Monster monster;
	int rand_x = (rand() + t) % 27;
	int rand_y = (rand() + t) % 17;
	if (rand_x == 1 && rand_y == 1)return;
	if (Map[rand_y][rand_x] == 0)
	{
		Monster_Size++;
		monster.Alive = 1;
		monster.Pos_x = rand_x;
		monster.Pos_y = rand_y;
		Monster_list.push_back(monster);
		Map[rand_y][rand_x] = 3;
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
	printf("������ �����Ϸ��� 'Start'�� �Է� �� ���͸� ��������.\n");
	while (scanf("%s", &state))
	{
		system("cls");
		printf("������ �����Ϸ��� 'Start'�� �Է� �� ���͸� ��������.\n");
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
			if ((i == j) && (j == 1))  printf("��");
			else if (Map[i][j] == 1)   printf("��");
			else if (Map[i][j] == 3)   printf("��");
			else if (Map[i][j] == 4)   printf("��");
			else if (Map[i][j] == 5)   printf("��");
			else                  printf("��");
		}
		printf("\n");
	}
}
void Output()
{
	system("cls");
	//������ ī��Ʈ
	printf("player.Cnt : %d\n", player.Cnt);
	printf("Player Position : (%d,%d)\n", player.Pos_y - 1, player.Pos_x - 1);
	//���ʹ� ������ŭ ������ ī��Ʈ
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Weight; j++)
		{
			//�ı� �Ұ����� ��
			if (Map[i][j] == 1)           printf("��");
			//����� ��ġ�� ����
			else if (Map[i][j] == 2)
			{
				if (Look_Dir == 1)        player.Cnt % 2 == 0 ? printf("��") : printf("��");
				else if (Look_Dir == 2)   player.Cnt % 2 == 0 ? printf("��") : printf("��");
				else if (Look_Dir == 3)   player.Cnt % 2 == 0 ? printf("��") : printf("��");
				else if (Look_Dir == 4)   player.Cnt % 2 == 0 ? printf("��") : printf("��");
			}
			else if (Map[i][j] == 3)      player.Cnt % 2 == 0 ? printf("��") : printf("��");
			else if (Map[i][j] == 4)      player.Cnt % 2 == 0 ? printf("��") : printf("��");
			else if (Map[i][j] == 5)      printf("��");
			else						  printf("��");
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	time_t t;
	time(&t);

	player.Pos_x = 2;		player.Pos_y = 2;		player.Cnt = 0;

	Map_Init();
	for (int i = 0; i < 10; i++)	Monster_Init(t);
	Breakable_Wall_Init(t);
	State();

	while (KeyBoard_Input = _getch())
	{
		player.Cnt++;
		//20�ʸ��� ���� �߰�
		if (player.Cnt % 20 == 0)	Monster_Init(t);
#pragma region ����� �Է�
		if ((KeyBoard_Input == 'W') || (KeyBoard_Input == 'w'))
		{
			if (Look_Dir == 1 && Map[player.Pos_y - 2][player.Pos_x - 1] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_y--;
			}
			else Look_Dir = 1;
		}
		else if ((KeyBoard_Input == 'A') || (KeyBoard_Input == 'a'))
		{
			if (Look_Dir == 2 && Map[player.Pos_y - 1][player.Pos_x - 2] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_x--;
			}
			else Look_Dir = 2;
		}
		else if ((KeyBoard_Input == 'S') || (KeyBoard_Input == 's'))
		{
			if (Look_Dir == 3 && Map[player.Pos_y][player.Pos_x - 1] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_y++;
			}
			else Look_Dir = 3;
		}
		else if ((KeyBoard_Input == 'D') || (KeyBoard_Input == 'd'))
		{
			if (Look_Dir == 4 && Map[player.Pos_y - 1][player.Pos_x] == 0)
			{
				Map[player.Pos_y - 1][player.Pos_x - 1] = 0;
				player.Pos_x++;
			}
			else Look_Dir = 4;
		}
		else if (KeyBoard_Input == '1')
		{
			Bomb bomb;
			bomb.Frame_Cnt = -1;
			//�ٶ󺸴� ������ ����
			if (Look_Dir == 1 && Map[player.Pos_y - 2][player.Pos_x - 1] == 0)
				Map[player.Pos_y - 2][player.Pos_x - 1] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 1, bomb.Pos_y = player.Pos_y - 2;
			else if (Look_Dir == 2 && Map[player.Pos_y - 1][player.Pos_x - 2] == 0)
				Map[player.Pos_y - 1][player.Pos_x - 2] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 2, bomb.Pos_y = player.Pos_y - 1;
			else if (Look_Dir == 3 && Map[player.Pos_y][player.Pos_x - 1] == 0)
				Map[player.Pos_y][player.Pos_x - 1] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x - 1, bomb.Pos_y = player.Pos_y;
			else if (Look_Dir == 4 && Map[player.Pos_y - 1][player.Pos_x] == 0)
				Map[player.Pos_y - 1][player.Pos_x] = 4, bomb.Frame_Cnt = 0, bomb.Pos_x = player.Pos_x, bomb.Pos_y = player.Pos_y - 1;
			//�ٶ󺸴� ���⿡ ��ź�� ������ ��ġ
			if (bomb.Frame_Cnt != -1)
			{
				Bomb_Size++;
				Bomb_list.push_back(bomb);
			}
		}
		//�����Ӹ� ����
		else if (KeyBoard_Input == '2');
		else printf("�߸��� Ű �Է��Դϴ�.");

		//����� ��ġ �ʱ�ȭ
		Map[player.Pos_y - 1][player.Pos_x - 1] = 2;
#pragma endregion
#pragma region ����
		for (int i = 0; i < Monster_Size; i++)
		{
			if (!Monster_list[i].Alive)continue;
			for (int j = 0; j < 4; j++)
			{
				//���Ϳ� ����ڰ� ���ڸ� -> ����
				if (Map[Monster_list[i].Pos_y + idx[j]][Monster_list[i].Pos_x + idy[j]] == 2)
				{
					Output();
					printf("Game Over!");
					system("PAUSE");
					return 0;
				}
			}
			if (Map[Monster_list[i].Pos_y][Monster_list[i].Pos_x] == 0)   Monster_list[i].Alive = 0;
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
#pragma endregion
#pragma region ��ź
		for (int i = 0; i < Bomb_Size; i++)
		{
			if (Bomb_list[i].Frame_Cnt == -1)      continue;
			Bomb_list[i].Frame_Cnt++;
			//��ź ������ Bomb_list[i].Frame_Cnt = -1�� �ʱ�ȭ.
			if (Bomb_list[i].Frame_Cnt == 5)
			{
				Bomb_list[i].Frame_Cnt = -1;

				for (int j = 0; j < 4; j++)
				{
					int new_y = Bomb_list[i].Pos_y + idx[j];
					int new_x = Bomb_list[i].Pos_x + idy[j];
					if (Map[new_y][new_x] == 2)
					{
						Output();
						printf("Game Over!");
						system("PAUSE");
						return 0;
					}
					if (Map[new_y][new_x] == 3 || Map[new_y][new_x] == 5)	Map[new_y][new_x] = 0;
				}
				Map[Bomb_list[i].Pos_y][Bomb_list[i].Pos_x] = 0;
			}
		}
#pragma endregion
		Output();
	}
	return 0;
}
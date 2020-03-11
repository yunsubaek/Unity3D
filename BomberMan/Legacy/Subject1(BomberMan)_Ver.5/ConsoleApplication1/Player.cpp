#include "Player.h"
#include "Bomb.h"
#include "Singleton.h"

void Player::Player_Move(Player *player)
{
	if ((Singleton::getInstance()->Move_Dir == 'W') || (Singleton::getInstance()->Move_Dir == 'w'))
	{
		if (Singleton::getInstance()->Look_Dir == 1 && Singleton::getInstance()->Map[Pos_y - 2][Pos_x - 1] == 0)
		{
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 1] = 0;
			Pos_y--;
		}
		else Singleton::getInstance()->Look_Dir = 1;
	}
	else if ((Singleton::getInstance()->Move_Dir == 'A') || (Singleton::getInstance()->Move_Dir == 'a'))
	{
		if (Singleton::getInstance()->Look_Dir == 2 && Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 2] == 0)
		{
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 1] = 0;
			Pos_x--;
		}
		else Singleton::getInstance()->Look_Dir = 2;
	}
	else if ((Singleton::getInstance()->Move_Dir == 'S') || (Singleton::getInstance()->Move_Dir == 's'))
	{
		if (Singleton::getInstance()->Look_Dir == 3 && Singleton::getInstance()->Map[Pos_y][Pos_x - 1] == 0)
		{
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 1] = 0;
			Pos_y++;
		}
		else Singleton::getInstance()->Look_Dir = 3;
	}
	else if ((Singleton::getInstance()->Move_Dir == 'D') || (Singleton::getInstance()->Move_Dir == 'd'))
	{
		if (Singleton::getInstance()->Look_Dir == 4 && Singleton::getInstance()->Map[Pos_y - 1][Pos_x] == 0)
		{
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 1] = 0;
			Pos_x++;
		}
		else Singleton::getInstance()->Look_Dir = 4;
	}
	else if (Singleton::getInstance()->Move_Dir == '1')
	{
		Bomb *bomb = new Bomb();
		bomb->Frame_Cnt = -1;
		//�ٶ󺸴� ������ ����
		if (Singleton::getInstance()->Look_Dir == 1 && Singleton::getInstance()->Map[Pos_y - 2][Pos_x - 1] == 0)
			Singleton::getInstance()->Map[Pos_y - 2][Pos_x - 1] = 4, bomb->Frame_Cnt = 0, bomb->Pos_x = Pos_x - 1, bomb->Pos_y = Pos_y - 2;
		else if (Singleton::getInstance()->Look_Dir == 2 && Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 2] == 0)
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 2] = 4, bomb->Frame_Cnt = 0, bomb->Pos_x = Pos_x - 2, bomb->Pos_y = Pos_y - 1;
		else if (Singleton::getInstance()->Look_Dir == 3 && Singleton::getInstance()->Map[Pos_y][Pos_x - 1] == 0)
			Singleton::getInstance()->Map[Pos_y][Pos_x - 1] = 4, bomb->Frame_Cnt = 0, bomb->Pos_x = Pos_x - 1, bomb->Pos_y = Pos_y;
		else if (Singleton::getInstance()->Look_Dir == 4 && Singleton::getInstance()->Map[Pos_y - 1][Pos_x] == 0)
			Singleton::getInstance()->Map[Pos_y - 1][Pos_x] = 4, bomb->Frame_Cnt = 0, bomb->Pos_x = Pos_x, bomb->Pos_y = Pos_y - 1;
		//�ٶ󺸴� ���⿡ ��ź�� ������ ��ġ
		if (bomb->Frame_Cnt != -1)
		{
			Singleton::getInstance()->Bomb_Size++;
			Singleton::getInstance()->Bomb_list.push_back(bomb);
		}
	}
	//�����Ӹ� ����
	else if (Singleton::getInstance()->Move_Dir == '2');
	else printf("�߸��� Ű �Է��Դϴ�.");
	//����� ��ġ �ʱ�ȭ
	Singleton::getInstance()->Map[Pos_y - 1][Pos_x - 1] = 2;
}

Player::Player()
{
}

Player::~Player()
{
}

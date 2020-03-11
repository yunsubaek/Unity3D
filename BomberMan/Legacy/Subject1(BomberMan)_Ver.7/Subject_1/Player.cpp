#include "Player.h"
#include "Bomb.h"

void Player::Player_Init()
{
	Set_X	(Start_X);
	Set_Y	(Start_Y);
	Set_Cnt	(Start_Cnt);
}

void Player::Player_Move()
{
	Singleton *S = &Singleton::getSingleton();

	S->Map[Pos_y - 1][Pos_x - 1] = T_empty;

	if (Move_Dir == 'w')
	{
		if (Look_Dir == D_up)
		{
			if (S->Map[Pos_y - 2][Pos_x - 1] == T_bomb_item)	Pos_y--, S->Player_Bomb_Max_Cnt++;
			else if (S->Map[Pos_y - 2][Pos_x - 1] == T_empty)	Pos_y--;
		}
		else Look_Dir = D_up;
	}
	else if (Move_Dir == 'a')
	{
		if (Look_Dir == D_left)
		{
			if (S->Map[Pos_y - 1][Pos_x - 2] == T_bomb_item)	Pos_x--, S->Player_Bomb_Max_Cnt++;
			else if (S->Map[Pos_y - 1][Pos_x - 2] == T_empty)	Pos_x--;
		}
		else Look_Dir = D_left;
	}
	else if (Move_Dir == 's')
	{
		if (Look_Dir == D_down)
		{
			if (S->Map[Pos_y][Pos_x - 1] == T_bomb_item)		Pos_y++, S->Player_Bomb_Max_Cnt++;
			else if (S->Map[Pos_y][Pos_x - 1] == T_empty)		Pos_y++;
		}
		else Look_Dir = D_down;
	}
	else if (Move_Dir == 'd')
	{
		if (Look_Dir == D_right)
		{
			if (S->Map[Pos_y - 1][Pos_x] == T_bomb_item)		Pos_x++, S->Player_Bomb_Max_Cnt++;
			else if (S->Map[Pos_y - 1][Pos_x] == T_empty)		Pos_x++;
		}
		else Look_Dir = D_right;
	}
	else if (Move_Dir == '1')
	{
		if (S->Player_Bomb_Max_Cnt > S->Player_Bomb_Size)
		{
			int idx[4] = { 0,-1,0,1 };
			int idy[4] = { -1,0,1,0 };

			Bomb *bomb = new Bomb();

			for (int i = 0; i < 4; i++)
			{
				int n_x = idx[i] + Pos_x - 1;
				int n_y = idy[i] + Pos_y - 1;
				if (Look_Dir == D_up + i && (S->Map[n_y][n_x] == T_empty || S->Map[n_y][n_x] == T_bomb_item))
				{
					S->Map[n_y][n_x] = T_bomb, bomb->Set_X(n_x), bomb->Set_Y(n_y);
					S->Player_Bomb_Size++;
					S->Player_Bomb_list.push_back(bomb);
				}
			}
		}
	}
	else if (Move_Dir == '2');
	else printf("잘못된 키 입력입니다.");

	S->Map[Pos_y - 1][Pos_x - 1] = T_player;
}

Player::Player()
{
}

Player::~Player()
{
}
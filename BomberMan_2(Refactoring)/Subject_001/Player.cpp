#include "Player.h"
#include "Bomb.h"
#include "Singleton.h"

char Player::Get_Move_Dir()
{
	return Move_Dir;
}

void Player::Move(char move_dir)
{
	int temp;
	Move_Dir = move_dir;
	if (Move_Dir == 'w')
	{
		temp = Singleton::getSingleton().Search(Get_X() - 1, Get_Y());
		Get_Frame_Cnt() % 2 == 0 ? Set_Shape(UP_EMPTY) : Set_Shape(UP_FILL);
		if (temp == -1) Set_X(Get_X() - 1);
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Set_X(Get_X() - 1);
			Singleton::getSingleton().Able_to_place_bomb++;
			Singleton::getSingleton().Delete(temp);
		}
	}
	else if (Move_Dir == 'a')
	{
		temp = Singleton::getSingleton().Search(Get_X(), Get_Y() - 1);
		Get_Frame_Cnt() % 2 == 0 ? Set_Shape(LEFT_EMPTY) : Set_Shape(LEFT_FILL);
		if (temp == -1) Set_Y(Get_Y() - 1);
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Set_Y(Get_Y() - 1);
			Singleton::getSingleton().Able_to_place_bomb++;
			Singleton::getSingleton().Delete(temp);
		}
	}
	else if (Move_Dir == 's')
	{
		temp = Singleton::getSingleton().Search(Get_X() + 1, Get_Y());
		Get_Frame_Cnt() % 2 == 0 ? Set_Shape(DOWN_EMPTY) : Set_Shape(DOWN_FILL);
		if (temp == -1) Set_X(Get_X() + 1);
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Set_X(Get_X() + 1);
			Singleton::getSingleton().Able_to_place_bomb++;
			Singleton::getSingleton().Delete(temp);
		}
	}
	else if (Move_Dir == 'd')
	{
		temp = Singleton::getSingleton().Search(Get_X(), Get_Y() + 1);
		Get_Frame_Cnt() % 2 == 0 ? Set_Shape(RIGHT_EMPTY) : Set_Shape(RIGHT_FILL);
		if (temp == -1) Set_Y(Get_Y() + 1);
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Set_Y(Get_Y() + 1);
			Singleton::getSingleton().Able_to_place_bomb++;
			Singleton::getSingleton().Delete(temp);
		}
	}
	else if (Move_Dir == '1')
	{
		if (Singleton::getSingleton().Able_to_place_bomb <= Singleton::getSingleton().Current_Place_bomb) return;

		if (!strcmp(Get_Shape(), UP_FILL) || !strcmp(Get_Shape(), UP_EMPTY))
		{
			temp = Singleton::getSingleton().Search(Get_X() - 1, Get_Y());
			if (temp == -1) Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X() - 1, Get_Y(), T_player));
			else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
			{
				Singleton::getSingleton().Delete(temp);
				Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X() - 1, Get_Y(), T_player));
			}
			else return;
			Singleton::getSingleton().Current_Place_bomb++;
		}
		else if (!strcmp(Get_Shape(), LEFT_FILL) || !strcmp(Get_Shape(), LEFT_EMPTY))
		{
			temp = Singleton::getSingleton().Search(Get_X(), Get_Y() - 1);
			if (temp == -1) Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X(), Get_Y() - 1, T_player));
			else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
			{
				Singleton::getSingleton().Delete(temp);
				Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X(), Get_Y() - 1, T_player));
			}
			else return;
			Singleton::getSingleton().Current_Place_bomb++;
		}
		else if (!strcmp(Get_Shape(), DOWN_FILL) || !strcmp(Get_Shape(), DOWN_EMPTY))
		{
			temp = Singleton::getSingleton().Search(Get_X() + 1, Get_Y());
			if (temp == -1) Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X() + 1, Get_Y(), T_player));
			else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
			{
				Singleton::getSingleton().Delete(temp);
				Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X() + 1, Get_Y(), T_player));
			}
			else return;
			Singleton::getSingleton().Current_Place_bomb++;
		}
		else if (!strcmp(Get_Shape(), RIGHT_FILL) || !strcmp(Get_Shape(), RIGHT_EMPTY))
		{
			temp = Singleton::getSingleton().Search(Get_X(), Get_Y() + 1);
			if (temp == -1)	Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X(), Get_Y() + 1, T_player));
			else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
			{
				Singleton::getSingleton().Delete(temp);
				Singleton::getSingleton().obj_list.push_back(new Bomb(Get_X(), Get_Y() + 1, T_player));
			}
			else return;
			Singleton::getSingleton().Current_Place_bomb++;
		}
	}
	else if (Move_Dir == '2');
	else printf("잘못된 입력입니다.");
}

Player::Player(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Shape(DOWN_EMPTY);
	Set_Type(T_player);
	Set_Frame_Cnt(0);
}
#include "Bomb.h"
#include "Singleton.h"

Bomb::Bomb(int x, int y, Type p_type)
{
	Set_X(x);
	Set_Y(y);
	Set_Type(T_bomb);
	Set_Frame_Cnt(0);
	Set_Shape(BOMB_EMPTY);
	Set_Parent_Type(p_type);
}

void Bomb::Set_Parent_Type(Type p_type)
{
	Parent_Type = p_type;
}

Type Bomb::Get_Parent_Type()
{
	return Parent_Type;
}

void Bomb::Explosion()
{
	int idx[4] = { 0,-1,0,1 };
	int idy[4] = { -1,0,1,0 };
	int temp;
	for (int i = 0; i < 4; i++)
	{
		temp = Singleton::getSingleton().Search(Get_X() + idx[i], Get_Y() + idy[i]);
		if (temp == -1) continue;
		if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_player)
		{
			Singleton::getSingleton().Lose();
			Singleton::getSingleton().End_Flag = true;
		}
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_breakable_wall 
			|| Singleton::getSingleton().obj_list[temp]->Get_Type() == T_monster 
			|| Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Singleton::getSingleton().Delete(temp);
		}
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_boss) Singleton::getSingleton().Boss_Current_HP--;
	}
	temp = Singleton::getSingleton().Search(Get_X(), Get_Y());
	if (Get_Parent_Type() == T_player) Singleton::getSingleton().Current_Place_bomb--;
	Singleton::getSingleton().Delete(temp);
}

void Bomb::Update()
{
	Set_Frame_Cnt(Get_Frame_Cnt() + 1);
	Get_Frame_Cnt() % 2 == 0 ? Set_Shape(BOMB_EMPTY) : Set_Shape(BOMB_FILL);
	if (Get_Frame_Cnt() == Bomb_delay) Explosion();
}
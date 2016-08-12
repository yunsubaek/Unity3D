#include "Boss.h"
#include "Singleton.h"
#include "Bomb.h"

Boss::Boss(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Shape(BOSS_EMPTY);
	Set_Type(T_boss);
	Set_Frame_Cnt(0);
	Set_Have_Bomb(true);
}

void Boss::Update()
{
	Set_Frame_Cnt(Get_Frame_Cnt() + 1);
	Get_Frame_Cnt() % 2 == 0 ? Set_Shape(BOSS_EMPTY) : Set_Shape(BOSS_FILL);
	Rand_Move();
	Attack();
	if (Get_Frame_Cnt() % Bomb_Put_delay == 0)
	{
		int idx[4] = { -1,0,1,0 };
		int idy[4] = { 0,-1,0,1 };
		int rand_dir = Singleton::getSingleton().Rand_Dir();
		int n_x = Get_X() + idx[rand_dir];
		int n_y = Get_Y() + idy[rand_dir];
		int temp = Singleton::getSingleton().Search(n_x, n_y);

		if (temp == -1) Singleton::getSingleton().obj_list.push_back(new Bomb(n_x, n_y, T_boss));
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Singleton::getSingleton().Delete(temp);
			Singleton::getSingleton().obj_list.push_back(new Bomb(n_x, n_y, T_boss));
		}
	}
}
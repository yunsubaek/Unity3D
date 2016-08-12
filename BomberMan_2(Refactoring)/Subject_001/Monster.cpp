#include "Monster.h"
#include "Bomb.h"
#include "Singleton.h"

Monster::Monster()
{
}

Monster::Monster(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Shape(MONSTER_EMPTY);
	Set_Type(T_monster);
	Set_Frame_Cnt(0);
	Have_Bomb = false;
}

void Monster::Attack()
{
	int idx[4] = { 0,-1,0,1 };
	int idy[4] = { -1,0,1,0 };
	for (int i = 0; i < 4; i++)
	{
		int temp = Singleton::getSingleton().Search(Get_X() + idx[i], Get_Y() + idy[i]);
		if (temp == -1) continue;
		if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_player)
		{
			Singleton::getSingleton().Lose();
			Singleton::getSingleton().End_Flag = true;
		}
	}
}

void Monster::Update()
{
	Set_Frame_Cnt(Get_Frame_Cnt() + 1);
	Get_Frame_Cnt() % 2 == 0 ? Set_Shape(MONSTER_EMPTY) : Set_Shape(MONSTER_FILL);
	Rand_Move();
	Attack();
	if (Get_Frame_Cnt() % Bomb_Put_delay == 0 && Get_Have_Bomb())
	{
		int idx[4] = { -1,0,1,0 };
		int idy[4] = { 0,-1,0,1 };
		int rand_dir = Singleton::getSingleton().Rand_Dir();
		int n_x = Get_X() + idx[rand_dir];
		int n_y = Get_Y() + idy[rand_dir];
		int temp = Singleton::getSingleton().Search(n_x, n_y);

		if (temp == -1) Singleton::getSingleton().obj_list.push_back(new Bomb(n_x, n_y, T_monster));
		else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
		{
			Singleton::getSingleton().Delete(temp);
			Singleton::getSingleton().obj_list.push_back(new Bomb(n_x, n_y, T_monster));
		}
	}
}

void Monster::Rand_Move()
{
	int idx[4] = { -1,0,1,0 };
	int idy[4] = { 0,-1,0,1 };
	int rand_dir = Singleton::getSingleton().Rand_Dir();
	int temp = Singleton::getSingleton().Search(Get_X() + idx[rand_dir], Get_Y() + idy[rand_dir]);

	if (temp == -1) Set_X(Get_X() + idx[rand_dir]), Set_Y(Get_Y() + idy[rand_dir]);
	else if (Singleton::getSingleton().obj_list[temp]->Get_Type() == T_item)
	{
		Set_X(Get_X() + idx[rand_dir]), Set_Y(Get_Y() + idy[rand_dir]);
		Singleton::getSingleton().Delete(temp);
		Set_Have_Bomb(true);
	}
	else
	{
		bool Is_Move = false;
		for (int i = 0; i < 4; i++)if (Singleton::getSingleton().Search(Get_X() + idx[i], Get_Y() + idy[i]) == -1)Is_Move = true;
		if (Is_Move) Rand_Move();
	}
}

void Monster::Set_Have_Bomb(bool have_bomb)
{
	Have_Bomb = have_bomb;
}

bool Monster::Get_Have_Bomb()
{
	return Have_Bomb;
}

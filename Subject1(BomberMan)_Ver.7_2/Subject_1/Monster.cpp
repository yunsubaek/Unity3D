#include "Monster.h"
#include "Render.h"
#include "Bomb.h"
#include <time.h>

void Monster::Init()
{
	for (int i = 0; i < Init_Monster_Cnt; i++)	Add();
}

void Monster::Add()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int rand_x = (rand() + t) % (Map_Width - 2);
	int rand_y = (rand() + t) % (Map_Height - 2);

	if (S->Map[rand_y][rand_x] == T_empty)
	{
		Monster *monster = new Monster();

		monster->Frame_Cnt = 0;
		monster->Pos_x = rand_x;
		monster->Pos_y = rand_y;

		S->Monster_Size++;
		S->Monster_list.push_back(monster);
		S->Map[rand_y][rand_x] = T_monster;
	}
	else return Add();
}

void Monster::Attack()
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { 1,-1,0,0 };
	int idy[4] = { 0,0,1,-1 };

	for (int j = 0; j < 4; j++)
	{
		int n_x = idx[j] + Get_X();
		int n_y = idy[j] + Get_Y();
		if (S->Map[n_y][n_x] == T_player)
		{
			Render().Lose();
			return;
		}
	}
}

void Monster::Search()
{
	Singleton *S = &Singleton::getSingleton();

	for (int i = 0; i < S->Monster_Size; i++)	S->Monster_list[i]->Rand_Move(T_monster);
}

void Monster::Rand_Move(Type type)
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int random = (rand() + t) % 4;

	int x = Get_X();
	int y = Get_Y();

	S->Map[y][x] = T_empty;

	if (random == D_up)
	{
		if (S->Map[y - 1][x] == T_empty) y -= 1;
		else if (S->Map[y - 1][x] == T_bomb_item) y -= 1, Set_Have_Bomb(true);
	}
	else if (random == D_left)
	{
		if (S->Map[y][x - 1] == T_empty) x -= 1;
		else if (S->Map[y][x - 1] == T_bomb_item) x -= 1, Set_Have_Bomb(true);
	}
	else if (random == D_down)
	{
		if (S->Map[y + 1][x] == T_empty) y += 1;
		else if (S->Map[y + 1][x] == T_bomb_item) y += 1, Set_Have_Bomb(true);
	}
	else if (random == D_right)
	{
		if (S->Map[y][x + 1] == T_empty) x += 1;
		else if (S->Map[y][x + 1] == T_bomb_item) x += 1, Set_Have_Bomb(true);
	}
	if (Get_Have_Bomb())
	{
		if (Bomb_list.size() != 0)Bomb_Cnt();
		else Add_Bomb();
	}
	Set_X(x);
	Set_Y(y);
	S->Map[y][x] = type;
	Attack();
}

void Monster::Add_Bomb()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int idx[4] = { 0,-1,0,1 };
	int idy[4] = { -1,0,1,0 };

	int j = (rand() + t) % 4;

	Bomb *bomb = new Bomb();

	int n_x = idx[j] + Get_X();
	int n_y = idy[j] + Get_Y();

	if (S->Map[n_y][n_x] == T_empty || S->Map[n_y][n_x] == T_bomb_item)
	{
		S->Map[n_y][n_x] = T_bomb, bomb->Set_X(n_x), bomb->Set_Y(n_y);
		Bomb_list.push_back(bomb);
	}
	else Add_Bomb();
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
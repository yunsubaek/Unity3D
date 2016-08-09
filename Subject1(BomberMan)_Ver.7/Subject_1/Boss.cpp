#include "Boss.h"
#include "Bomb.h"
#include "Singleton.h"
#include <time.h>

void Boss::Boss_Move()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int random = (rand() + t) % 4;

	S->Map[Pos_y - 1][Pos_x - 1] = T_empty;

	if (random == D_up && (S->Map[Pos_y - 2][Pos_x - 1] == T_empty || S->Map[Pos_y - 2][Pos_x - 1] == T_bomb_item))			Pos_y -= 1;
	else if (random == D_left && (S->Map[Pos_y - 1][Pos_x - 2] == T_empty || S->Map[Pos_y - 1][Pos_x - 2] == T_bomb_item))	Pos_x -= 1;
	else if (random == D_down && (S->Map[Pos_y][Pos_x - 1] == T_empty || S->Map[Pos_y][Pos_x - 1] == T_bomb_item))			Pos_y += 1;
	else if (random == D_right && (S->Map[Pos_y - 1][Pos_x] == T_empty || S->Map[Pos_y - 1][Pos_x] == T_bomb_item))			Pos_x += 1;

	S->Map[Pos_y - 1][Pos_x - 1] = T_boss;
}

void Boss::Boss_Init()
{
	Set_X(Boss_X);
	Set_Y(Boss_Y);
	Set_HP(Boss_HP);
}

void Boss::Boss_Add_Bomb()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int idx[4] = { 0,-1,0,1 };
	int idy[4] = { -1,0,1,0 };

	int j = (rand() + t) % 4;

	Bomb *bomb = new Bomb();

	int n_x = idx[j] + Pos_x - 1;
	int n_y = idy[j] + Pos_y - 1;

	if (S->Map[n_y][n_x] == T_empty || S->Map[n_y][n_x] == T_bomb_item)
	{
		S->Boss_Bomb_Size++;
		S->Map[n_y][n_x] = T_bomb, bomb->Set_X(n_x), bomb->Set_Y(n_y);
		S->Boss_Bomb = bomb;
	}
	else Boss_Add_Bomb();
}

Boss::Boss()
{
}

Boss::~Boss()
{
}

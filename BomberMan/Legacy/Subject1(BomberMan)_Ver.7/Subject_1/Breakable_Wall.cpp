#include "Breakable_Wall.h"
#include "Singleton.h"
#include <time.h>
#include <iostream>

void Breakable_Wall::Breakable_Wall_Init()
{
	for (int i = 0; i < Init_Obstacle_Cnt; i++)	Breakable_Wall_Add();
}

void Breakable_Wall::Breakable_Wall_Add()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int rand_x = (rand() + t) % (Map_Width - 2);
	int rand_y = (rand() + t) % (Map_Height - 2);

	if (rand_x == 1 && rand_y == 1) return;
	if (S->Map[rand_y][rand_x] == T_empty)	S->Map[rand_y][rand_x] = T_breakable_wall;
	else Breakable_Wall_Add();
}

Breakable_Wall::Breakable_Wall()
{
}

Breakable_Wall::~Breakable_Wall()
{
}

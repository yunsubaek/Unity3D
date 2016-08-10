#include "Breakable_Wall.h"

void Breakable_Wall::Init()
{
	for (int i = 0; i < Init_Obstacle_Cnt; i++)	Add(T_breakable_wall);
}

Breakable_Wall::Breakable_Wall()
{
}

Breakable_Wall::~Breakable_Wall()
{
}

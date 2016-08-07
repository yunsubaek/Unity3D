#include "UnBreakable_Wall.h"
#include "Singleton.h"

void UnBreakable_Wall::UnBreakable_Wall_Init()
{
	Singleton *S = &Singleton::getSingleton();
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			if (i == 0 || i == Map_Height - 1)		S->Map[i][j] = T_unbreakable_wall;
			else if (j == 0 || j == Map_Width - 1)	S->Map[i][j] = T_unbreakable_wall;
			else if (i % 2 == 0 && j % 2 == 0)		S->Map[i][j] = T_unbreakable_wall;
		}
	}
}

UnBreakable_Wall::UnBreakable_Wall()
{
}

UnBreakable_Wall::~UnBreakable_Wall()
{
}

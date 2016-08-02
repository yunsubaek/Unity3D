#include "UnBreakable_Wall.h"
#include "Singleton.h"
#include <iostream>
using namespace std;

void UnBreakable_Wall::UnBreakable_Wall_Init()
{
	for (int i = 0; i < Map_Height; i++)
	{
		for (int j = 0; j < Map_Width; j++)
		{
			//맨 윗줄, 맨 아랫줄의 경우 1
			if (i == 0 || i == Map_Height - 1)				Singleton::getInstance()->Map[i][j] = 1;
			//맨 왼쪽, 맨 오른쪽의 경우 1
			else if (j == 0 || j == Map_Width - 1)			Singleton::getInstance()->Map[i][j] = 1;
			//나머지 경우
			else if (i % 2 == 0 && j % 2 == 0)				Singleton::getInstance()->Map[i][j] = 1;
		}
	}
}

UnBreakable_Wall::UnBreakable_Wall()
{
}

UnBreakable_Wall::~UnBreakable_Wall()
{
}

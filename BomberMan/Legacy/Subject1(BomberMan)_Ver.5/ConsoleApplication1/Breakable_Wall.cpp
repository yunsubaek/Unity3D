#include "Breakable_Wall.h"
#include "Singleton.h"
#include <time.h>

void Breakable_Wall::Breakable_Wall_Init()
{
	time_t t;
	time(&t);

	for (int i = 0; i < 20; i++)
	{
		int rand_x = (rand() + t) % 27;
		int rand_y = (rand() + t) % 17;
		if (rand_x == 1 && rand_y == 1)continue;
		if (Singleton::getInstance()->Map[rand_y][rand_x] == 0)
		{
			Singleton::getInstance()->Map[rand_y][rand_x] = 5;
		}
	}
}

Breakable_Wall::Breakable_Wall()
{
}

Breakable_Wall::~Breakable_Wall()
{
}

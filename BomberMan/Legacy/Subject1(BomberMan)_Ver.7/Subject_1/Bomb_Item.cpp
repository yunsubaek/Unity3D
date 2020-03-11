#include "Bomb_Item.h"
#include "Singleton.h"
#include <time.h>

void Bomb_Item::Bomb_Item_Init()
{
	for (int i = 0; i < Bomb_Item_Cnt; i++)	Bomb_Item_Add();
}

void Bomb_Item::Bomb_Item_Add()
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int rand_x = (rand() + t) % (Map_Width - 2);
	int rand_y = (rand() + t) % (Map_Height - 2);

	if (rand_x == 1 && rand_y == 1) return;
	if (S->Map[rand_y][rand_x] == T_empty)	S->Map[rand_y][rand_x] = T_bomb_item;
	else Bomb_Item_Add();
}

Bomb_Item::Bomb_Item()
{
}


Bomb_Item::~Bomb_Item()
{
}
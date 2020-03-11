#include "Bomb_Item.h"

void Bomb_Item::Init()
{
	for (int i = 0; i < Bomb_Item_Cnt; i++)	Add(T_bomb_item);
}

Bomb_Item::Bomb_Item()
{
}


Bomb_Item::~Bomb_Item()
{
}
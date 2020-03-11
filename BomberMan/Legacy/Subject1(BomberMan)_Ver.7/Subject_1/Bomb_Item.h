#pragma once
#include "Object.h"

class Bomb_Item:public Object
{
public:
	void Bomb_Item_Init();
	void Bomb_Item_Add();

	Bomb_Item();
	~Bomb_Item();
};
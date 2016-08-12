#pragma once
#include "Object.h"

class Item :public Object
{
public:
	Item(int x, int y);
	void Update();
};
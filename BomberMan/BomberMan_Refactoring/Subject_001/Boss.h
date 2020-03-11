#pragma once
#include "Monster.h"

class Boss :public Monster
{
public:
	Boss(int x, int y);
	void Update();
};
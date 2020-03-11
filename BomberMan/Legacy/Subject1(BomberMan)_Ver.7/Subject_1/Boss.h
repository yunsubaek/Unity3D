#pragma once
#include "Object.h"

class Boss:public Object
{
public:
	void Boss_Move();
	void Boss_Init();
	void Boss_Add_Bomb();

	Boss();
	~Boss();
};


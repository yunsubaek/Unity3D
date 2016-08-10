#pragma once
#include "Monster.h"

class Boss:public Monster
{
protected:
	int HP;

public:
	int Get_HP();

	void Set_HP(int hp);
	void Init();

	Boss();
	~Boss();
};
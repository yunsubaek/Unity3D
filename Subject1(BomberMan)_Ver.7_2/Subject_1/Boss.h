#pragma once
#include "Monster.h"

class Boss:public Monster
{
protected:
	int HP;

public:
	void Init();

	Boss();
	~Boss();
};
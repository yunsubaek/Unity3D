#pragma once
#include "Object.h"

class Monster :public Object
{
private:
	bool Have_Bomb;

public:
	Monster();
	Monster(int x, int y);
	void Attack();
	void Update();
	void Rand_Move();
	void Set_Have_Bomb(bool have_bomb);

	bool Get_Have_Bomb();
};
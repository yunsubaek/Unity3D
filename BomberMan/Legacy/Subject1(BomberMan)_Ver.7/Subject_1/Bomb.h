#pragma once
#include "Object.h"
#include "Boss.h"

class Bomb :public Object
{
public:
	void Player_Bomb_Attack(int i);
	void Player_Bomb_Cnt();

	void Boss_Bomb_Attack();
	void Boss_Bomb_Cnt();
	
	Boss *boss = new Boss();

	Bomb();
	~Bomb();
};
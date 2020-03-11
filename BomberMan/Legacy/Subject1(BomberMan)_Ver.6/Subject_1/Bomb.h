#pragma once
#include "Object.h"

class Bomb :public Object
{
public:
	void Bomb_Attack(int i);
	void Bomb_Cnt();
	Bomb();
	~Bomb();
};
#pragma once
#include "Object.h"
#include "Singleton.h"
#include <iostream>

class Player:public Object
{
public:
	Player();
	~Player();
	
	int Look_Dir;

	char Move_Dir;

	void Player_Move();
};


#pragma once
#include "Object.h"
#include "Singleton.h"
#include <iostream>

class Player:public Object
{
public:
	int Look_Dir;

	char Move_Dir;

	void Player_Move();
	void Player_Init();

	Player();
	~Player();
};


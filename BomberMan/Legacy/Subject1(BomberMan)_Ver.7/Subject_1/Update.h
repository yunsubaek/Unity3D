#pragma once
#include <iostream>
#include "Singleton.h"
#include "Player.h"

class Update
{
public:
	Player *player = new Player();

	void State();
	void Output();
	void Win();

	Update();
	~Update();
};
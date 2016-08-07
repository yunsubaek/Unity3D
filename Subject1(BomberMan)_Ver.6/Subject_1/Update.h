#pragma once
#include <iostream>
#include "Singleton.h"
#include "Player.h"

class Update
{
public:
	Update();
	~Update();

	Player *player = new Player();
	void State();
	void Output();
	void Win();
};


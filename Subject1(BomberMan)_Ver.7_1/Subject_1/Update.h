#pragma once
#include <iostream>
#include "Singleton.h"
#include "Player.h"

class Update
{
public:
	Player *player = new Player();

	void Start();
	void Output();
	void Win();
	void Lose();

	Update();
	~Update();
};


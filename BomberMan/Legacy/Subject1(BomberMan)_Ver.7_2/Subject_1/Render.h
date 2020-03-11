#pragma once
#include <iostream>
#include "Singleton.h"
#include "Player.h"

class Render
{
public:
	Player *player = new Player();

	void Start();
	void Output();
	void Win();
	void Lose();

	Render();
	~Render();
};


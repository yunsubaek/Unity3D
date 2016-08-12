#pragma once
#include "Object.h"

class Player :public Object
{
private:
	char Move_Dir;

public:
	Player(int x, int y);

	void Move(char move_dir);
	char Get_Move_Dir();
};
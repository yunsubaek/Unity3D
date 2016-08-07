#pragma once
#include "Declare.h"

class Object
{
protected:
	int Pos_x;
	int Pos_y;
	int Frame_Cnt;

public:
	Object();
	~Object();

	int Get_X();
	int Get_Y();
	int Get_Cnt();

	void Set_X(int x);
	void Set_Y(int y);
	void Set_Cnt(int cnt);
};
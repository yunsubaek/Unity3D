#pragma once
#include "Declare.h"

class Object
{
protected:
	int Pos_x;
	int Pos_y;
	int Frame_Cnt=0;
	int HP;

public:
	bool Have_Bomb;

	int Get_X();
	int Get_Y();
	int Get_Cnt();
	int Get_HP();
	
	void Set_X(int x);
	void Set_Y(int y);
	void Set_Cnt(int cnt);
	void Set_HP(int hp);

	Object* Monster_Bomb;

	Object();
	~Object();
};
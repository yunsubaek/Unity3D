#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Singleton
{
public:
	vector<Object*>		Player_Bomb_list;
	vector<Object*>		Monster_list;
	Object*				Boss_Bomb;
	
	int	Map[Map_Height][Map_Width];
	int	Monster_Size;
	int	Player_Bomb_Size;
	int Boss_Bomb_Size;

	int	Current_Boss_HP		= Boss_HP;
	int	Player_Bomb_Max_Cnt = 1;
	int	Boss_Bomb_Max_Cnt	= 1;
	
	bool End_Flag;

	static Singleton&	getSingleton();
};
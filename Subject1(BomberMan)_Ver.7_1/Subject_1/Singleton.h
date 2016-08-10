#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Singleton
{
public:
	vector<Object*>		Obj_list;
	vector<Object*>		Monster_list;
	
	int					Map[Map_Height][Map_Width];
	int					Monster_Size;
	int					Player_Bomb_Max_Cnt = 1;
	int					Current_Boss_HP = 3;

	bool				End_Flag;

	static Singleton&	getSingleton();
};

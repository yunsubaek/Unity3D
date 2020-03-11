#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Singleton
{
public:
	vector<Object*>		Obj_list;
	vector<Object*>		Bomb_list;
	vector<Object*>		Monster_list;
	
	int					Map[Map_Height][Map_Width];
	int					Monster_Size;
	int					Bomb_Size;
	
	bool				End_Flag;

	static Singleton&	getSingleton();
};

#pragma once
#include "Player.h"
#include <vector>
using namespace std;

class Singleton :public Object
{
public:
	std::vector<Object*> obj_list;

	bool End_Flag = false;

	void Win();
	void Lose();
	void Update();
	void Start_Map();
	void Delete(int i);
	void Print(Object player);

	int Rand_X();
	int Rand_Y();
	int Rand_Dir();
	int Search(int x, int y);

	int Current_Place_bomb;
	int Boss_Current_HP		= Boss_HP;
	int Able_to_place_bomb	= Bomb_Able_to_Put;

	Player* Make_Player();
	static Singleton&	getSingleton();
};
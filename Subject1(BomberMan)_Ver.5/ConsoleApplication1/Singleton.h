#pragma once
#include "Declare.h"
#include "Object.h"
#include "Monster.h"
#include "Bomb.h"
#include "Player.h"
using namespace std;

class Singleton
{
private:
	Singleton();

	static bool instanceFlag;

	static Singleton* instance;

public:
	Player *player = new Player();

	vector<Object*>		Monster_list;
	vector<Object*>		Bomb_list;

	char Move_Dir;

	int Look_Dir;
	int Map[Map_Height][Map_Width] = { 0 };
	int Monster_Size;
	int Bomb_Size;

	bool End_Flag = false;

	virtual ~Singleton() 
	{
		instanceFlag = false;
	};
	static Singleton* getInstance();
};
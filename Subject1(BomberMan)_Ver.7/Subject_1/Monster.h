#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Monster :public Object
{
public:
	void Monster_Init();
	void Monster_Add();
	void Monster_Attack();
	void Monster_Move();
	void Monster_Add_Bomb(Object *monster);
	void Monster_Bomb_Attack(Object *monster);

	int Monster_Bomb_Size;

	Monster();
	~Monster();
};
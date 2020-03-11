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
	Monster();
	~Monster();
};
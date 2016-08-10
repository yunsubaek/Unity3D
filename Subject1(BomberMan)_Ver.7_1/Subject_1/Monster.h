#pragma once
#include "Object.h"
#include <vector>
using namespace std;

class Monster :public Object
{
public:
	void Init();
	void Add();
	void Attack();
	void Rand_Move(Type type);
	void Search();
	void Add_Bomb();

	Monster();
	~Monster();
};
#pragma once
#include "Object.h"

class Breakable_Wall :public Object
{
public:
	void Breakable_Wall_Add();
	void Breakable_Wall_Init();

	Breakable_Wall();
	~Breakable_Wall();
};
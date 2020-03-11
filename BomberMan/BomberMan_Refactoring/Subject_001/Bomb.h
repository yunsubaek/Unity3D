#pragma once
#include "Object.h"

class Bomb :public Object
{
private:
	Type Parent_Type;
public:
	Bomb(int x, int y, Type p_type);
	void Set_Parent_Type(Type p_type);
	void Update();
	void Explosion();

	Type Get_Parent_Type();
};
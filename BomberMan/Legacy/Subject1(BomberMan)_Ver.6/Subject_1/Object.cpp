#include "Object.h"

int Object::Get_X()
{
	return Pos_x;
}

int Object::Get_Y()
{
	return Pos_y;
}

int Object::Get_Cnt()
{
	return Frame_Cnt;
}

void Object::Set_X(int x)
{
	Pos_x = x;
}

void Object::Set_Y(int y)
{
	Pos_y = y;
}

void Object::Set_Cnt(int cnt)
{
	Frame_Cnt = cnt;
}

Object::Object()
{
}

Object::~Object()
{
}

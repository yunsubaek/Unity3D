#include "Object.h"

void Object::Set_Frame_Cnt(int frame_cnt)
{
	Frame_Cnt = frame_cnt;
}

void Object::Set_X(int x)
{
	Pos_x = x;
}

void Object::Set_Y(int y)
{
	Pos_y = y;
}

void Object::Set_Type(Type t_type)
{
	type = t_type;
}

int Object::Get_Frame_Cnt()
{
	return Frame_Cnt;
}

int Object::Get_X()
{
	return Pos_x;
}

int Object::Get_Y()
{
	return Pos_y;
}

void Object::Update()
{
	Frame_Cnt++;
}

Type Object::Get_Type()
{
	return type;
}


void Object::Set_Shape(char *shape)
{
	strcpy_s(Shape, shape);
}

char *Object::Get_Shape()
{
	return Shape;
}

Object::Object()
{
}

Object::~Object()
{
}

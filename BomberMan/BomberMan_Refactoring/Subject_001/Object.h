#pragma once
#include "Declareh.h"
#include <cstring>
using namespace std;

class Object
{
private:
	int Pos_x;
	int Pos_y;
	int Frame_Cnt;
	char Shape[3];
	Type type;

public:
	void Set_Frame_Cnt(int frame_cnt);
	void Set_X(int x);
	void Set_Y(int y);
	void Set_Type(Type t_type);
	void Set_Shape(char *shape);

	int Get_Frame_Cnt();
	int Get_X();
	int Get_Y();
	char *Get_Shape();
	Type Get_Type();

	virtual void Update();

	Object();
	~Object();
};
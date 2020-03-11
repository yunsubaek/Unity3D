#pragma once
#include "Declare.h"
#include <vector>
using namespace std;

class Object
{
protected:
	int Pos_x;
	int Pos_y;
	int Frame_Cnt;
	bool Have_Bomb = false;

public:
	int Get_X();
	int Get_Y();
	int Get_Cnt();

	bool Get_Have_Bomb();

	void Add(Type type);
	void Set_X(int x);
	void Set_Y(int y);
	void Set_Cnt(int cnt);
	void Set_Have_Bomb(bool Is_Bomb);

	vector<Object*>	Bomb_list;

	virtual void Init();
	virtual void Cnt();
	virtual void Move();
	virtual void Rand_Move(Type type);
	virtual void Attack();
	virtual void Add_Bomb();
	virtual void Bomb_Attack();
	virtual void Bomb_Cnt();

	Object();
	~Object();
};
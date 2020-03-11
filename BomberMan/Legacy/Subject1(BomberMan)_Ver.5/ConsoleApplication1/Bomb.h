#ifndef __BOMB_H__
#define __BOMB_H__
#include "Object.h"
#include <vector>
using namespace std;

class Bomb:public Object
{
public:
	void Bomb_Attack(int i);
	void Bomb_Cnt();
	Bomb();
	~Bomb();
};
#endif
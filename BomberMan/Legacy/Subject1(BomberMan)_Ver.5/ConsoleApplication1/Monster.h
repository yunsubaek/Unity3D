#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "Object.h"
#include <vector>
using namespace std;

class Monster:public Object
{
public:
	void Monster_Init();
	void Monster_Attack(vector<Object*> *Monster_list);
	void Monster_Move(vector<Object*> *Monster_list);
	Monster();
	~Monster();
};
#endif
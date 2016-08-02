#ifndef __BREAKABLEWALL_H__
#define __BREAKABLEWALL_H__
#include "Object.h"

class Breakable_Wall:public Object
{
public:
	void Breakable_Wall_Init();
	Breakable_Wall();
	~Breakable_Wall();
};
#endif
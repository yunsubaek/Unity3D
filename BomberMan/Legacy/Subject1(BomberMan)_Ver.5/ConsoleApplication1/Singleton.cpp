#include "Singleton.h"

Singleton::Singleton()
{
	Look_Dir = 0;
	Monster_Size = 0;
	Bomb_Size = 0;
}

bool Singleton::instanceFlag = false;
Singleton* Singleton::instance = NULL;
Singleton* Singleton::getInstance()
{
	if (instance == NULL)
	{
		instance = new Singleton();
		instanceFlag = true;
	}
	return instance;
}
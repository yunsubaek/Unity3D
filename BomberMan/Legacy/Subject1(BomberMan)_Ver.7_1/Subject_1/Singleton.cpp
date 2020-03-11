#include "Singleton.h"

Singleton & Singleton::getSingleton()
{
	static Singleton instance;
	return instance;
}
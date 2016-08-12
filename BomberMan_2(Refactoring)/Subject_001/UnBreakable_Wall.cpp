#include "UnBreakable_Wall.h"
#include "Singleton.h"

UnBreakable_Wall::UnBreakable_Wall(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Type(T_unbreakable_wall);
	Set_Shape(UN_BREAKABLE_WALL);
}
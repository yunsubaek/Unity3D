#include "Breakable_Wall.h"

Breakable_Wall::Breakable_Wall(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Type(T_breakable_wall);
	Set_Shape(BREAKABLE_WALL);
}
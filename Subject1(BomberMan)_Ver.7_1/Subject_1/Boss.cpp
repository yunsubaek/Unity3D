#include "Boss.h"

int Boss::Get_HP()
{
	return HP;
}

void Boss::Set_HP(int hp)
{
	HP = hp;
}

void Boss::Init()
{
	Set_X(Boss_X);
	Set_Y(Boss_Y);
	Set_HP(Boss_HP);
	Set_Have_Bomb(true);
}

Boss::Boss()
{
}


Boss::~Boss()
{
}

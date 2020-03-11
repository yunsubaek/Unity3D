#pragma once

enum Type
{
	T_empty,
	T_unbreakable_wall,
	T_player,
	T_monster,
	T_bomb,
	T_breakable_wall,
};

enum Dir
{
	D_up,
	D_left,
	D_down,
	D_right
};

const int Map_Height		= 19;
const int Map_Width			= 29;

const int Init_Obstacle_Cnt	= 20;
const int Init_Monster_Cnt	= 10;

const int Start_X			= 2;
const int Start_Y			= 2;
const int Start_Cnt			= 0;

const int Bomb_delay		= 5;
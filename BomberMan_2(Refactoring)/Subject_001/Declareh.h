#pragma once

enum Type
{
	T_empty,
	T_unbreakable_wall,
	T_player,
	T_monster,
	T_bomb,
	T_breakable_wall,
	T_item,
	T_boss,
	T_space
};

enum Dir
{
	D_up,
	D_left,
	D_down,
	D_right
};

static char *SPACE					= "��";

static char *UN_BREAKABLE_WALL		= "��";
static char *BREAKABLE_WALL			= "��";

static char *UP_EMPTY				= "��";
static char *UP_FILL				= "��";
static char *LEFT_EMPTY				= "��";
static char *LEFT_FILL				= "��";
static char *DOWN_EMPTY				= "��";
static char *DOWN_FILL				= "��";
static char *RIGHT_EMPTY			= "��";
static char *RIGHT_FILL				= "��";

static char *BOMB_EMPTY				= "��";
static char *BOMB_FILL				= "��";

static char *MONSTER_EMPTY			= "��";
static char *MONSTER_FILL			= "��";

static char *BOSS_EMPTY				= "��";
static char *BOSS_FILL				= "��";

static char *ITEM_EMPTY				= "��";
static char *ITEM_FILL				= "��";

const int Init_Breakable_Wall_Cnt	= 10;

const int Map_Height				= 17;
const int Map_Width					= 27;

const int Init_Item_Cnt				= 10;
const int Init_Monster_Cnt			= 1;

const int Start_X					= 1;
const int Start_Y					= 1;
const int Start_Cnt					= 0;

const int Bomb_Put_delay			= 10;
const int Bomb_delay				= 6;
const int Bomb_Item_Cnt				= 10;
const int Bomb_Able_to_Put			= 1;

const int Boss_X					= 15;
const int Boss_Y					= 10;
const int Boss_HP					= 3;
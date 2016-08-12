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

static char *SPACE					= "¡¡";

static char *UN_BREAKABLE_WALL		= "¡á";
static char *BREAKABLE_WALL			= "¡à";

static char *UP_EMPTY				= "¡â";
static char *UP_FILL				= "¡ã";
static char *LEFT_EMPTY				= "¢·";
static char *LEFT_FILL				= "¢¸";
static char *DOWN_EMPTY				= "¡ä";
static char *DOWN_FILL				= "¡å";
static char *RIGHT_EMPTY			= "¢¹";
static char *RIGHT_FILL				= "¢º";

static char *BOMB_EMPTY				= "¡Þ";
static char *BOMB_FILL				= "¡ß";

static char *MONSTER_EMPTY			= "¡Û";
static char *MONSTER_FILL			= "¡Ü";

static char *BOSS_EMPTY				= "¢½";
static char *BOSS_FILL				= "¢¾";

static char *ITEM_EMPTY				= "¡Ù";
static char *ITEM_FILL				= "¡Ú";

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
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Object.h"

class Player:public Object
{
public:
	void Player_Move(Player *player);
	Player();
	~Player();
};
#endif
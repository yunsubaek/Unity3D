#include "Main.h"
using namespace std;

int main()
{
	Player *player;
	Singleton::getSingleton().Start_Map();
	player = Singleton::getSingleton().Make_Player();

	while (!Singleton::getSingleton().End_Flag)
	{
		player->Move(_getch());
		Singleton::getSingleton().Update();
		Singleton::getSingleton().Print(*player);
		if (Singleton::getSingleton().Boss_Current_HP == 0)Singleton::getSingleton().Win();
	}
	return 0;
}
#include "Main.h"
using namespace std;

int main()
{
	Singleton *S						= &Singleton::getSingleton();

	int Cnt								= Start_Cnt;

	Player *player						= new Player();
	Render *render						= new Render();
	Monster *monster					= new Monster();
	Boss *boss							= new Boss();
	Bomb_Item *bomb_item				= new Bomb_Item();
	Breakable_Wall *breakablewall		= new Breakable_Wall();
	UnBreakable_Wall *unbreakablewall	= new UnBreakable_Wall();

	render								->player = player;

	player								->Init();
	unbreakablewall						->Init();
	breakablewall						->Init();
	monster								->Init();
	bomb_item							->Init();
	boss								->Init();

	render								->Start();

	while (player->Move_Dir = _getch())
	{
		if (S->End_Flag)				return 0;

		player							->Set_Cnt(Cnt++);
		player							->Move();
		monster							->Search();
		boss							->Rand_Move(T_boss);
		render							->Output();
	}
	
	return 0;
}
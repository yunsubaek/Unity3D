#include "Main.h"
using namespace std;

int main()
{
	Singleton *S						= &Singleton::getSingleton();

	int Cnt								= Start_Cnt;

	Player *player						= new Player();
	Update *update						= new Update();
	Monster *monster					= new Monster();
	Bomb *bomb							= new Bomb();
	Breakable_Wall *breakablewall		= new Breakable_Wall();
	UnBreakable_Wall *unbreakablewall	= new UnBreakable_Wall();

	player->Set_X(Start_X);
	player->Set_Y(Start_Y);
	player->Set_Cnt(Cnt);

	unbreakablewall->UnBreakable_Wall_Init();
	breakablewall->Breakable_Wall_Init();
	monster->Monster_Init();
	update->State();

	while (player->Move_Dir = _getch())
	{
		if (S->Monster_Size == 0) update->Win();
		if (S->End_Flag)return 0;
		update->player = player;
		player->Set_Cnt(Cnt++);
		player->Player_Move();
		monster->Monster_Move();
		monster->Monster_Attack();
		bomb->Bomb_Cnt();
		update->Output();
	}
	
	return 0;
}
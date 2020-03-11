#include "Main.h"
using namespace std;

int main()
{
	Singleton *S						= &Singleton::getSingleton();

	int Cnt								= Start_Cnt;

	Player *player						= new Player();
	Update *update						= new Update();
	Monster *monster					= new Monster();
	Boss *boss							= new Boss();
	Bomb *bomb							= new Bomb();
	Bomb_Item *bomb_item				= new Bomb_Item();
	Breakable_Wall *breakablewall		= new Breakable_Wall();
	UnBreakable_Wall *unbreakablewall	= new UnBreakable_Wall();

	player			->Player_Init();
	unbreakablewall	->UnBreakable_Wall_Init();
	breakablewall	->Breakable_Wall_Init();
	monster			->Monster_Init();
	bomb_item		->Bomb_Item_Init();
	boss			->Boss_Init();

	update			->State();
	bomb			->boss = boss;

	while (player->Move_Dir = _getch())
	{
		update			->player = player;
		player			->Set_Cnt(Cnt++);
		player			->Player_Move();
		monster			->Monster_Move();
		monster			->Monster_Attack();
		if(boss->Get_HP()>0)
		{
			boss->Boss_Move();
			if (S->Boss_Bomb_Size == 0) boss->Boss_Add_Bomb();
			if (S->Boss_Bomb_Size > 0)	bomb->Boss_Bomb_Cnt();
		}
		bomb			->Player_Bomb_Cnt();
		update			->Output();

		if (S->End_Flag)return 0;
	}
	return 0;
}
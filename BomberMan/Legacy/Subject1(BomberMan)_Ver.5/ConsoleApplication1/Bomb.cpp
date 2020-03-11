#include "Bomb.h"
#include "Update.h"
#include "Singleton.h"

void Bomb::Bomb_Attack(int i)
{
	int idx[4] = { 1,-1,0,0 };
	int idy[4] = { 0,0,1,-1 };

	Singleton::getInstance()->Map[Singleton::getInstance()->Bomb_list[i]->Pos_y][Singleton::getInstance()->Bomb_list[i]->Pos_x] = 0;

	for (int j = 0; j < 4; j++)
	{
		if (Singleton::getInstance()->Bomb_Size == 0)break;
		int new_y = Singleton::getInstance()->Bomb_list[i]->Pos_y + idx[j];
		int new_x = Singleton::getInstance()->Bomb_list[i]->Pos_x + idy[j];
		if (Singleton::getInstance()->Map[new_y][new_x] == 2)
		{
			Update().Output();
			printf("Game Over!");
			system("PAUSE");
			Singleton::getInstance()->End_Flag = true;
			return;
		}
		else if (Singleton::getInstance()->Map[new_y][new_x] == 3)
		{
			Singleton::getInstance()->Map[new_y][new_x] = 0;
			for (int k = 0; k < Singleton::getInstance()->Monster_Size; k++)
			{
				if (Singleton::getInstance()->Monster_list[k]->Pos_x != new_x || Singleton::getInstance()->Monster_list[k]->Pos_y != new_y) continue;
				Singleton::getInstance()->Monster_list.erase(Singleton::getInstance()->Monster_list.begin() + k);
				Singleton::getInstance()->Monster_Size--;
				break;
			}
		}
		else if (Singleton::getInstance()->Map[new_y][new_x] == 5) Singleton::getInstance()->Map[new_y][new_x] = 0;
	}
}

void Bomb::Bomb_Cnt()
{
	for (int i = 0; i < Singleton::getInstance()->Bomb_Size; i++)
	{
		Singleton::getInstance()->Bomb_list[i]->Frame_Cnt++;
		if (Singleton::getInstance()->Bomb_list[i]->Frame_Cnt == 5)
		{
			Bomb_Attack(i);
			Singleton::getInstance()->Bomb_list.erase(Singleton::getInstance()->Bomb_list.begin() + i);
			Singleton::getInstance()->Bomb_Size--;
			break;
		}
	}
}

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

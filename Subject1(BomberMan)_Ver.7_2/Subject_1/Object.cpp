#include "Object.h"
#include "Singleton.h"
#include "Render.h"
#include <time.h>

int Object::Get_X()
{
	return Pos_x;
}

int Object::Get_Y()
{
	return Pos_y;
}

int Object::Get_Cnt()
{
	return Frame_Cnt;
}

bool Object::Get_Have_Bomb()
{
	return Have_Bomb;
}

void Object::Set_X(int x)
{
	Pos_x = x;
}

void Object::Set_Y(int y)
{
	Pos_y = y;
}

void Object::Set_Cnt(int cnt)
{
	Frame_Cnt = cnt;
}

void Object::Set_Have_Bomb(bool Is_Bomb)
{
	Have_Bomb = Is_Bomb;
}

void Object::Add(Type type)
{
	Singleton *S = &Singleton::getSingleton();

	time_t t;
	time(&t);

	int rand_x = (rand() + t) % (Map_Width - 2);
	int rand_y = (rand() + t) % (Map_Height - 2);

	if (S->Map[rand_y][rand_x] == T_empty)	S->Map[rand_y][rand_x] = type;
	else return Add(type);
}

void Object::Init()
{
	
}

void Object::Cnt()
{

}

void Object::Move()
{

}

void Object::Rand_Move(Type type)
{

}

void Object::Attack()
{

}

void Object::Add_Bomb()
{

}

void Object::Bomb_Attack()
{
	Singleton *S = &Singleton::getSingleton();

	int idx[4] = { -1,1,0,0 };
	int idy[4] = { 0,0,-1,1 };
	int x = Get_X();
	int y = Get_Y();

	S->Map[y][x] = 0;

	for (int j = 0; j < 4; j++)
	{
		int n_y = y + idy[j];
		int n_x = x + idx[j];
		if (S->Map[n_y][n_x] == T_player)
		{
			Render().Lose();
			return;
		}
		else if (S->Map[n_y][n_x] == T_monster)
		{
			S->Map[n_y][n_x] = T_empty;
			for (int k = 0; k < S->Monster_Size; k++)
			{
				int m_x = S->Monster_list[k]->Get_X();
				int m_y = S->Monster_list[k]->Get_Y();
				if (m_x != n_x || m_y != n_y) continue;
				S->Monster_list.erase(S->Monster_list.begin() + k);
				S->Monster_Size--;
				break;
			}
		}
		else if (S->Map[n_y][n_x] == T_breakable_wall || S->Map[n_y][n_x] == T_bomb_item) S->Map[n_y][n_x] = T_empty;
		else if (S->Map[n_y][n_x] == T_boss)
		{
			S->Current_Boss_HP--;
			if (S->Current_Boss_HP == 0) Render().Win();
		}
	}
}

void Object::Bomb_Cnt()
{
	Singleton *S = &Singleton::getSingleton();

	int Cnt;

	for (int i = 0; i < Bomb_list.size(); i++)
	{
		Bomb_list[i]->Get_Cnt() < 0 ? Cnt = 0 : Cnt = Bomb_list[i]->Get_Cnt();
		Bomb_list[i]->Set_Cnt(++Cnt);
		if (Bomb_list[i]->Get_Cnt() == Bomb_delay)
		{
			Bomb_list[i]->Bomb_Attack();
			Bomb_list.erase(Bomb_list.begin() + i);
			break;
		}
	}
}

Object::Object()
{
}

Object::~Object()
{
}

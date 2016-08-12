#include "Item.h"

Item::Item(int x, int y)
{
	Set_X(x);
	Set_Y(y);
	Set_Shape(ITEM_EMPTY);
	Set_Type(T_item);
	Set_Frame_Cnt(0);
}

void Item::Update()
{
	Set_Frame_Cnt(Get_Frame_Cnt() + 1);
	Get_Frame_Cnt() % 2 == 0 ? Set_Shape(ITEM_EMPTY) : Set_Shape(ITEM_FILL);
}
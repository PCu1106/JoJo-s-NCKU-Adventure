#ifndef ArmorItem_H
#define ArmorItem_H
#include"Item.h"
class ArmorItem :public Item
{
public:
	const int defense_increment; //the number of increment on defense after equipping this item
	ArmorItem(int lr, string namae, string eff, string des, int wei, char t, int de,int n)
		:Item(lr, namae, eff, des, wei, t, n), defense_increment(de)
	{
	}

};
#endif
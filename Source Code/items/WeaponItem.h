#ifndef WeaponItem_H
#define WeaponItem_H
#include"Item.h"
class WeaponItem :public Item
{
public:
	const int attack_increment; //the number of increment on attack after equipping this item
	WeaponItem(int lr, string namae, string eff, string des, int wei, char t,int at,int n)
		:Item(lr, namae, eff, des, wei, t,n), attack_increment(at)
	{
	}
};
#endif
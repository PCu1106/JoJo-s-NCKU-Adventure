#ifndef ConsumableItem_H
#define ConsumableItem_H
#include"Item.h"
#include"NovicePlayer.h"
class NovicePlayer;
#include<iostream>
using namespace std;
class ConsumableItem :public Item
{
public:
	virtual void use(NovicePlayer*) = 0;//This function is responsible to adjust a player¡¦s status such as HP, MP¡K
	ConsumableItem(int lr, string namae, string eff, string des, int wei, char t,int n)
		:Item(lr, namae, eff, des, wei, t,n)
	{
	}
};
#endif

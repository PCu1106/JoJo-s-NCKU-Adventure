#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>
using namespace std;
class Item
{
public:
	const int No;
	const int level_required; // level limit of equip/use this item
	const string name; // the name of this item E.g., ¡§JW¡¦s Hand¡¨
	const string effects; // a short description of its effect E.g., ¡§Attack + 100, 20 % of probability making opponents cannot act at the next turn¡¨
	const string description; // a short description of this item E.g., ¡§A silver - made hand - shaped weapon.There¡¦s a folklore said that once upon a time, a blacksmith encountered and was beaten by the JWMaster.While fighting with JWM, he found that the shape of JWM¡¦s hand is so beautiful.So he made a weapon that mimics the shape of JWM¡¦s hand for increasing his ability in self - defense.¡¨
	const int weight; // the weight of the item
	const char type;//Type of this item, ¡§w¡¨ for weapons, ¡§a¡¨ for armors, ¡§c¡¨ for consumables
	Item(int lr, string namae, string eff, string des, int wei, char t,int n)
		:level_required(lr),name(namae),effects(eff),description(des),weight(wei),type(t),No(n)
	{
	}
};
#endif
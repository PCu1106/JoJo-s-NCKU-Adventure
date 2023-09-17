#ifndef LifePotion_H
#define LifePotion_H
#include"ConsumableItem.h"
#include"NovicePlayer.h"
class LifePotion :public ConsumableItem
{
public:
	LifePotion();//cons
	virtual void use(NovicePlayer*);
};
#endif

#ifndef MagicPotion_H
#define MagicPotion_H
#include"ConsumableItem.h"
#include"NovicePlayer.h"
class MagicPotion :public ConsumableItem
{
public:
	MagicPotion();//cons
	virtual void use(NovicePlayer*);
};
#endif

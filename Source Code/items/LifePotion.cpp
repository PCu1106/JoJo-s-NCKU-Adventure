#include "LifePotion.h"

LifePotion::LifePotion()
	:ConsumableItem(0, "生命藥水", "HP+20", "來自妖精王之森的生命之泉", 1, 'c',201)
{
}

void LifePotion::use(NovicePlayer *user)
{
	cout << user->getName() << "恢復了20HP\n";
	user->setHp(user->getHp() + 20);
	cout << user->getName() << "目前HP：" << user->getHp() << endl;
	system("pause");
}
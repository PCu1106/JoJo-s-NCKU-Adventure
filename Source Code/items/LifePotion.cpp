#include "LifePotion.h"

LifePotion::LifePotion()
	:ConsumableItem(0, "�ͩR�Ĥ�", "HP+20", "�Ӧۧ�������˪��ͩR���u", 1, 'c',201)
{
}

void LifePotion::use(NovicePlayer *user)
{
	cout << user->getName() << "��_�F20HP\n";
	user->setHp(user->getHp() + 20);
	cout << user->getName() << "�ثeHP�G" << user->getHp() << endl;
	system("pause");
}
#include "MagicPotion.h"

MagicPotion::MagicPotion()
	:ConsumableItem(0, "魔力藥水", "MP+20", "森林巫師精心熬煮七七四十九天的藥水", 1, 'c',202)
{
}

void MagicPotion::use(NovicePlayer *user)
{
	cout << user->getName() << "恢復了20MP\n";
	user->setMp(user->getMp() + 20);
	cout << user->getName() << "目前MP：" << user->getMp() << endl;
	system("pause");
}

#include "MagicPotion.h"

MagicPotion::MagicPotion()
	:ConsumableItem(0, "�]�O�Ĥ�", "MP+20", "�˪L�Ův��߼��N�C�C�|�Q�E�Ѫ��Ĥ�", 1, 'c',202)
{
}

void MagicPotion::use(NovicePlayer *user)
{
	cout << user->getName() << "��_�F20MP\n";
	user->setMp(user->getMp() + 20);
	cout << user->getName() << "�ثeMP�G" << user->getMp() << endl;
	system("pause");
}

#include "FieldMenu.h"

FieldMenu::FieldMenu()
{
}

int FieldMenu::FieldChoice(NovicePlayer**pp, int nply)
{
	system("cls");
	char *arrow = new char[3];
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			arrow[i] = '>';
		}
		else
		{
			arrow[i] = ' ';
		}
	}
	while (true)
	{
		system("cls");
		cout << "選單\n";
		cout << arrow[0] << "背包\n" << arrow[1] << "存檔\n" << arrow[2] << "退出選單\n" << endl;
		char option;
		option = _getch();
		if (option == 72)//按上
		{
			for (int i = 0; i < 3; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 0)//在最上面
					{
						arrow[0] = ' ';
						arrow[2] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//找到就離開了
				}
			}
		}
		if (option == 80)//按下
		{
			for (int i = 0; i < 3; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 3 - 1)//在最下面
					{
						arrow[3 - 1] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//找到就離開了
				}
			}
		}
		if (option == 13)//按enter
		{
			int choice = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					choice = i;
					break;
				}
			}
			if (choice == 0)
			{
				system("cls");
				whosbackpack(pp, nply);
			}
			else if (choice == 1)
			{
				system("cls");
				return 1;
			}
			else if (choice == 2)
			{
				return 0;
			}
		}
	}
	return 0;
}

void FieldMenu::whosbackpack(NovicePlayer ** pp, int nply)
{
	system("cls");
	char *arrow = new char[nply + 1];
	for (int i = 0; i < nply + 1; i++)
	{
		if (i == 0)
		{
			arrow[i] = '>';
		}
		else
		{
			arrow[i] = ' ';
		}
	}
	while (true)
	{
		system("cls");
		cout << "看誰的背包\n";
		for (int i = 0; i < nply; i++)
		{
			if (pp[i] != nullptr)
			{
				cout << arrow[i] << pp[i]->getName() << endl;
			}
		}
		cout << arrow[nply] << "退回\n";
		char option;
		option = _getch();
		if (option == 72)//按上
		{
			for (int i = 0; i < nply + 1; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 0)//在最上面
					{
						arrow[0] = ' ';
						arrow[nply] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//找到就離開了
				}
			}
		}
		if (option == 80)//按下
		{
			for (int i = 0; i < nply + 1; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == nply)//在最下面
					{
						arrow[nply] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//找到就離開了
				}
			}

		}
		if (option == 13)//按enter
		{
			int choice = 0;
			for (int i = 0; i < nply + 1; i++)
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					choice = i;
					break;
				}
			}
			if (choice == nply)
			{
				return;
			}
			backpack(pp[choice]);//若隊伍裡只有1,4，箭頭2指到4
		}
	}
}

void FieldMenu::backpack(NovicePlayer * pp)
{
	system("cls");
	char *arrow = new char[pp->backpack_slot_limit + 1];
	for (int i = 0; i < pp->backpack_slot_limit + 1; i++)
	{
		if (i == 0)
		{
			arrow[i] = '>';
		}
		else
		{
			arrow[i] = ' ';
		}
	}
	char option;
	int choice = 0;
	while (true)
	{
		system("cls");
		cout << pp->getName() << endl;
		cout << "容量" << pp->occupied_slot << "/" << pp->backpack_slot_limit << endl;
		cout << "負重" << pp->backpack_weight << "/" << pp->backpack_weight_limit << endl;
		cout << "金錢：" << pp->getMoney() << "$\n";
		for (int i = 0; i < pp->backpack_slot_limit; i++)
		{
			if (pp->backpack[i] == nullptr)
			{
				cout << arrow[i] << "---\n";
				continue;
			}
			cout << arrow[i] << pp->backpack[i]->name << endl;
		}
		cout << arrow[pp->backpack_slot_limit] << "退回\n";
		if (choice < pp->backpack_slot_limit)
		{
			if (pp->backpack[choice] != nullptr)
			{
				cout << "等級需求：" << pp->backpack[choice]->level_required << endl;
				cout << "重量：" << pp->backpack[choice]->weight << endl;
				cout << "效果：" << pp->backpack[choice]->effects << endl;
				cout << "類型：" << pp->backpack[choice]->type << endl;
				cout << pp->backpack[choice]->description << endl;
			}
		}
		option = _getch();
		if (option == 72)//按上
		{
			for (int i = 0; i < pp->backpack_slot_limit + 1; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 0)//在最上面
					{
						arrow[0] = ' ';
						arrow[pp->backpack_slot_limit] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//找到就離開了
				}
			}
		}
		if (option == 80)//按下
		{
			for (int i = 0; i < pp->backpack_slot_limit + 1; i++)//設定箭頭位置
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == pp->backpack_slot_limit)//在最下面
					{
						arrow[pp->backpack_slot_limit] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//找到就離開了
				}
			}
		}
		for (int i = 0; i < pp->backpack_slot_limit + 1; i++)
		{
			if (arrow[i] == '>')//找到箭頭的位置
			{
				choice = i;
				break;
			}
		}
		if (option == 13)//按enter
		{
			if (choice == pp->backpack_slot_limit)
			{
				return;
			}
			if (pp->backpack[choice] != nullptr)
			{
				if (pp->backpack[choice]->type == 'c')
				{
					cout << "使用消耗品\n";
					ConsumableItem *my_con = static_cast<ConsumableItem*>(pp->takeItem(choice));
					pp->useConsumable(my_con);
				}
				else if (pp->backpack[choice]->type == 'w')
				{
					cout << "裝備武器\n";
					WeaponItem*my_wea = static_cast<WeaponItem*>(pp->backpack[choice]);
					if (pp->equipWeapon(my_wea))
					{
						pp->takeItem(choice);
					}
				}
				else if (pp->backpack[choice]->type == 'a')
				{
					cout << "裝備防具\n";
					ArmorItem*my_arm = static_cast<ArmorItem*>(pp->backpack[choice]);
					if (pp->equipArmor(my_arm))
					{
						pp->takeItem(choice);
					}
				}
			}
		}
	}
}


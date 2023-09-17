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
		cout << "���\n";
		cout << arrow[0] << "�I�]\n" << arrow[1] << "�s��\n" << arrow[2] << "�h�X���\n" << endl;
		char option;
		option = _getch();
		if (option == 72)//���W
		{
			for (int i = 0; i < 3; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 0)//�b�̤W��
					{
						arrow[0] = ' ';
						arrow[2] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//���N���}�F
				}
			}
		}
		if (option == 80)//���U
		{
			for (int i = 0; i < 3; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 3 - 1)//�b�̤U��
					{
						arrow[3 - 1] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//���N���}�F
				}
			}
		}
		if (option == 13)//��enter
		{
			int choice = 0;
			for (int i = 0; i < 3; i++)
			{
				if (arrow[i] == '>')//���b�Y����m
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
		cout << "�ݽ֪��I�]\n";
		for (int i = 0; i < nply; i++)
		{
			if (pp[i] != nullptr)
			{
				cout << arrow[i] << pp[i]->getName() << endl;
			}
		}
		cout << arrow[nply] << "�h�^\n";
		char option;
		option = _getch();
		if (option == 72)//���W
		{
			for (int i = 0; i < nply + 1; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 0)//�b�̤W��
					{
						arrow[0] = ' ';
						arrow[nply] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//���N���}�F
				}
			}
		}
		if (option == 80)//���U
		{
			for (int i = 0; i < nply + 1; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == nply)//�b�̤U��
					{
						arrow[nply] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//���N���}�F
				}
			}

		}
		if (option == 13)//��enter
		{
			int choice = 0;
			for (int i = 0; i < nply + 1; i++)
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					choice = i;
					break;
				}
			}
			if (choice == nply)
			{
				return;
			}
			backpack(pp[choice]);//�Y����̥u��1,4�A�b�Y2����4
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
		cout << "�e�q" << pp->occupied_slot << "/" << pp->backpack_slot_limit << endl;
		cout << "�t��" << pp->backpack_weight << "/" << pp->backpack_weight_limit << endl;
		cout << "�����G" << pp->getMoney() << "$\n";
		for (int i = 0; i < pp->backpack_slot_limit; i++)
		{
			if (pp->backpack[i] == nullptr)
			{
				cout << arrow[i] << "---\n";
				continue;
			}
			cout << arrow[i] << pp->backpack[i]->name << endl;
		}
		cout << arrow[pp->backpack_slot_limit] << "�h�^\n";
		if (choice < pp->backpack_slot_limit)
		{
			if (pp->backpack[choice] != nullptr)
			{
				cout << "���ŻݨD�G" << pp->backpack[choice]->level_required << endl;
				cout << "���q�G" << pp->backpack[choice]->weight << endl;
				cout << "�ĪG�G" << pp->backpack[choice]->effects << endl;
				cout << "�����G" << pp->backpack[choice]->type << endl;
				cout << pp->backpack[choice]->description << endl;
			}
		}
		option = _getch();
		if (option == 72)//���W
		{
			for (int i = 0; i < pp->backpack_slot_limit + 1; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 0)//�b�̤W��
					{
						arrow[0] = ' ';
						arrow[pp->backpack_slot_limit] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//���N���}�F
				}
			}
		}
		if (option == 80)//���U
		{
			for (int i = 0; i < pp->backpack_slot_limit + 1; i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == pp->backpack_slot_limit)//�b�̤U��
					{
						arrow[pp->backpack_slot_limit] = ' ';
						arrow[0] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i + 1] = '>';
					}
					break;//���N���}�F
				}
			}
		}
		for (int i = 0; i < pp->backpack_slot_limit + 1; i++)
		{
			if (arrow[i] == '>')//���b�Y����m
			{
				choice = i;
				break;
			}
		}
		if (option == 13)//��enter
		{
			if (choice == pp->backpack_slot_limit)
			{
				return;
			}
			if (pp->backpack[choice] != nullptr)
			{
				if (pp->backpack[choice]->type == 'c')
				{
					cout << "�ϥή��ӫ~\n";
					ConsumableItem *my_con = static_cast<ConsumableItem*>(pp->takeItem(choice));
					pp->useConsumable(my_con);
				}
				else if (pp->backpack[choice]->type == 'w')
				{
					cout << "�˳ƪZ��\n";
					WeaponItem*my_wea = static_cast<WeaponItem*>(pp->backpack[choice]);
					if (pp->equipWeapon(my_wea))
					{
						pp->takeItem(choice);
					}
				}
				else if (pp->backpack[choice]->type == 'a')
				{
					cout << "�˳ƨ���\n";
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


#include "BattleMenu.h"

BattleMenu::BattleMenu()
{
}

int BattleMenu::BattleChoice(NovicePlayer*tmp_player)
{
	char arrow[4] = { '>',' ',' ',' ' };
	cout << setw(10) << tmp_player->getName() << "���^�X\n";
	cout << arrow[0] << "����\n" << arrow[1] << "�ޯ�\n" << arrow[2] << "�I�]\n" << arrow[3] << "�k�]\n";
	char opt;
	while (true)
	{
		opt = _getch();
		if (opt == 72)//���W
		{
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 0)//�b�̤W��
					{
						arrow[0] = ' ';
						arrow[3] = '>';
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
		if (opt == 80)//���U
		{
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 3)//�b�̤U��
					{
						arrow[3] = ' ';
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
		if (opt == 13)//��enter
		{
			int choice = 0;
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					choice = i;
					break;
				}
			}
			if (choice == 0)
			{
				return 0;
			}
			else if (choice == 1)
			{
				return 1;
			}
			else if (choice == 2)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
		system("cls");
	}
}

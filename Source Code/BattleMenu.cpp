#include "BattleMenu.h"

BattleMenu::BattleMenu()
{
}

int BattleMenu::BattleChoice(NovicePlayer*tmp_player)
{
	char arrow[4] = { '>',' ',' ',' ' };
	cout << setw(10) << tmp_player->getName() << "的回合\n";
	cout << arrow[0] << "攻擊\n" << arrow[1] << "技能\n" << arrow[2] << "背包\n" << arrow[3] << "逃跑\n";
	char opt;
	while (true)
	{
		opt = _getch();
		if (opt == 72)//按上
		{
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 0)//在最上面
					{
						arrow[0] = ' ';
						arrow[3] = '>';
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
		if (opt == 80)//按下
		{
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//找到箭頭的位置
				{
					if (i == 3)//在最下面
					{
						arrow[3] = ' ';
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
		if (opt == 13)//按enter
		{
			int choice = 0;
			for (int i = 0; i < 4; i++)
			{
				if (arrow[i] == '>')//找到箭頭的位置
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

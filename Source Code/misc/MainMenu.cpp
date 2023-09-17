#include "MainMenu.h"
#include <iomanip>
MainMenu::MainMenu()
{
}

int MainMenu::GameChoice()
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
		cout << endl << endl;
		cout << "   ■■■■■■■  ■■■■■■■                      ■ ■■       ■      ■■■■■■ ■■■   ■■     \n";
		cout << "         ■              ■          ■■■■     ■■■■■    ■■■■■■ ■  ■■  ■ ■ ■   ■  ■     \n";
		cout << "         ■              ■         ■    ■■   ■     ■          ■■     ■  ■■  ■ ■■  ■  ■  ■   \n";
		cout << "         ■              ■        ■    ■  ■  ■■■  ■ ■     ■  ■      ■■■■   ■ ■ ■■  ■■  \n";
		cout << "         ■ ■■■       ■ ■■■ ■   ■   ■  ■  ■  ■■     ■    ■     ■ ■ ■   ■  ■ ■    ■      \n";  
		cout << "         ■ ■  ■       ■ ■  ■  ■ ■    ■  ■ ■  ■ ■    ■      ■    ■ ■ ■   ■■  ■■  ■■         \n";
		cout << "    ■■■  ■■■  ■■■  ■■■   ■     ■  ■     ■    ■ ■        ■   ■■■■   ■   ■  ■■  ■          \n";
		cout << endl << endl << endl <<setw(50)<< arrow[0] << "新遊戲\n" << setw(50) << arrow[1] << "繼續遊戲\n" << setw(50) << arrow[2] << "離開\n" << endl;
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
				return 0;
			}
			else if (choice == 1)
			{
				system("cls");
				return 1;
			}
			else if (choice == 2)
			{
				system("cls");
				return 2;
			}
		}
	}
}

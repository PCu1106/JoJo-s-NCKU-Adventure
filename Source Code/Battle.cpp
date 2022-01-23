#include "Battle.h"
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
Battle::Battle(NovicePlayer**play, BaseMonster**mon, int Nplay, int Nmon)
{
	ElapsedTurn = 0;
	ActionList = new Character[Nplay + Nmon];
	setCharacter(Nplay, Nmon, play, mon);
	nTurn = 0;
	turnLimit = 9999;
	nPlayer = Nplay;
	nMonster = Nmon;
	nAll = nPlayer + nMonster;
	tmp_player = static_cast<NovicePlayer*>(ActionList[0].instance);
	tmp_monster = static_cast<BaseMonster*>(ActionList[1].instance);
	run = 0;
	win = 0;
	while (nextAction())
	{
		nTurn++;
		action();
		setAlive();
	}
	system("cls");
}

Battle::Battle(NovicePlayer**play, BaseMonster**mon, int Nplay, int Nmon, int lim)
{
	ElapsedTurn = 0;
	ActionList = new Character[Nplay + Nmon];
	setCharacter(Nplay, Nmon, play, mon);
	nTurn = 0;
	turnLimit = lim;
	nPlayer = Nplay;
	nMonster = Nmon;
	nAll = nPlayer + nMonster;
	tmp_player = static_cast<NovicePlayer*>(ActionList[0].instance);
	tmp_monster = static_cast<BaseMonster*>(ActionList[1].instance);
	run = 0;
	win = 0;
	while (nextAction())
	{
		nTurn++;
		action();
		setAlive();
	}
	system("cls");
}

Battle::~Battle()
{
	delete ActionList;
}

void Battle::setCharacter(int p, int m, NovicePlayer**play, BaseMonster**mon)
{
	int n = 0;
	int i = p + m;
	int a = 0;
	int b = 0;
	while (n < i)
	{
		if (p > 0)
		{
			ActionList[n].type = 'p';
			ActionList[n].alive = true;
			ActionList[n].instance = play[a];
			//cout << "ActionList[" << n << "].type is " << ActionList[n].type << endl;
			//cout << "ActionList[" << n << "].alive is " << ActionList[n].alive << endl;
			//cout << "ActionList[" << n << "].instance is " << typeid(ActionList[n].instance).name() << endl;
			n++;
			p--;
			a++;
		}
		if (m > 0)
		{
			ActionList[n].type = 'm';
			ActionList[n].alive = true;
			ActionList[n].instance = mon[b];
			//cout << "ActionList[" << n << "].type is " << ActionList[n].type << endl;
			//cout << "ActionList[" << n << "].alive is " << ActionList[n].alive << endl;
			//cout << "ActionList[" << n << "].instance is " << typeid(ActionList[n].instance).name() << endl;
			tmp_monster = static_cast<BaseMonster*>(ActionList[n].instance);
			//cout << "ActionList[" << n << "].instance->name is " << tmp_monster->getHP() << endl;
			n++;
			m--;
			b++;
		}
	}
}

bool Battle::nextAction()
{
	//cout << "nextAction\n";
	if (getPlayerCount(true) == 0)
	{
		cout << "�j�a���������F\n";
		system("pause");
		system("cls");
		cout << "GAME OVER\n";
		system("pause");
		return false;
	}
	else if (getTurnCount() >= getTurnLimit())
	{
		cout << "�^�X�w�F�W��\n";
		system("pause");
		return false;
	}
	else if (getMonsterCount(true) == 0)
	{
		cout << "Ĺ�F\n";
		win = 1;
		system("pause");
		bonus();
		return false;
	}
	else if (run == 1)
	{
		cout << "�k�]���\\n";
		system("pause");
		return false;
	}
	else
	{
		return true;
	}
}

int Battle::getTurnCount() const
{
	return nTurn;
}

int Battle::getTurnLimit() const
{
	return turnLimit;
}

int Battle::getPlayerCount() const
{
	return nPlayer;
}

int Battle::getNAll() const
{
	return nAll;
}

int Battle::getPlayerCount(bool b) const
{
	int n = 0;
	for (int i = 0; i < nPlayer + nMonster; i++)
	{
		//cout << "ActionList[" << i << "].type = " << ActionList[i].type << endl << "ActionList[" << i << "].alive = " << ActionList[i].alive << endl;
		if (ActionList[i].type == 'p'&&ActionList[i].alive == b)//�O���a�B�s��/���`
		{
			n++;
		}
	}
	//cout << "alive = " << n << endl;
	return n;
}

int Battle::getMonsterCount() const
{
	return nMonster;
}

int Battle::getMonsterCount(bool b) const
{
	int n = 0;
	for (int i = 0; i < nPlayer + nMonster; i++)
	{
		if (ActionList[i].type == 'm'&&ActionList[i].alive == b)//�O�ĤH�B�s��/���`
		{
			n++;
		}
	}
	return n;
}

/*Character Battle::getCurrentActor()
{
	Character c;
	if (ActionList[(getTurnCount() - 1) % 4].type == 'p')
	{
		c.type = ActionList[(getTurnCount() - 1) % 4].type;
		c.alive = ActionList[(getTurnCount() - 1) % 4].alive;
		c.instance = static_cast<NovicePlayer*>(ActionList[(getTurnCount() - 1) % 4].instance);
	}
	if (ActionList[(getTurnCount() - 1) % 4].type == 'm')
	{
		c.type = ActionList[(getTurnCount() - 1) % 4].type;
		c.alive = ActionList[(getTurnCount() - 1) % 4].alive;
		c.instance = static_cast<BaseMonster*>(ActionList[(getTurnCount() - 1) % 4].instance);
	}
	return c;
}*/


Character * Battle::getPlayers()
{
	Character* c = new Character[nPlayer];
	int n = 0;
	for (int i = 0; i < nPlayer + nMonster; i++)
	{
		if (ActionList[i].type == 'p')//�O���a�N��i��
		{
			c[n].type = ActionList[i].type;
			c[n].alive = ActionList[i].alive;
			c[n].instance = ActionList[i].instance;
			n++;
		}
	}
	return c;
}

Character * Battle::getMonsters()
{
	Character* c = new Character[nMonster];
	int n = 0;
	for (int i = 0; i < nPlayer + nMonster; i++)
	{
		if (ActionList[i].type == 'm')//�O�ĤH�N��i��
		{
			c[n].type = ActionList[i].type;
			c[n].alive = ActionList[i].alive;
			c[n].instance = ActionList[i].instance;
			n++;
		}
	}
	return c;
}

void Battle::printchar()
{
	//cout << "getMonsterCount() = " << getMonsterCount() << endl;
	cout << "Turn " << getTurnCount() << "/" << getTurnLimit() << endl;
	cout << "===============================================================================================\n";
	for (int i = 0; i < getMonsterCount(); i++)
	{
		cout << "Monster" << i + 1 << "�G";
		tmp_monster = static_cast<BaseMonster*>(getMonsters()[i].instance);
		cout << setw(12) << tmp_monster->name << setw(12) << "HP�G" << tmp_monster->getHP() << "/" << tmp_monster->max_hp << setw(12) << "MP�G" << tmp_monster->getMP() << "/" << tmp_monster->max_mp ;
		cout << setw(12) << "ATK�G" << tmp_monster->attack << setw(12) << "DEF�G" << tmp_monster->defense << endl;
	}
	cout << "-----------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < getPlayerCount(); i++)
	{
		tmp_player = static_cast<NovicePlayer*>(getPlayers()[i].instance);
		cout << "Lv" << tmp_player->getLevel() << tmp_player->getWork() << "�G";
		cout << setw(12) << tmp_player->getName() << setw(12) << "HP�G" << tmp_player->getHp() << "/" << tmp_player->getMaxHP() << setw(12) << "MP�G" << tmp_player->getMp() << "/" << tmp_player->getMaxMP();
		cout << setw(12) << "ATK�G" << tmp_player->getAttack() << setw(12) << "DEF�G" << tmp_player->getDefense() << endl;
	}
	cout << "===============================================================================================\n";
}

void Battle::action()
{
	printchar();//�����T
	//�M�w�ثe��ʪ��O�Hor��
	if (ActionList[(getTurnCount() - 1) % getNAll()].type == 'p')//�H
	{
		tmp_player = static_cast<NovicePlayer*>(ActionList[(getTurnCount() - 1) % getNAll()].instance);
		if (ActionList[(getTurnCount() - 1) % getNAll()].alive == false)
		{
			cout << tmp_player->getName() << "���F�A�L�k���\n";
			system("pause");
			system("cls");
			return;
		}
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
					attack(tmp_player);
					break;
				}
				else if (choice == 1)
				{
					skill(tmp_player);
					break;
				}
				else if (choice == 2)
				{
					item(tmp_player);
					break;
				}
				else
				{
					escape();
					break;
				}
			}
			system("cls");
			printchar();//�����T
			tmp_player = static_cast<NovicePlayer*>(ActionList[(getTurnCount() - 1) % getNAll()].instance);
			cout << setw(10) << tmp_player->getName() << "���^�X\n";
			cout << arrow[0] << "����\n" << arrow[1] << "�ޯ�\n" << arrow[2] << "�I�]\n" << arrow[3] << "�k�]\n";
		}
	}
	else if (ActionList[(getTurnCount() - 1) % getNAll()].type == 'm')//��
	{
		tmp_monster = static_cast<BaseMonster*>(ActionList[(getTurnCount() - 1) % getNAll()].instance);
		//�Ǫ������
		if (ActionList[(getTurnCount() - 1) % getNAll()].alive == false)
		{
			cout << tmp_monster->name << "���F�A�L�k���\n";
			system("pause");
			system("cls");
			return;
		}
		srand(time(0));
		int who = rand() % getPlayerCount();//�����ؼ�
		tmp_player = static_cast<NovicePlayer*>(getPlayers()[who].instance);
		cout << tmp_monster->name << "�����F" << tmp_player->getName() << endl;
		if (getPlayers()[who].alive == false)
		{
			cout << tmp_monster->name << "�n���������F\n";
		}
		else if (tmp_monster->attack - tmp_player->getDefense() <= 0)
		{
			cout << "���G�L�k�y���ˮ`\n";
		}
		else
		{
			tmp_player->setHp(tmp_player->getHp() - (tmp_monster->attack - tmp_player->getDefense()));//����
			cout << tmp_player->getName() << "����F" << (tmp_monster->attack - tmp_player->getDefense()) << "�I�ˮ`\n";
		}
		system("pause");
		system("cls");
		return;
	}
	system("cls");
}
void Battle::attack(NovicePlayer * atker)
{
	system("cls");
	printchar();//�����T
	char *arrow = new char[getMonsterCount()];
	for (int i = 0; i < getMonsterCount(); i++)
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
	for (int i = 0; i < getMonsterCount(); i++)//�L�X������H
	{
		cout << arrow[i] << "monster" << i + 1 << endl;
	}
	char who;
	while (true)
	{
		who = _getch();
		//cout << "�K�K\n";
		//cout << who << endl;
		//system("pause");
		if (who == 72)//���W
		{
			for (int i = 0; i < getMonsterCount(); i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == 0)//�b�̤W��
					{
						arrow[0] = ' ';
						arrow[getMonsterCount() - 1] = '>';
					}
					else
					{
						arrow[i] = ' ';
						arrow[i - 1] = '>';
					}
					break;//���N���}�F
				}
			}
			system("cls");
			printchar();//�����T
			for (int i = 0; i < getMonsterCount(); i++)//�L�X������H
			{
				cout << arrow[i] << "monster" << i + 1 << endl;
			}
		}
		if (who == 80)//���U
		{
			for (int i = 0; i < getMonsterCount(); i++)//�]�w�b�Y��m
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					if (i == getMonsterCount() - 1)//�b�̤U��
					{
						arrow[getMonsterCount() - 1] = ' ';
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
			system("cls");
			printchar();//�����T
			for (int i = 0; i < getMonsterCount(); i++)//�L�X������H
			{
				cout << arrow[i] << "monster" << i + 1 << endl;
			}
		}
		if (who == 13)//��enter
		{
			int choice = 0;
			for (int i = 0; i < getMonsterCount(); i++)
			{
				if (arrow[i] == '>')//���b�Y����m
				{
					choice = i;
					break;
				}
			}
			tmp_monster = static_cast<BaseMonster*>(getMonsters()[choice].instance);
			cout << atker->getName() << "�����F" << tmp_monster->name << endl;
			if (getMonsters()[choice].alive == false)
			{
				cout << atker->getName() << "���M�@�͡A�u�O�c���\n";
			}
			else if (atker->getAttack() - tmp_monster->defense <= 0)
			{
				cout << "���G�L�k�y���ˮ`\n";
			}
			else
			{
				tmp_monster->setHP(tmp_monster->getHP() - (atker->getAttack() - tmp_monster->defense));//����
				cout << tmp_monster->name << "����F" << (atker->getAttack() - tmp_monster->defense) << "�I�ˮ`\n";
			}
			system("pause");
			system("cls");
			return;
		}
	}
	return;
}

void Battle::skill(NovicePlayer *user)
{
	system("cls");
	printchar();//�����T
	cout << user->getName() << "�ϥX�F";
	user->specialSkill();
	system("pause");
	system("cls");
	return;
}

void Battle::item(NovicePlayer * p)
{
	cout << "�I�]\n";
	lookbackpack(p);
	system("pause");
	system("cls");
	return;
}

void Battle::escape()
{
	int r = rand() % 2;
	if (r == 1)
	{
		run = 1;
	}
	else
	{
		cout << "�k�]����\n";
	}
	system("pause");
	system("cls");
	return;
}

void Battle::setAlive()//��b�C����action��
{
	for (int i = 0; i < getPlayerCount() + getMonsterCount(); i++)
	{
		if (ActionList[i].type == 'p')
		{
			tmp_player = static_cast<NovicePlayer*>(ActionList[i].instance);
			if (tmp_player->getHp() <= 0)
			{
				ActionList[i].alive = false;
			}
		}
		if (ActionList[i].type == 'm')
		{
			tmp_monster = static_cast<BaseMonster*>(ActionList[i].instance);
			if (tmp_monster->getHP() <= 0)
			{
				ActionList[i].alive = false;
			}
		}
	}
}

void Battle::bonus()
{
	int winexp = 0;
	int winmoney = 0;
	for (int i = 0; i < getMonsterCount(); i++)
	{
		tmp_monster = static_cast<BaseMonster*>(getMonsters()[i].instance);
		winexp += tmp_monster->exp;
		winmoney += tmp_monster->money;
	}
	for (int i = 0; i < getPlayerCount(); i++)
	{
		tmp_player = static_cast<NovicePlayer*>(getPlayers()[i].instance);
		tmp_player->setExp(tmp_player->getExp()+winexp);
		tmp_player->setMoney(tmp_player->getMoney() + winmoney);
	}
	cout << "�j�a��o�F�g���" << winexp << endl;
	cout << "�j�a��o�F����" << winmoney << endl;
	system("pause");
}

void Battle::lookbackpack(NovicePlayer*pp)
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
			if (pp->backpack[choice] != nullptr)
			{
				if (choice == pp->backpack_slot_limit)
				{
					return;
				}
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
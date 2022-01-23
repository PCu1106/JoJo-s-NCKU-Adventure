#include "NovicePlayer.h"
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void NovicePlayer::setName(string namae) 
{
	name = namae;
}

string NovicePlayer::getName() const
{
	return name;
}

void NovicePlayer::setLevel(int lv)
{
	level = lv;
	max_hp = 100 + 10 * lv;
	max_mp = 40 + 5 * lv;
	attack = 20 + 5 * lv;
	defense = 20 + 5 * lv;
	lvup_exp = ceil(pow(10, (log(lv + 1) / log(2))));
	backpack_weight_limit = 2 + 8 * lv;
	backpack_slot_limit = lv;
	backpack = new Item*[backpack_slot_limit];
	
	//cout << lvup_exp;
	//cout << "novice set\n";
}

int NovicePlayer::getLevel(void) const
{
	return level;
}

NovicePlayer::NovicePlayer()// default constructor
{
	setName("anonymous");
	setLevel(1);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("��ߪ�");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

NovicePlayer::NovicePlayer(int lv)// normal constructor
{
	setName("anonymous");
	setLevel(lv);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("��ߪ�");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

NovicePlayer::NovicePlayer(int lv, string namae)// normal constructor
{
	setName(namae);
	setLevel(lv);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("��ߪ�");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

NovicePlayer::NovicePlayer(const NovicePlayer &p)// copy constructor
{
	setName(p.name);
	setLevel(p.level);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("��ߪ�");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

void NovicePlayer::setHp(int h)//[0, max_hp]
{
	if (h > max_hp)

	{
		hp = max_hp;
	}
	else if (h < 0)
	{
		hp = 0;
	}
	else
	{
		hp = h;
	}
}

int NovicePlayer::getHp(void) const
{
	return hp;
}

void NovicePlayer::setMp(int m)//[0, max_mp]
{
	if (m > max_mp)
	{
		mp = max_mp;
	}
	else if (m < 0)
	{
		mp = 0;
	}
	else
	{
		mp = m;
	}
}

int NovicePlayer::getMp(void) const
{
	return mp;
}

void NovicePlayer::setExp(int e)//>=0
{
	if (e > lvup_exp)//�ɵ�
	{
		exp = e;
		setLevel(getLevel()+1);
		setExp(e);
	}
	else if (e < 0)
	{
		exp = 0;
	}
	else
	{
		exp = e;
	}
}

int NovicePlayer::getExp(void) const
{
	return exp;
}

void NovicePlayer::setMoney(int m)//>=0
{
	if (m < 0)
	{
		money = 0;
	}
	else
	{
		money = m;
	}
}

int NovicePlayer::getMoney(void) const
{
	return money;
}

int NovicePlayer::getAttack(void) const
{
	return attack;
}

int NovicePlayer::getDefense(void) const
{
	return defense;
}

int NovicePlayer::getMaxHP(void) const
{
	return max_hp;
}

int NovicePlayer::getMaxMP(void) const
{
	return max_mp;
}

int NovicePlayer::getLvupExp(void) const
{
	return lvup_exp;
}

void NovicePlayer::specialSkill()
{
	cout << "�s��\n";
	system("pause");
	cout << "�n���S�����\n";
	return;
}

string NovicePlayer::serialize()
{
	//cout << "NovicePlayer::serialize()\n";
	string a;
	a.push_back('a');//����N��
	a.push_back(',');
	for (int i = 0; i < getName().size(); i++)
	{
		a.push_back(getName()[i]);
	}
	a.push_back(',');
	stringstream ll;
	ll << getLevel();
	string l = ll.str();//int �� string
	for (int i = 0; i < l.size(); i++)
	{
		a.push_back(l[i]);
	}
	a.push_back(',');
	stringstream hh;
	hh << getHp();
	string h = hh.str();//int �� string
	for (int i = 0; i < h.size(); i++)
	{
		a.push_back(h[i]);
	}
	a.push_back(',');
	stringstream mm;
	mm << getMp();
	string m = mm.str();
	for (int i = 0; i < m.size(); i++)
	{
		a.push_back(m[i]);
	}
	a.push_back(',');
	stringstream ee;
	ee << getExp();
	string e = ee.str();
	for (int i = 0; i < e.size(); i++)
	{
		a.push_back(e[i]);
	}
	a.push_back(',');
	stringstream momo;
	momo << getMoney();
	string mo = momo.str();
	for (int i = 0; i < mo.size(); i++)
	{
		a.push_back(mo[i]);
	}
	a.push_back(',');
	if (weapon != nullptr)
	{
		stringstream nn;
		nn << weapon->No;
		string nnn = nn.str();
		for (int i = 0; i < nnn.size(); i++)
		{
			a.push_back(nnn[i]);
		}
	}
	else
	{
		a.push_back('0');//�S�F��
	}
	a.push_back(',');
	if (armor != nullptr)
	{
		stringstream aa;
		aa << armor->No;
		string aaa = aa.str();
		for (int i = 0; i < aaa.size(); i++)
		{
			a.push_back(aaa[i]);
		}
	}
	else
	{
		a.push_back('0');//�S�F��
	}
	a.push_back(',');
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		if (backpack[i] != nullptr)
		{
			stringstream bb;
			bb << backpack[i]->No;
			string bbb = bb.str();
			for (int i = 0; i < bbb.size(); i++)
			{
				a.push_back(bbb[i]);
			}
		}
		else
		{
			a.push_back('0');//�S�F��
		}
		a.push_back(',');
	}
	a.push_back('\n');
	return a;
}

NovicePlayer * NovicePlayer::unserialize(string a)
{
	//cout << "NovicePlayer::unserialize(string a)\n";
	string namae;
	int i = 2;//���L����N��
	while (a[i] != ',')
	{
		namae.push_back(a[i]);
		i++;
	}
	i++;
	int lv = 0;
	while (a[i] != ',')
	{
		lv = lv *10 + (a[i] - 48);
		i++;
	}
	i++;
	int h = 0;
	while (a[i] != ',')
	{
		h = h * 10 + (a[i] - 48);
		i++;
	}
	i++;
	int m = 0;
	while (a[i] != ',')
	{
		m = m *10 + (a[i] - 48);
		i++;
	}
	i++;
	int ex = 0;
	while (a[i] != ',')
	{
		ex = ex * 10 + (a[i] - 48);
		i++;
	}
	i++;
	int mon = 0;
	while (a[i] != ',')
	{
		mon = mon *10 + (a[i] - 48);
		i++;
	}
	
	//cout << lv << endl << h << endl << m << endl << ex << endl << mon;
	NovicePlayer *p = new NovicePlayer();
	p->setName(namae);
	p->setLevel(lv);
	p->setHp(h);
	p->setMp(m);
	p->setExp(ex);
	p->setMoney(mon); 
	int ww = 0;
	while (a[i] != ',')
	{
		ww = ww * 10 + (a[i] - 48);
		i++;
	}
	/*if (ww == 1)
	{
		WeaponItem *ws = new SwordWeapon;
		p->equipWeapon(ws);
	}
	if (ww == 2)
	{
		WeaponItem *we = new ExcaliburWeapon;
		p->equipWeapon(we);
	}
	if (ww == 3)
	{
		WeaponItem *wn = new NeoArmstrongWeapon;
		p->equipWeapon(wn);
	}*/
	int aa = 0;
	while (a[i] != ',')
	{
		aa = aa * 10 + (a[i] - 48);
		i++;
	}
	for (int i = 0; i < lv; i++)
	{

		while (a[i] != ',')
		{
			aa = aa * 10 + (a[i] - 48);
			i++;
		}
	}
	////�Ȯɪ�
	p->weapon = nullptr;
	p->armor = nullptr;
	for (int i = 0; i < lv; i++)
	{
		p->backpack[i] = nullptr;
	}
	return p;
}

void NovicePlayer::setWork(string w)
{
	work = w;
}

string NovicePlayer::getWork()
{
	return work;
}

bool NovicePlayer::putItem(Item * it)
{
	if (occupied_slot + 1 <= backpack_slot_limit && backpack_weight+it->weight<=backpack_weight_limit)//�e�q�t������
	{
		for (int i = 0; i < backpack_slot_limit; i++)
		{
			if (backpack[i] == nullptr)
			{
				backpack[i] = it;
				occupied_slot++;
				backpack_weight += it->weight;
				cout << getName() << "�N" << it->name << "��i�F�I�]\n";
				break;//��n�N���}
			}
		}
		return true;
	}
	else
	{
		if (occupied_slot + 1 > backpack_slot_limit)
		{
			cout << "�e�q�w��\n";
		}
		if (backpack_weight + it->weight > backpack_weight_limit)
		{
			cout << "�W�X�t��\n";
		}
		return false;
	}
}

Item * NovicePlayer::takeItem(int n)
{
	Item *it = backpack[n];
	backpack[n] = nullptr; 
	occupied_slot--;
	backpack_weight -= it->weight;
	return it;
}

bool NovicePlayer::equipWeapon(WeaponItem *w)
{
	if (level < w->level_required)
	{
		cout << "���Ť����A�L�k�˳�\n";
		system("pause");
		return false;
	}
	else if (weapon == nullptr)
	{
		cout << getName() << "�˳ƤF" << w->name << endl;
		weapon = w;
	}
	else if (weapon != nullptr)
	{
		cout << getName() << "�N" << weapon->name << "���^�I�]" << endl;

		attack -= weapon->attack_increment;
		cout << "ATK��_��" << attack << endl;
		//putItem(weapon);//dynamic_cast<Item*>(weapon)
		cout << getName() << "�˳ƤF" << w->name << endl;
		Item *myit = static_cast<Item*>(weapon);
		putItem(myit);
		weapon = w;
	}
	attack += w->attack_increment;
	cout << "ATK���ɤF" << w->attack_increment << endl;
	cout << "ATK�ܦ�" << attack << endl;
	system("pause");
	return true;
}

bool NovicePlayer::equipArmor(ArmorItem *a)
{
	if (level < a->level_required)
	{
		cout << "���Ť����A�L�k�˳�\n";
		system("pause");
		return false;
	}
	else if (armor == nullptr)
	{
		cout << getName() << "�˳ƤF" << a->name << endl;
		armor = a;
	}
	else if (armor != nullptr)
	{
		cout << getName() << "�N" << armor->name << "���^�I�]" << endl;
		defense -= armor->defense_increment;
		cout << "DEF��_��" << defense << endl;
		cout << getName() << "�˳ƤF" << a->name << endl;
		Item *myit = static_cast<Item*>(armor);
		putItem(myit);
		armor = a;
	}
	defense += a->defense_increment;
	cout << "DEF���ɤF" << a->defense_increment << endl;
	cout << "DEF�ܦ�" << defense << endl;
	system("pause");
	return true;
}

void NovicePlayer::useConsumable(ConsumableItem * c)
{
	NovicePlayer *p = this;
	c->use(p);
}





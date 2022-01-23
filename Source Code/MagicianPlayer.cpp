#include "MagicianPlayer.h"

MagicianPlayer::MagicianPlayer()
{
	setName("anonymous");
	setLevel(1);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("法師");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

MagicianPlayer::MagicianPlayer(int lv)
{
	setName("anonymous");
	setLevel(lv);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("法師");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

MagicianPlayer::MagicianPlayer(int lv, string namae)
{
	setName(namae);
	setLevel(lv);
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("法師");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

MagicianPlayer::MagicianPlayer(const MagicianPlayer &p)
{
	setName(p.getName());
	setLevel(p.getLevel());
	setHp(max_hp);
	setMp(max_mp);
	setExp(0);
	setMoney(0);
	setWork("法師");
	backpack_weight = 0;
	for (int i = 0; i < backpack_slot_limit; i++)
	{
		backpack[i] = nullptr;
	}
	weapon = nullptr;
	armor = nullptr;
}

void MagicianPlayer::setLevel(int lv)
{
	level = lv;
	max_hp = 120 + 15 * lv;
	max_mp = 100 + 15 * lv;
	attack = 30 + 8 * lv;
	defense = 20 + 7 * lv;
	lvup_exp = ceil(pow(10, (log(lv + 1) / log(2))));
	backpack_weight_limit = 6 + 9 * lv;
	backpack_slot_limit = lv;
	backpack = new Item*[backpack_slot_limit];
}

void MagicianPlayer::specialSkill(void)
{
	cout << "靈魂獻祭\n";
	if (getHp() - getLevel() * 5 > 0)
	{
		setMp(getMp() + getLevel() * 10);
		setHp(getHp() - getLevel() * 5);
		cout << "HP-" << getLevel() * 5 << endl;
		cout << "MP+" << getLevel() * 10 << endl;
	}
	else
	{
		cout << "HP不夠\n";
	}
}

string MagicianPlayer::serialize()
{
	//cout << "MagicianPlayer::serialize()\n";
	string a;
	a.push_back('d');//角色代號
	a.push_back(',');
	for (int i = 0; i < getName().size(); i++)
	{
		a.push_back(getName()[i]);
	}
	a.push_back(',');
	stringstream ll;
	ll << getLevel();
	string l = ll.str();//int 轉 string
	for (int i = 0; i < l.size(); i++)
	{
		a.push_back(l[i]);
	}
	a.push_back(',');
	stringstream hh;
	hh << getHp();
	string h = hh.str();//int 轉 string
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
	a.push_back('\n');
	return a;
}

NovicePlayer * MagicianPlayer::unserialize(string a)
{
	//cout << "MagicianPlayer::unserialize(string a)\n";
	string namae;
	int i = 2;//跳過角色代號
	while (a[i] != ',')
	{
		namae.push_back(a[i]);
		i++;
	}
	i++;
	int lv = 0;
	while (a[i] != ',')
	{
		lv = lv * 10 + (a[i] - 48);
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
		m = m * 10 + (a[i] - 48);
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
		mon = mon * 10 + (a[i] - 48);
		i++;
	}
	//cout << lv << endl << h << endl << m << endl << ex << endl << mon;
	NovicePlayer *p = new MagicianPlayer();
	p->setName(namae);
	p->setLevel(lv);
	p->setHp(h);
	p->setMp(m);
	p->setExp(ex);
	p->setMoney(mon); 
	p->weapon = nullptr;
	p->armor = nullptr;
	for (int i = 0; i < lv; i++)
	{
		p->backpack[i] = nullptr;
	}
	return p;
}

#include "ZombieMonster.h"

ZombieMonster::ZombieMonster()
	:BaseMonster("Zombie", 50, 65, 17, 65, 150, 30)
{
}

ZombieMonster::~ZombieMonster()
{
	cout << "~ZombieMonster()";
}

string ZombieMonster::serialize()
{
	//cout << "ZombieMonster::serialize()\n";
	string a;
	a.push_back('y');//角色代號
	a.push_back(',');
	for (int i = 0; i < name.size(); i++)
	{
		a.push_back(name[i]);
	}
	a.push_back(',');
	stringstream hh;
	int hhh = getHP();
	hh << hhh;
	string h = hh.str();//int 轉 string
	for (int i = 0; i < h.size(); i++)
	{
		a.push_back(h[i]);
	}
	a.push_back(',');
	stringstream mm;
	int mmm = getMP();
	mm << mmm;
	string m = mm.str();
	for (int i = 0; i < m.size(); i++)
	{
		a.push_back(m[i]);
	}
	a.push_back(',');
	return a;
}

BaseMonster * ZombieMonster::unserialize(string a)
{
	//cout << "ZombieMonster::unserialize(string a)\n";
	string namae;
	int i = 2;//跳過角色代號
	while (a[i] != ',')
	{
		namae.push_back(a[i]);
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
	BaseMonster *p = new ZombieMonster();
	p->setHP(h);
	p->setMP(m);
	//cout << endl << h << endl << m << endl ;
	return p;
}





#include "GoblinMonster.h"

GoblinMonster::GoblinMonster()
	:BaseMonster("Goblin",60,40,12,30,100,50)
{
}

GoblinMonster::~GoblinMonster()
{
	cout << "~GoblinMonster()";
}

string GoblinMonster::serialize()
{
	//cout << "GoblinMonster::serialize()\n";
	string a;
	a.push_back('z');//角色代號
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

BaseMonster * GoblinMonster::unserialize(string a)
{
	//cout << "GoblinMonster::unserialize(string a)\n";
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
	BaseMonster *p = new GoblinMonster();
	p->setHP(h);
	p->setMP(m);
	//cout << endl << h << endl << m << endl ;
	return p;
}





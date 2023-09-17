#include "BaseMonster.h"

int BaseMonster::count = 0;
BaseMonster::BaseMonster(string namae, int atk, int def, int e, int mon, int mhp, int mmp)
	:name(namae),attack(atk),defense(def),exp(e),money(mon),max_hp(mhp),max_mp(mmp)
{
	count++;
	setHP(mhp);
	setMP(mmp);
}

BaseMonster::~BaseMonster()
{
	cout << "\n~BaseMonster()\n";
	count--;
}

void BaseMonster::setHP(int h)
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

int BaseMonster::getHP() const
{
	return hp;
}

void BaseMonster::setMP(int m)
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

int BaseMonster::getMP() const
{
	return mp;
}



int BaseMonster::getInstanceCount(void)
{
	return count;
}



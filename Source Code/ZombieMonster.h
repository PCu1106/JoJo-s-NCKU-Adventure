#ifndef ZombieMonster_H
#define ZombieMonster_H
#include"BaseMonster.h"
class ZombieMonster :public BaseMonster
{
public:
	ZombieMonster();
	virtual ~ZombieMonster();
	virtual string serialize();
	static BaseMonster* unserialize(string);
};
#endif
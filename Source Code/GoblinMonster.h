#ifndef GoblinMonster_H
#define GoblinMonster_H
#include"BaseMonster.h"
class GoblinMonster :public BaseMonster
{
public:
	GoblinMonster();
	virtual ~GoblinMonster();
	virtual string serialize();
	static BaseMonster* unserialize(string);
};
#endif


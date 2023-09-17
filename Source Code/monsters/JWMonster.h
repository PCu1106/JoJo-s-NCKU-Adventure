#ifndef JWMonster_H
#define JWMonster_H
#include"BaseMonster.h"
class JWMonster :public BaseMonster
{
public:
	JWMonster();
	virtual ~JWMonster();
	virtual string serialize();
	static BaseMonster* unserialize(string);
};
#endif



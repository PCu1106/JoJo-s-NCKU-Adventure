#ifndef KnightPlayer_H
#define KnightPlayer_H
#include"NovicePlayer.h"
class KnightPlayer :public NovicePlayer
{
public:
	KnightPlayer();// default constructor
	KnightPlayer(int);// normal constructor
	KnightPlayer(int, string);// normal constructor
	KnightPlayer(const KnightPlayer&);//copy constructor
	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};
#endif

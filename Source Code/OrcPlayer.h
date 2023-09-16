#ifndef OrcPlayer_H
#define OrcPlayer_H
#include"NovicePlayer.h"
class OrcPlayer :public NovicePlayer
{
public:
	OrcPlayer();// default constructor
	OrcPlayer(int);// normal constructor
	OrcPlayer(int, string);// normal constructor
	OrcPlayer(const OrcPlayer&);//copy constructor
	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	//static NovicePlayer* unserialize(string);
};
#endif
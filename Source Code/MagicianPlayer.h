#ifndef MagicianPlayer_H
#define MagicianPlayer_H
#include"NovicePlayer.h"
class MagicianPlayer :public NovicePlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	virtual void setLevel(int);
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};
#endif


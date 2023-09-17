#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H
#include"NovicePlayer.h"
#include "Orcplayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
class PlayerFactory {
public:
	static NovicePlayer* createPlayer(char career);
};


#endif

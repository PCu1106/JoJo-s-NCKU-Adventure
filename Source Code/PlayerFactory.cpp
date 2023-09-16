#include "PlayerFactory.h"

NovicePlayer* PlayerFactory::createPlayer(char career) {
	switch (career) {
		case 'b':
			return new OrcPlayer();
		case 'c':
			return new KnightPlayer();
		case 'd':
			return new MagicianPlayer();
		default:
			return new NovicePlayer();
	}
}
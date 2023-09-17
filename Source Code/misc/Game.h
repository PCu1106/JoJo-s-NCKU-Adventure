#ifndef GAME_H
#define GAME_H
#include "NovicePlayer.h"
#include "Orcplayer.h"
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
#include "BaseMonster.h"
#include "GoblinMonster.h"
#include "ZombieMonster.h"
#include "JWMonster.h"
#include "Battle.h"
#include "Field.h"
#include "Item.h"
#include "WeaponItem.h"
#include "SwordWeapon.h"
#include "ArmorItem.h"
#include "TunicArmor.h"
#include "ConsumableItem.h"
#include "LifePotion.h"
#include "ExcaliburWeapon.h"
#include "YataNoKagamiArmor.h"
#include "MagicPotion.h"
#include "NeoArmstrongWeapon.h"
#include "MainMenu.h"
#include "Event.h"
#include "Menu.h"
#include "FieldMenu.h"
#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Game
{
public:
	NovicePlayer**Playlist=new NovicePlayer*[5];//³Ì¦h5¤H
	int** MyMap;
	int MyMapHeight;
	int MyMapWidth;
	int PositionX;
	int PositionY;
	int CurrentPlayer;
	Game();
	Field *AllField = new Field[5];
	void run();
	//void menu(NovicePlayer**, int);
	void move(Field&);
	void Serialize();
	int whichmap;
	Event e;
};
#endif
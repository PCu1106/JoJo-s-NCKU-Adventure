#ifndef Event_H
#define Event_H
#include<iostream>
#include<string>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include"NovicePlayer.h"
#include "Orcplayer.h"
#include"KnightPlayer.h"
#include"MagicianPlayer.h"
#include"BaseMonster.h"
#include"GoblinMonster.h"
#include"ZombieMonster.h"
#include"JWMonster.h"
#include"Battle.h"
#include"Field.h"
#include"Item.h"
#include"WeaponItem.h"
#include"SwordWeapon.h"
#include"ArmorItem.h"
#include"TunicArmor.h"
#include"ConsumableItem.h"
#include"LifePotion.h"
#include"ExcaliburWeapon.h"
#include"YataNoKagamiArmor.h"
#include"MagicPotion.h"
#include"NeoArmstrongWeapon.h"
using namespace std;
class Event
{
public:
	Event();
	int happen[1000];//事件發生過=1
	void Event0();//開場
	void Event250();//喬瑟夫
	void Event251();//阿布德爾
	void Event252();//花京院典明
	void Event253();//波魯納雷夫
	void Event300(NovicePlayer **);//商人
	void Event900(NovicePlayer**, int);//小怪戰
	void Event901(NovicePlayer**, int);//仁暐戰
	void EventPlace(int);

};
#endif

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
	int happen[1000];//�ƥ�o�͹L=1
	void Event0();//�}��
	void Event250();//����
	void Event251();//�����w��
	void Event252();//��ʰ|���
	void Event253();//�i�|�ǹp��
	void Event300(NovicePlayer **);//�ӤH
	void Event900(NovicePlayer**, int);//�p�Ǿ�
	void Event901(NovicePlayer**, int);//���¾�
	void EventPlace(int);

};
#endif

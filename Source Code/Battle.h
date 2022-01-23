#ifndef Battle_H
#define Battle_H
#include<iostream>
#include "NovicePlayer.h"
#include "BaseMonster.h"
#include "BattleMenu.h"
#include<string>
using namespace std;
struct Character
{
	char type; // monster or player?	
	bool alive; // alive or dead?	
	void *instance; // pointer to instance
};
class Battle
{
private:
	Character *ActionList;
	int nTurn;
	int turnLimit;
	int nPlayer;
	int nMonster;
	int nAll;
	NovicePlayer *tmp_player;
	BaseMonster *tmp_monster;
	int ElapsedTurn;
	int run;
public:
	Battle(NovicePlayer**, BaseMonster**, int, int);//(NovicePlayer*�}�C,BaseMonster*�}�C,���a�ƶq,�ĤH�ƶq)
	Battle(NovicePlayer**, BaseMonster**, int, int, int);//(NovicePlayer*�}�C,BaseMonster*�}�C,���a�ƶq,�ĤH�ƶq,�^�X����)
	~Battle();
	void setCharacter(int, int, NovicePlayer**, BaseMonster**);


	bool nextAction();

	int getTurnCount()const;
	int getTurnLimit()const;
	int getPlayerCount()const;
	int getNAll()const;
	int getPlayerCount(bool)const;//�Ǧ^�s��/���`�H��
	int getMonsterCount()const;
	int getMonsterCount(bool)const;//�Ǧ^�s��/���`�ĤH
	//Character getCurrentActor();
	Character* getPlayers();//���a�}�C
	Character* getMonsters();//�ĤH�}�C
	void printchar();
	void action();
	void attack(NovicePlayer *);
	void skill(NovicePlayer *);
	void item(NovicePlayer *);
	void escape();
	void setAlive();
	void bonus();
	int win;
	void lookbackpack(NovicePlayer*);
};
#endif

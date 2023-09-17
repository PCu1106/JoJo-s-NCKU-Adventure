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
	char type;
	bool alive;
	void *instance;
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
	Battle(NovicePlayer**, BaseMonster**, int, int);
	Battle(NovicePlayer**, BaseMonster**, int, int, int);
	~Battle();
	void setCharacter(int, int, NovicePlayer**, BaseMonster**);


	bool nextAction();

	int getTurnCount()const;
	int getTurnLimit()const;
	int getPlayerCount()const;
	int getNAll()const;
	int getPlayerCount(bool)const;
	int getMonsterCount()const;
	int getMonsterCount(bool)const;
	//Character getCurrentActor();
	Character* getPlayers();
	Character* getMonsters();
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

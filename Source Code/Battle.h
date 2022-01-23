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
	Battle(NovicePlayer**, BaseMonster**, int, int);//(NovicePlayer*陣列,BaseMonster*陣列,玩家數量,敵人數量)
	Battle(NovicePlayer**, BaseMonster**, int, int, int);//(NovicePlayer*陣列,BaseMonster*陣列,玩家數量,敵人數量,回合限制)
	~Battle();
	void setCharacter(int, int, NovicePlayer**, BaseMonster**);


	bool nextAction();

	int getTurnCount()const;
	int getTurnLimit()const;
	int getPlayerCount()const;
	int getNAll()const;
	int getPlayerCount(bool)const;//傳回存活/死亡人數
	int getMonsterCount()const;
	int getMonsterCount(bool)const;//傳回存活/死亡敵人
	//Character getCurrentActor();
	Character* getPlayers();//玩家陣列
	Character* getMonsters();//敵人陣列
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

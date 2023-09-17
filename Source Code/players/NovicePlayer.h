#ifndef NovicePlayer_H
#define NovicePlayer_H
#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
#include"Item.h"
#include"WeaponItem.h"
#include"ArmorItem.h"
#include"ConsumableItem.h"
using namespace std;
class ConsumableItem;
class NovicePlayer
{
private:
	string name; // Name of the player
	int hp; // Current HP of the player, range: [0, max_hp]
	int mp; // Current MP of the player, range: [0, max_mp]
	int exp; // Cumulative experience of the player, >= 0
							   // Will not reset to zero after leveling-up
	string work;
protected:
	int level; // The level of the player, >= 1
	int attack; // Attack of the player
	int defense; // Defense of the player
	int max_hp; // Max HP of the player
	int max_mp; // Max MP of the player
	int lvup_exp; // Experience needed for leveling-up
	int money; // Current amount of money that player carries, >= 0
public:
	void setName(string);
	string getName(void) const;
	virtual void setLevel(int);
	int getLevel(void) const;
	NovicePlayer(); // default constructor
	NovicePlayer(int); // normal constructor
	NovicePlayer(int, string); // normal constructor
	NovicePlayer(const NovicePlayer&);//copy constructor
	void setHp(int);
	int getHp(void) const;
	void setMp(int);
	int getMp(void) const;
	void setExp(int);
	int getExp(void) const;
	void setMoney(int);
	int getMoney(void) const;
	int getAttack(void) const;
	int getDefense(void) const;
	int getMaxHP(void) const;
	int getMaxMP(void) const;
	int getLvupExp(void) const;
	virtual void specialSkill();
	virtual string serialize();
	static NovicePlayer* unserialize(string);
	void setWork(string);
	string getWork();
	Item** backpack; // the ¡§inventory¡¨ in many other games
	WeaponItem* weapon; // weapon item
	ArmorItem* armor; // armor item
	int backpack_weight; // current weight of player¡¦s backpack
	int backpack_weight_limit; // limit on weight of backpack
	int backpack_slot_limit; // limit on number of backpack¡¦s slots
	int occupied_slot=0;
	bool putItem(Item*);
	Item* takeItem(int);
	bool equipWeapon(WeaponItem*);
	bool equipArmor(ArmorItem*); 
	void useConsumable(ConsumableItem*);



};

#endif

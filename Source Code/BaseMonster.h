#ifndef BaseMonster_H
#define BaseMonster_H
#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;
class BaseMonster
{
private:
	int hp; // Current HP of this monster, range: [0, max_hp]
	int mp; // Current MP of this monster, range: [0, max_mp]
	static int count; // Number of instances of monster series classes
								 // Don¡¦t forget to increase/decrease it within proper places

protected:
	
public:
	const string name; // Name of the monster
	const int attack; // Attack of the monster
	const int defense; // Defense of the monster 
	const int exp; // Experience earned by players after beating this monster
	const int money; // Amount of money dropped after beating this monster
	const int max_hp; // The monster¡¦s maximum HP
	const int max_mp; // The monster¡¦s maximum MP
	BaseMonster(string, int, int, int, int, int, int);
	virtual ~BaseMonster();
	void setHP(int);
	int getHP() const;
	void setMP(int);
	int getMP() const;
	//string getName(void) const;
	static int getInstanceCount(void);
	virtual string serialize() = 0;
};

#endif

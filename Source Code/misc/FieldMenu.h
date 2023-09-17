#ifndef FieldMenu_H
#define FieldMenu_H
#include"Menu.h"
#include"NovicePlayer.h"
#include"Game.h"
#include<fstream>
class Game;
using namespace std;
class FieldMenu :public Menu
{
public:
	FieldMenu();
	int FieldChoice(NovicePlayer**, int);
	void whosbackpack(NovicePlayer**, int);
	void backpack(NovicePlayer*);
};
#endif

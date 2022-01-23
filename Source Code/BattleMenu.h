#ifndef BattleMenu_H
#define BattleMenu_H
#include"Menu.h"
#include"NovicePlayer.h"
#include <iomanip>
using namespace std;
class BattleMenu :public Menu
{
public:
	BattleMenu();
	int BattleChoice(NovicePlayer*);
};
#endif

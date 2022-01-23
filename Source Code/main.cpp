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
#include<iostream>
#include<string>
#include<math.h>
#include<typeinfo>
#include<fstream>
#include<vector>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include"Game.h"
using namespace std;
//int **createmap(string x);
void whosbackpack(NovicePlayer**,int);
void backpack(NovicePlayer*);
int main()
{
	Game rpg;
	rpg.run();
	
	
}
/*int **createmap(string x)
{
	ifstream read;
	read.open(x, ios::in);
	int **map;
	int row, col;
	char trash;
	read >> col;
	read >> trash;
	read >> row;
	map = new int *[row];//宣告行大小
	for (int x = 0; x < row; x++)
	{
		map[x] = new int[col];//宣告列大小
	}
	for (int i = 0; i < row; i++)//將datas中的迷宮讀進map
	{
		for (int j = 0; j < col; j++)
		{
			read >> map[i][j];
			if (j != col - 1)
			{
				read >> trash;
			}
		}
	}
	return map;
}*/


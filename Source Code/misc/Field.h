#ifndef FIELD_H
#define FIELD_H
#include<iostream>
#include "NovicePlayer.h"
#include "BaseMonster.h"
#include<string>
using namespace std;
class Field
{
private:
	int** map_data;
	int current_position_x;
	int current_position_y;
	string map_name;
	int vision_width;
	int vision_height;
	int map_width;
	int map_height;

public:
	Field();
	Field(int**, int, int, int, int);//(map data,x,y,width, height)
	Field(const char*, int, int, int, int);//(file name,x,y,width, height)後兩個盡量設奇數
	~Field();
	void setMapWidth(int);
	void setMapHeight(int);
	void setMapName(string);
	bool move(char);
	bool moveUp(void);
	bool moveDown(void);
	bool moveLeft(void);
	bool moveRight(void);
	//void control();
	int getCurrentPositionX(void) const;
	int getCurrentPositionY(void) const;
	int getVisionWidth(void) const;
	int getVisionHeight(void) const;
	string getMapName(void) const;
	int getMapSymbol(int, int);
	void setPosition(int, int);//(x,y)
	void setMapSymbol(int, int, int);//(symbol,x,y)
	void setVisionSize(int, int);
	void display(void) const;
	int getMapWidth(void) const;
	int getMapHeight(void) const;
};
#endif

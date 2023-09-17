#include "Field.h"
#include<fstream>
#include <stdio.h>
#include <conio.h>

enum { ROAD = 0, WALL = 1, PLAYER = 200, END = 201 ,START=202,SHOP=300};
Field::Field(int **map, int x, int y, int w, int h)
{
	map_data = map;
	setPosition(x, y);
	setVisionSize(w, h);
	map_width = 0;
	map_height = 0;
	map_name = "Field";
	//setMapSymbol(1, 1, 2);
	/*for (int i = 0; i < 11; i++)//印出map
	{
		for (int j = 0; j < 12; j++)
		{
			cout << map[i][j] << "\t";
		}
		cout << endl;
	}*/
	//system("pause");
	//display();
}

Field::Field()
{
}

Field::Field(const char *filename, int x, int y, int w, int h)
{
	ifstream read;
	read.open(filename, ios::in);
	char trash;
	read >> map_width;
	read >> trash;
	read >> map_height;

	map_data = new int *[getMapHeight()];//宣告行大小
	for (int i = 0; i < getMapHeight(); i++)
	{
		map_data[i] = new int[getMapWidth()];//宣告列大小
	}
	for (int i = 0; i < getMapHeight(); i++)//將datas中的迷宮讀進map
	{
		for (int j = 0; j < getMapWidth(); j++)
		{
			read >> map_data[i][j];
			if (j != getMapWidth() - 1)
			{
				read >> trash;
			}
		}
	}
	//for (int i = 0; i < getMapHeight(); i++)//將datas中的迷宮讀進map
	//{
	//	for (int j = 0; j < getMapWidth(); j++)
	//	{
	//		cout << map_data[i][j]<<"\t";
	//	}
	//	cout << endl;
	//}
	//system("pause");
	setPosition(x, y);
	setVisionSize(w, h);
	map_name = filename;
	map_name = map_name.substr(0, map_name.rfind("."));//去除副檔名
	//cout << map_name << endl;
	//display();
}

Field::~Field()
{
	for (int j = 0; j < getMapHeight(); j++)
	{
		delete map_data[j];
	}
	delete map_data;
}

void Field::setMapWidth(int w)
{
	map_width = w;
}

void Field::setMapHeight(int h)
{
	map_height = h;
}

void Field::setMapName(string n)
{
	map_name = n;
}

bool Field::move(char opt)
{
	if (opt == 'U')
	{
		if (moveUp())
		{
			return true;
		}
	}
	else if (opt == 'D')
	{
		if (moveDown())
		{
			return true;
		}
	}
	else if (opt == 'L')
	{
		if (moveLeft())
		{
			return true;
		}
	}
	else if (opt == 'R')
	{
		if (moveRight())
		{
			return true;
		}
	}
	return false;
}

bool Field::moveUp(void)
{
	//cout << "getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1 is" << getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) << endl;
	if (getMapSymbol(getCurrentPositionX(), getCurrentPositionY() - 1) == WALL)
	{
		//cout << "false\n";
		return false;
	}
	return true;
}

bool Field::moveDown(void)
{
	if (getMapSymbol(getCurrentPositionX(), getCurrentPositionY() + 1) == WALL)
	{
		return false;
	}
	return true;
}

bool Field::moveLeft(void)
{
	if (getMapSymbol(getCurrentPositionX()-1, getCurrentPositionY()) == WALL)
	{
		return false;
	}
	return true;
}

bool Field::moveRight(void)
{
	if (getMapSymbol(getCurrentPositionX() + 1, getCurrentPositionY()) == WALL)
	{
		return false;
	}
	return true;
}

int Field::getCurrentPositionX(void) const
{
	return current_position_x;
}

int Field::getCurrentPositionY(void) const
{
	return current_position_y;
}

int Field::getVisionWidth(void) const
{
	return vision_width;
}

int Field::getVisionHeight(void) const
{
	return vision_height;
}

string Field::getMapName(void) const
{
	return map_name;
}

int Field::getMapSymbol(int x, int y)
{
	return map_data[y][x];//xy相反
}

void Field::setPosition(int x, int y)
{
	current_position_x = x;
	current_position_y = y;
}

void Field::setMapSymbol(int s, int x, int y)
{
	map_data[y][x] = s;//xy反過來
}

void Field::setVisionSize(int w, int h)
{
	vision_width = w;
	vision_height = h;
}

void Field::display(void) const
{
	cout <<"\t\t\t\t\t\t"<< map_name << endl;
	if (map_name == "中西區")//中西區路名
	{
		cout << "\t\t\t\t\t\t";
		if (getCurrentPositionX() == 2){cout << "海安路\t";}
		else if (getCurrentPositionX() == 9) { cout << "國華街\t"; }
		else if (getCurrentPositionX() == 16) { cout << "西門路\t"; }
		else if (getCurrentPositionX() == 26) { cout << "永福路\t"; }
		else if (getCurrentPositionX() == 32) { cout << "忠義路\t"; }
		else if (getCurrentPositionX() == 39) { cout << "公園路\t"; }
		if (getCurrentPositionY() == 2) { cout << "公園南路"; }
		else if(getCurrentPositionY() == 8) { cout << "成功路"; }
		else if (getCurrentPositionY() == 14) { cout << "民族路"; }
		else if (getCurrentPositionY() == 20) { cout << "民權路"; }
		else if (getCurrentPositionY() == 26) { cout << "民生路"; }
		else if (getCurrentPositionY() == 32) { cout << "中正路"; }
		else if (getCurrentPositionY() == 35) { cout << "友愛街"; }
		else if (getCurrentPositionY() == 38) { cout << "府前路"; }
		else if (getCurrentPositionY() == 41) { cout << "保安路"; }
		cout << "\n";
	}
	else
	{
		cout << "\t\t\t\t\t\t" << "目前位置(" << getCurrentPositionX() << "," << getCurrentPositionY() << ")\n";
	}
	int ini_x, ini_y;//視線最左上
	if (getCurrentPositionX() - (getVisionWidth() / 2) > 0)
	{
		ini_x = getCurrentPositionX() - (getVisionWidth() / 2);
		if (getCurrentPositionX() + (getVisionWidth() / 2) >= getMapWidth())//超過範圍
		{
			//cout << "ini_x is " << ini_x << endl;
			//cout << "(getCurrentPositionX() + (getVisionWidth() / 2)) is" << (getCurrentPositionX() + (getVisionWidth() / 2));
			//cout << " getMapWidth() is" << getMapWidth() << endl;
			//cout << "超過" << (getCurrentPositionX() + (getVisionWidth() / 2)) - getMapWidth()+1 << endl;
			ini_x = ini_x - ((getCurrentPositionX() + (getVisionWidth() / 2)) - getMapWidth()+1);//超過範圍幾格
			//cout << "ini_x is " << ini_x << endl;
		}
	}
	else
	{
		ini_x = 0;
	}
	if (getCurrentPositionY() - (getVisionHeight() / 2) > 0)
	{
		//cout << "current_position_y is" << current_position_y<<endl;
		//cout << "current_position_y - (vision_height / 2) is" << current_position_y - (vision_height / 2) << endl;
		ini_y = getCurrentPositionY() - (getVisionHeight() / 2);
		if (getCurrentPositionY() + (getVisionHeight() / 2) >= getMapHeight())//超過範圍
		{
			//cout << "超過" << ((getCurrentPositionY() + (getVisionHeight() / 2)) - getMapHeight()+1) << endl;
			ini_y = ini_y - ((getCurrentPositionY() + (getVisionHeight() / 2)) - getMapHeight()+1);//超過範圍幾格
		}
	}
	else
	{
		ini_y = 0;
	}
	for (int i = 0; i < getVisionHeight(); i++)//從最左上開始print視野
	{
		cout << "\t\t\t\t\t\t";
		for (int j = 0; j < getVisionWidth(); j++)
		{
			if (map_data[ini_y + i][ini_x + j] == ROAD) { cout << "  "; }
			else if (map_data[ini_y + i][ini_x + j] == WALL) { cout << "■"; }
			else if (map_data[ini_y + i][ini_x + j] == END) { cout << "下"; }
			else if (map_data[ini_y + i][ini_x + j] == START) { cout << "上"; }
			else if (map_data[ini_y + i][ini_x + j] == SHOP) { cout << "商"; }
			else if (map_data[ini_y + i][ini_x + j] >=900) { cout << "怪"; }
			else if (map_data[ini_y + i][ini_x + j] == PLAYER) { cout << "我"; }
			else if (map_data[ini_y + i][ini_x + j] >500 && map_data[ini_y + i][ini_x + j] <= 600) { cout << "☆"; }//精選商店
			else if (map_data[ini_y + i][ini_x + j] >= 250 && map_data[ini_y + i][ini_x + j] <= 254) { cout << "人"; }//精選商店
			else { cout << "!!"; }
		}
		cout << endl;
	}
}

int Field::getMapWidth(void) const
{
	return map_width;
}

int Field::getMapHeight(void) const
{
	return map_height;
}




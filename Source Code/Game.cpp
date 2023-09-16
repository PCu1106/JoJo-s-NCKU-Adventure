#include "Game.h"
#include <windows.h> 
#pragma comment(lib, "Winmm.lib") 
Game::Game()
{
	for (int i = 0; i < 5; i++)//�̤j�H��5�H
	{
		Playlist[i] = nullptr;
	}
}

void Game::run()
{
	PlaySound("Awaken.wav", NULL, SND_ASYNC | SND_LOOP);
	Event e;
	srand(time(NULL));
	MainMenu ini;
	int firstcho = ini.GameChoice();
	PositionX = 1;
	PositionY = 1;
	//Field f1(mmm, PositionX, PositionY, 11, 9);
	if (firstcho == 0)//�s�C��
	{
		Field f1("�q�@��.txt", PositionX, PositionY, 11, 11);
		Field f2("�����.txt", 40, 2, 17, 17);
		Field f3("�q���t�].txt", PositionX, PositionY, 11, 11);
		AllField[0] = f1;
		AllField[1] = f2;
		AllField[2] = f3;
		PlaySound("Jotaro.wav", NULL, SND_ASYNC | SND_LOOP);
		e.Event0();
		CurrentPlayer = 0;
		NovicePlayer *p1 = new NovicePlayer(18, "�ű��Ӥӭ�");
		CurrentPlayer++;
		Playlist[0] = p1;
		//WeaponItem *my_weapon = new SwordWeapon;//static_cast<WeaponItem*>(p1->takeItem(0));
		//p1->putItem(static_cast<Item*>(my_weapon)); 
		whichmap = 0;
		system("pause");
		while (true)
		{
			system("cls");
			AllField[whichmap].display();
			MyMap = new int *[AllField[whichmap].getMapHeight()];
			for (int i = 0; i < AllField[whichmap].getMapHeight(); i++)
			{
				MyMap[i] = new int[AllField[whichmap].getMapWidth()];
			}
			for (int i = 0; i < AllField[whichmap].getMapHeight(); i++)//�g�JMyMap
			{
				for (int j = 0; j < AllField[whichmap].getMapWidth(); j++)
				{
					MyMap[i][j] = AllField[whichmap].getMapSymbol(j, i);
				}
			}
			MyMapHeight = AllField[whichmap].getMapHeight();
			MyMapWidth = AllField[whichmap].getMapWidth();

			move(AllField[whichmap]);
		}
	}
	else if (firstcho == 1)//�~��C��
	{
		PlaySound("Jotaro.wav", NULL, SND_ASYNC | SND_LOOP);
		CurrentPlayer = 0;
		ifstream read;
		read.open("serialize.txt", ios::in);
		string line;
		for (int i = 0; i < 5; i++)//Ū���W����
		{
			getline(read, line);
			if (line != "N")
			{
				if (i == 0)
				{
					CurrentPlayer++;
					Playlist[0] = NovicePlayer::unserialize(line);
				}
				if (i == 1)
				{
					CurrentPlayer++;
					Playlist[1] = NovicePlayer::unserialize(line);
				}
				if (i == 2)
				{
					CurrentPlayer++;
					Playlist[2] = NovicePlayer::unserialize(line);
				}
				if (i == 3)
				{
					CurrentPlayer++;
					Playlist[3] = NovicePlayer::unserialize(line);
				}
				if (i == 4)
				{
					CurrentPlayer++;
					Playlist[4] = NovicePlayer::unserialize(line);
				}
			}
		}
		read>>whichmap;
		int x1, y1, x2, y2, x3, y3;
		read >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Field f11("new�q�@��.txt", x1, y1, 11, 11);
		f11.setMapName("�q�@��");
		Field f22("new�����.txt", x2, y2, 17, 17);
		f22.setMapName("�����");
		Field f33("new�q���t�].txt", x3, y3, 11, 11);
		f33.setMapName("�q���t�]");
		AllField[0] = f11;
		AllField[1] = f22;
		AllField[2] = f33;
		while (true)
		{
			system("cls");
			AllField[whichmap].display();
			MyMap = new int *[AllField[whichmap].getMapHeight()];
			for (int i = 0; i < AllField[whichmap].getMapHeight(); i++)
			{
				MyMap[i] = new int[AllField[whichmap].getMapWidth()];
			}
			for (int i = 0; i < AllField[whichmap].getMapHeight(); i++)//�g�JMyMap
			{
				//cout << i << '\n';
				//system("pause");
				for (int j = 0; j < AllField[whichmap].getMapWidth(); j++)
				{
					MyMap[i][j] = AllField[whichmap].getMapSymbol(j, i);
				}
			}
			MyMapHeight = AllField[whichmap].getMapHeight();
			MyMapWidth = AllField[whichmap].getMapWidth();

			move(AllField[whichmap]);
		}
	}
	else//���}
	{
		cout << "���}\n";
	}

	system("pause");

}



void Game::move(Field &f1)
{
	int EncounterEvent = 0;//�O�_�D�J�ƥ�
	char opt;
	opt = _getch();
	if (opt == 72)//���W
	{
		if (f1.move('U'))
		{
			f1.setMapSymbol(0, f1.getCurrentPositionX(), f1.getCurrentPositionY());//���a���}��0
			f1.setPosition(f1.getCurrentPositionX(), f1.getCurrentPositionY() - 1);
			//cout << "getCurrentPositionX() is" << getCurrentPositionX() << endl;
			//cout << "getCurrentPositionY() is" << getCurrentPositionY() << endl;
		}
	}
	else if (opt == 80)//���U
	{
		if (f1.move('D'))
		{
			f1.setMapSymbol(0, f1.getCurrentPositionX(), f1.getCurrentPositionY());//���a���}��0
			f1.setPosition(f1.getCurrentPositionX(), f1.getCurrentPositionY() + 1);
		}
	}
	else if (opt == 75)//����
	{
		if (f1.move('L'))
		{
			f1.setMapSymbol(0, f1.getCurrentPositionX(), f1.getCurrentPositionY());//���a���}��0
			f1.setPosition(f1.getCurrentPositionX() - 1, f1.getCurrentPositionY());
		}
	}
	else if (opt == 77)//���k
	{
		if (f1.move('R'))
		{
			f1.setMapSymbol(0, f1.getCurrentPositionX(), f1.getCurrentPositionY());//���a���}��0
			f1.setPosition(f1.getCurrentPositionX() + 1, f1.getCurrentPositionY());
		}
	}
	else if (opt == 13)//��enter
	{
		FieldMenu fm;
		if (fm.FieldChoice(Playlist, CurrentPlayer) == 1)
		{
			Serialize();
		}
	}
	//cout << f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) << endl;
	//system("cls");
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 201)//�U�i��
	{
		EncounterEvent = 1;
		whichmap++;//�U�@�i
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 202)//�W�i��
	{
		EncounterEvent = 1;
		whichmap--;//�W�@�i
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 250)//����
	{
		EncounterEvent = 1;
		NovicePlayer *p2 = new NovicePlayer(10, "���� �촵�F");
		Playlist[1] = p2;
		e.Event250();
		CurrentPlayer++;
		if (e.happen[250] == 1)
		{
			EncounterEvent = 0;//�ƥ�|����
		}
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 251)//�����w��
	{
		EncounterEvent = 1;
		e.Event251();
		if (e.happen[251] == 1)
		{
			EncounterEvent = 0;//�ƥ�|����
			CurrentPlayer++;
			NovicePlayer *p3 = new MagicianPlayer(12, "�����w��");
			Playlist[2] = p3;
		}
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 252)//��ʰ|���
	{
		EncounterEvent = 1;
		e.Event252();
		if (e.happen[252] == 1)
		{
			EncounterEvent = 0;//�ƥ�|����
			NovicePlayer *p4 = new KnightPlayer(16, "��ʰ|���");
			Playlist[3] = p4;
			CurrentPlayer++;
		}
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 253)//�i�|�ǹp��
	{
		EncounterEvent = 1;
		e.Event253();
		if (e.happen[253] == 1)
		{
			EncounterEvent = 0;//�ƥ�|����
			NovicePlayer *p5 = new KnightPlayer(14, "�i�|�ǹp��");
			Playlist[4] = p5;
			CurrentPlayer++;
		}
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 300)//�ӤH
	{
		EncounterEvent = 1;
		e.Event300(Playlist);
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) > 300 && f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) <= 600)//�a�I301~600(501~600���ө�)
	{
		EncounterEvent = 1;
		e.EventPlace(f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()));
	}
	if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) >= 900)//�J��Ǫ�
	{
		PlaySound("Kakyoin.wav", NULL, SND_ASYNC | SND_LOOP);
		cout << "�԰��}�l!!\n";
		system("pause");
		system("cls");
		if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 900)
		{
			e.Event900(Playlist,CurrentPlayer);
		}
		if (f1.getMapSymbol(f1.getCurrentPositionX(), f1.getCurrentPositionY()) == 901)
		{
			e.Event901(Playlist, CurrentPlayer);
		}

		EncounterEvent = 1;
		PlaySound("Jotaro.wav", NULL, SND_ASYNC | SND_LOOP);
	}
	if (EncounterEvent == 1)//�Y���D�J�ƥ�A�h�h�^
	{
		if (opt == 72){f1.setPosition(f1.getCurrentPositionX(), f1.getCurrentPositionY() + 1);}//�����W
		else if (opt == 80) { f1.setPosition(f1.getCurrentPositionX(), f1.getCurrentPositionY() - 1); }//�����U
		else if (opt == 75) { f1.setPosition(f1.getCurrentPositionX() + 1 , f1.getCurrentPositionY()); }//������
		else if (opt == 77) { f1.setPosition(f1.getCurrentPositionX() - 1, f1.getCurrentPositionY()); }//�����k
	}
	f1.setMapSymbol(200, f1.getCurrentPositionX(), f1.getCurrentPositionY());////////////���a���ʧ�s��m
	PositionX = f1.getCurrentPositionX();
	PositionY = f1.getCurrentPositionY();
	//system("cls");
	//f1.display();
	for (int i = 0; i < f1.getMapHeight(); i++)//��sMyMap
	{
		for (int j = 0; j < f1.getMapWidth(); j++)
		{
			MyMap[i][j] = f1.getMapSymbol(j, i);
		}
	}
}

void Game::Serialize()
{
	cout << "�s��\n";
	ofstream write("serialize.txt", ios::out);
	if (!write)
	{
		cerr << "�L�k�}��" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++)
	{
		if (Playlist[i] != nullptr)
		{
			write << Playlist[i]->serialize();
		}
		else
		{
			write << "N\n";
		}
	}
	write << whichmap << endl;//�ثe�b���i��
	write << AllField[0].getCurrentPositionX() << '\t' << AllField[0].getCurrentPositionY()<< endl;
	write << AllField[1].getCurrentPositionX() << '\t' << AllField[1].getCurrentPositionY() << endl;
	write << AllField[2].getCurrentPositionX() << '\t' << AllField[2].getCurrentPositionY() << endl;
	ofstream wmap1("new�q�@��.txt", ios::out);
	//wmap1 << AllField[0].getCurrentPositionX() << ',' << AllField[0].getCurrentPositionY() << endl;
	wmap1 << AllField[0].getMapWidth() << ',' << AllField[0].getMapHeight() << endl;
	for (int i = 0; i < AllField[0].getMapHeight(); i++)
	{
		for (int j = 0; j < AllField[0].getMapWidth(); j++)
		{
			wmap1 << AllField[0].getMapSymbol(j,i) ;
			if (j < AllField[0].getMapWidth() - 1)
			{
				wmap1 << ',';
			}
		}
		wmap1 << endl;
	}
	ofstream wmap2("new�����.txt", ios::out);
	wmap2 << AllField[1].getMapWidth() << ',' << AllField[1].getMapHeight() << endl;
	for (int i = 0; i < AllField[1].getMapHeight(); i++)
	{
		for (int j = 0; j < AllField[1].getMapWidth(); j++)
		{
			wmap2 << AllField[1].getMapSymbol(j, i) ; 
			if (j < AllField[1].getMapWidth() - 1)
			{
				wmap2 << ',';
			}
		}
		wmap2 << endl;
	}
	ofstream wmap3("new�q���t�].txt", ios::out);
	wmap3 << AllField[2].getMapWidth() << ',' << AllField[2].getMapHeight() << endl;
	for (int i = 0; i < AllField[2].getMapHeight(); i++)
	{
		for (int j = 0; j < AllField[2].getMapWidth(); j++)
		{
			wmap3 << AllField[2].getMapSymbol(j, i);
			if (j < AllField[2].getMapWidth() - 1)
			{
				wmap3 << ',';
			}
		}
		wmap3 << endl;
	}
	system("pause");
}

#include "Event.h"

Event::Event()
{
	for (int i = 0; i < 1000; i++)
	{
		happen[i] = 0;
	}
}

void Event::Event0()
{
	happen[0] = 1;
	cout << "JoJo�@��H�b�Q��DIO���ȵ{���A�]�D���ĤH�����A�ثe�b�x�W�x�n�����j�����\n";
}

void Event::Event250()
{
	happen[250] = 1;
	cout << "���ҳ촵�F�G���Ӥӭ����A�o���\�U����N�N�Ѵ��Y���S���D\n";
	system("pause");
	cout << "���ҳ촵�F�G�٬O�h����ϦY���n�F�A�֥h�s��L�H\n";
	system("pause");
	cout << "���ҳ촵�F�G�ƻ�!?�L�̤w�g���h�F!!������!!\n";
	system("pause");
	cout << "���ҳ촵�F�[�J�F����\n";
	system("pause");
}

void Event::Event251()
{
	if (happen[250] == 0)
	{
		cout << "�����w���G�촵�F���ͨS��A�b�@�_��?\n";
	}
	else
	{
		happen[251] = 1;
		cout << "�����w���G�x�n�u���O�䤣�Ө�p���O\n";
		system("pause");
		cout << "�����w���G�촵�F���͡AJoJo�A�n�@�_�Y��?\n";
		system("pause");
		cout << "�����w���[�J�F����\n";
	}
	system("pause");
}

void Event::Event252()
{
	if (happen[251] == 0)
	{
		cout << "��ʰ|����G�o�a�ޱƤ����O�A�i�������w�����ͤ���Y��\n";
	}
	else
	{
		happen[252] = 1;
		cout << "��ʰ|����GJoJo�A�n���n�ոեx�W���ޱƶ�?\n";
		system("pause");
		cout << "��ʰ|����G���M�S���饻���n�Y�A���۸��_�ӫK�y�h�F�O\n";
		system("pause");
		cout << "��ʰ|����[�J�F����\n";
	}
	system("pause");
}

void Event::Event253()
{
	if (happen[252] == 0)
	{
		cout << "�i�|�ǹp�ҡG�o�N�O�x�n�̦��W���B����ü��!!\n";
	}
	else
	{
		happen[253] = 1;
		cout << "�i�|�ǹp�ҡG��!!!�ڦY���a�F\n";
		system("pause");
		cout << "�i�|�ǹp�ҡG�o�a���O�G�N��!!!\n";
		system("pause");
		cout << "�i�|�ǹp�ҥ[�J�F����\n";
	}
	system("pause");
}

void Event::Event300(NovicePlayer **Playlist)
{
	cout << "�q�~�\�U\n";
	cout << "������\n" ;
	cout << "�q�~�H���n�B�͡A�����ܿˤ�\n";
	system("pause");
	if (happen[300] == 0)
	{
		cout << "�q�\�����G�P�Ǧ���ݨ���~�i�H�������Z����\n";
		system("pause");
		cout << "�j�a��o�F�}�C�M���@��\n";
		WeaponItem *w = new SwordWeapon[5];
		ArmorItem *a = new TunicArmor[5];
		for (int i = 0; i < 5; i++)
		{
			if (Playlist[i] != nullptr)
			{
				Playlist[i]->putItem(&w[i]);
				Playlist[i]->putItem(&a[i]);
			}
		}
		happen[300] = 1;
	}
	system("pause");
}

void Event::Event900(NovicePlayer **Playlist, int CurrentPlayer)
{
	BaseMonster **mm = new BaseMonster*[5];
	BaseMonster *g1 = new GoblinMonster;
	BaseMonster *z1 = new ZombieMonster;
	BaseMonster *j1 = new JWMonster;
	BaseMonster *j2 = new JWMonster;
	mm[0] = g1;
	mm[1] = z1;
	mm[2] = j1;
	mm[3] = j2;
	Battle b1(Playlist, mm, CurrentPlayer, 2,10);
	if (b1.win == 1)//Ĺ�F
	{
		cout << "�j�a��o�F�ͩR�Ĥ��M�]�O�Ĥ�\n";
		ConsumableItem *b1potion = new LifePotion[5];
		ConsumableItem *b1potion2 = new MagicPotion[5];
		for (int i = 0; i < 5; i++)
		{
			if (Playlist[i] != nullptr)
			{
				Playlist[i]->putItem(&b1potion[i]);
				Playlist[i]->putItem(&b1potion2[i]);
			}
		}
		cout << Playlist[0]->getName() << "��o�F�s���i���S�Ԭ����Q�g���i���S�ԯ�\n";
		WeaponItem *a1 = new NeoArmstrongWeapon;
		Playlist[0]->putItem(a1);
		system("pause");
	}
}

void Event::Event901(NovicePlayer **Playlist, int CurrentPlayer)
{
	cout << "�ű��Ӥӭ��G�o����...�O��������!!!\n";
	system("pause");
	cout << "???�G���⤣����~�p�l\n";
	system("pause");
	cout << "�ű��Ӥӭ��G���J�A���W�W��\n";
	system("pause");
	cout << "???�G�ڬO�֦�""HW""�t�ܪ������Ϫ̡A���¤j�]��\n";
	system("pause");
	cout << "���¤j�]���G�ݨ�ڪ�HW���H�A�S���@�ӯଡ��\n";
	system("pause");
	cout << "�ű��Ӥӭ��G�r�ǧr�ǡA�ݨӬO�n�ή��Y���L�M���F\n";
	system("pause");
	system("cls");
	BaseMonster **mm = new BaseMonster*[5];
	BaseMonster *g1 = new GoblinMonster;
	BaseMonster *z1 = new ZombieMonster;
	BaseMonster *j1 = new JWMonster;
	BaseMonster *j2 = new JWMonster;
	mm[0] = g1;
	mm[1] = z1;
	mm[2] = j1;
	mm[3] = j2;
	Battle b2(Playlist, mm, CurrentPlayer, 4);
	if (b2.win == 1)//Ĺ�F
	{
		int r = rand() % 5;
		if (r == 0)//20%���D��
		{
			cout << "�j�a��o�F���̤��C\n";
			WeaponItem *b2w = new ExcaliburWeapon[5];
			for (int i = 0; i < 5; i++)
			{
				if (Playlist[i] != nullptr)
				{
					Playlist[i]->putItem(&b2w[i]);
				}
			}
		}
		system("pause");
	}
}

void Event::EventPlace(int a)
{
	if (a == 301)
	{
		cout << "���r��\n";
		cout << "������\n";
		cout << "���ǥ��ҥi�H�K�O�J��\n�O�ɴZ�Ҫ��n�Ҧb\n";
	}
	else if (a == 302)
	{
		cout << "���a���Y�N��\n";
		cout << "������\n";
		cout << "²�檺40������+�F���ը�\n";
	}
	else if (a == 303)
	{
		cout << "�z��\n";
		cout << "��������\n";
		cout << "60����N�N�Ѵ��Y�̲��A�Ƥ]�ܦh\n��O�w�����J�C�{��N�N�Ѥ@�I\n�p�j�@�~�Y�p�Z��\n";
	}
	else if (a == 304)
	{
		cout << "�I�h�F�H�馡����\n";
		cout << "������\n";
		cout << "160���H�W���ѡA�e�N�u���O�J�f�Y��\n�������b�O�ܰ�\n(���|�ֵ󪺩��ѴN�������ڤF)\n";
	}
	else if (a == 305)
	{
		cout << "�j����\n";
		cout << "��������\n";
		cout << "�b���j���񩱮a�N���A�R190���¨q�q�v��\n�ݹq�v����\n";
	}
	else if (a == 306)
	{
		cout << "�夫�饻�Ʋz\n";
		cout << "������\n";
		cout << "60�����g���Q�s���Z�S�O���A�����ӥB�����Y\n�����I�]�i�H�Y�X��\n";
	}
	else if (a == 307)
	{
		cout << "���Τ��d\n";
		cout << "����\n";
		cout << "90�����d�ܤp�J�A�n�Y���S���S�O�n�Y\n�d���٬O����������N��M��\n";
	}
	else if (a == 308)
	{
		cout << "�����ѩ�\n";
		cout << "������\n";
		cout << "35�����氮�ѡA�ݨ�����W�ܱ�\n���G�èS���S�O�n�Y\n";
	}
	else if (a == 309)
	{
		cout << "�����̿|\n";
		cout << "������\n";
		cout << "35���̿|�A�ݨ�����W�j��\n���G�èS���S�O�n�Y\n�̿|�N�O�n�Y�O�w�������̿|��\n";
	}
	else if (a == 310)
	{
		cout << "�̭����a\n";
		cout << "������\n";
		cout << "80���ޱƶ��A�����q�q\n�ޱƨS�ƻ���D\n���a�������������{���ޱƤ���n�Y\n";
	}
	else if (a == 311)
	{
		cout << "�p�����J��\n";
		cout << "������\n";
		cout << "40����J�ѡA�N�O��J��\n����_�Q���H���פp��A�ڷ|���ˤj�a�Y�o�a��J��\n";
	}
	else if (a == 312)
	{
		cout << "�E�Q�B����ü\n";
		cout << "������\n";
		cout << "60���B����ü\n���M�n�Y���O�Y�����A�u�����ת��I��\n";
	}
	else if (a == 313)
	{
		cout << "���ͺ񨧨F\n";
		cout << "������\n";
		cout << "40���񨧨F�����A�O�B�F\n��ı�o�n�ܺ񨧨F���������٬O���q�����ڸ��Ѥl����������������\n";
	}
	else if (a == 314)
	{
		cout << "�q�ץV�ʯ�\n";
		cout << "������\n";
		cout << "���q��20���V�ʯ�\n30���V�ʤ����]�O���q\n���ܦ��W�N�O�F\n";
	}
	else if (a == 315)
	{
		cout << "���T��ަ��u\n";
		cout << "��������\n";
		cout << "���M�L��ަ�����٨S�Y�L�L���ަ�\n20�����궺����\n";
	}
	else if (a == 316)
	{
		cout << "�פp��\n";
		cout << "����\n";
		cout << "50����J�ѶW�p�J\n�٬O�h��������Y�p�����J�Ѥ���n\n";
	}
	else if (a == 317)
	{
		cout << "������������N�ѩ�\n";
		cout << "������\n";
		cout << "80����N�N�ѡA���I�p�J\n�G�M�Y�O�w�����J�C�{��N�N�Ѧn\n";
	}
	else if (a == 318)
	{
	cout << "�i�a�����B�ç��O\n";
	cout << "��������\n";
	cout << "60���ç��O\n�ثe�u�Y�L�a���p���A�ҥH�L�k�T�w�O�_�̱��o�a\n";
	}
	else if (a == 319)
	{
	cout << "�P�O�w������\n";
	cout << "��������\n";
	cout << "35������A�٤���\n�����᭺���O�C�~�����M�R�����I�߳��A�ĤG�O�F�׸����x�n����񨧤�\n";
	}
	else if (a == 320)
	{
	cout << "�ۺ���I�߫��ç��O\n";
	cout << "������\n";
	cout << "60���ç��O\n���`�����D�S�i�a�����B�ç��O���@��\n";
	}
	else if (a == 321)
	{
	cout << "�ۺ�ݤ��״�\n";
	cout << "��\n";
	cout << "110�����״��S����\n�p\n�������S���D\n�٬O�峹�n\n";
	}
	else if (a == 322)
	{
	cout << "���Ӯp�ڥͦװ���\n";
	cout << "��������\n";
	cout << "100���װ���\n�Ĥ@���Y�װ���ı�o�W�n�Y\n���ھڰ��Ӧ�ȤH��ܦn���٤֤F�@��\n";
	}
	else if (a == 323)
	{
	cout << "�����~��\n";
	cout << "��������\n";
	cout << "�n����ź��\n";
	}
	else if (a == 324)
	{
	cout << "�üֿN�׶�\n";
	cout << "��������\n";
	cout << "70���N�׶��A�����F��\n�n�Y�A���Y����\n";
	}
	else if (a == 325)
	{
	cout << "���t���궺\n";
	cout << "����\n";
	cout << "20�����궺�A�t�椣���D��������[�T�˵�N��70\n���궺�����A�o��Ӥ�\n";
	}
	else if (a == 326)
	{
	cout << "����N��\n";
	cout << "������\n";
	cout << "35���N�ѡA���S�O�����D\n�W�h�H�ƶ�~~����ı�o�S���n�Y��o�ص{��\n";
	}
	else if (a == 327)
	{
	cout << "�İӸ�\n";
	cout << "��������\n";
	cout << "50������B��\n���N�|�p�ɯu���O�Z�n�ܪ��A���]�O���I�p����\n";
	}
	else if (a == 328)
	{
	cout << "�L�W�p�Y\n";
	cout << "��������\n";
	cout << "�u���O�S���W�r\n25�����궺��30���̿|���ܦn�Y\n�ܦ��ѩ������D\n";
	}
	else if (a == 329)
	{
	cout << "�ռq\n";
	cout << "������\n";
	cout << "���ܤj�ܺ}�G���x�|\n";
	}
	else if (a == 330)
	{
	cout << "���P�c�j������N��\n";
	cout << "��������\n";
	cout << "60����N�N��\n���q�y�֦��ƫ��״I�A�������M�����A���Y�]�ܦn��\n���L��N�Ĥ@�O�O�w�����J�C�{��N�N��\n";
	}
	else if (a == 331)
	{
	cout << "����B����س�ü\n";
	cout << "��������\n";
	cout << "60����س�ü��\n��ü�̪����׶W�j������\n";
	}
	else if (a == 332)
	{
	cout << "����B����س�ü\n";
	cout << "������\n";
	cout << "60����س�ü��\n�O�w�����񪺲ĤG�N�A�Pı��ü�̪����פ֤F�I\n";
	}
	else if (a == 501)
	{
		cout << "��������\n";
		cout << "����������\n";
		cout << "���ƭ���!!!!!!\n30������¿}���̦E��\n40������񨧨F�����]����\n�����\�]�W��C�A�ܾA�X�a�f�l�ӳܶ��ƥ��d\n";
	}
	else if (a == 502)
	{
		cout << "�i�֤j�W��Ϳ}\n";
		cout << "����������\n";
		cout << "���§����100���s�L�]�ܾA�X����§�R�^�a\n���ª۳�.��ͱ�.������ɪ�Ϳ}�T�ؤf��\n";
	}
	else if (a == 503)
	{
	cout << "�Ҫ������J(���r��)\n";
	cout << "����������\n";
	cout << "�����J�����A12���@��\n��b�O�������A�����J���ܤJ��\n";
	}
	else if (a == 504)
	{
	cout << "�Φ����G��\n";
	cout << "����������\n";
	cout << "�G�Ĥ��G�B�����A��ʤ���50���W�@\n���G�B�]�W�n�Y�A����100�h���Z���ת�\n";
	}
	else if (a == 505)
	{
	cout << "�J�C�{�j������N�N��\n";
	cout << "����������\n";
	cout << "55����N�N��\nCP�ȳ̰��A���@�ƤS�h�A�ثe�Y�L�̦n�Y����N�N��\n";
	}
	else if (a == 506)
	{
	cout << "���̿|��\n";
	cout << "����������\n";
	cout << "30���̿|20�����궺\n�ӥx�n�n�Y���ǲΤp�Y����\n���M�x�n�n�Y�����궺�ܦh�A���o�a�̦����D\n";
	}
	system("pause");
}


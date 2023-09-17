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
	cout << "JoJo一行人在討伐DIO的旅程中，因遭受敵人攻擊，目前在台灣台南的成大附近休息\n";
}

void Event::Event250()
{
	happen[250] = 1;
	cout << "喬瑟夫喬斯達：ㄟ承太郎阿，這間餐廳的鍋燒意麵湯頭都沒味道\n";
	system("pause");
	cout << "喬瑟夫喬斯達：還是去中西區吃飯好了，快去叫其他人\n";
	system("pause");
	cout << "喬瑟夫喬斯達：甚麼!?他們已經先去了!!不揪喔!!\n";
	system("pause");
	cout << "喬瑟夫喬斯達加入了隊伍\n";
	system("pause");
}

void Event::Event251()
{
	if (happen[250] == 0)
	{
		cout << "阿布德爾：喬斯達先生沒跟你在一起嗎?\n";
	}
	else
	{
		happen[251] = 1;
		cout << "阿布德爾：台南真的是找不太到雷店呢\n";
		system("pause");
		cout << "阿布德爾：喬斯達先生，JoJo，要一起吃嗎?\n";
		system("pause");
		cout << "阿布德爾加入了隊伍\n";
	}
	system("pause");
}

void Event::Event252()
{
	if (happen[251] == 0)
	{
		cout << "花京院典明：這家豬排不錯呢，可惜阿布德爾先生不能吃豬\n";
	}
	else
	{
		happen[252] = 1;
		cout << "花京院典明：JoJo，要不要試試台灣的豬排飯?\n";
		system("pause");
		cout << "花京院典明：雖然沒有日本的好吃，但相較起來便宜多了呢\n";
		system("pause");
		cout << "花京院典明加入了隊伍\n";
	}
	system("pause");
}

void Event::Event253()
{
	if (happen[252] == 0)
	{
		cout << "波魯納雷夫：這就是台南最有名的浮水魚羹阿!!\n";
	}
	else
	{
		happen[253] = 1;
		cout << "波魯納雷夫：不!!!我吃錯家了\n";
		system("pause");
		cout << "波魯納雷夫：這家店是二代啊!!!\n";
		system("pause");
		cout << "波魯納雷夫加入了隊伍\n";
	}
	system("pause");
}

void Event::Event300(NovicePlayer **Playlist)
{
	cout << "敬業餐廳\n";
	cout << "★★★\n" ;
	cout << "敬業人的好朋友，阿姨很親切\n";
	system("pause");
	if (happen[300] == 0)
	{
		cout << "敬餐阿姨：同學有填問卷齁~可以跟阿姨領武器喔\n";
		system("pause");
		cout << "大家獲得了破劍和爛護甲\n";
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
	if (b1.win == 1)//贏了
	{
		cout << "大家獲得了生命藥水和魔力藥水\n";
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
		cout << Playlist[0]->getName() << "獲得了新阿姆斯特朗炫風噴射阿姆斯特朗砲\n";
		WeaponItem *a1 = new NeoArmstrongWeapon;
		Playlist[0]->putItem(a1);
		system("pause");
	}
}

void Event::Event901(NovicePlayer **Playlist, int CurrentPlayer)
{
	cout << "空條承太郎：這殺氣...是替身攻擊!!!\n";
	system("pause");
	cout << "???：身手不錯嘛~小子\n";
	system("pause");
	cout << "空條承太郎：渾蛋，報上名來\n";
	system("pause");
	cout << "???：我是擁有""HW""暗示的替身使者，仁暐大魔王\n";
	system("pause");
	cout << "仁暐大魔王：看到我的HW的人，沒有一個能活著\n";
	system("pause");
	cout << "空條承太郎：呀勒呀勒，看來是要用拳頭讓他清醒了\n";
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
	if (b2.win == 1)//贏了
	{
		int r = rand() % 5;
		if (r == 0)//20%掉道具
		{
			cout << "大家獲得了王者之劍\n";
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
		cout << "赤崁樓\n";
		cout << "★★★\n";
		cout << "有學生證可以免費入場\n是借廁所的好所在\n";
	}
	else if (a == 302)
	{
		cout << "陳家汕頭意麵\n";
		cout << "★★★\n";
		cout << "簡單的40塊乾麵+沙茶調味\n";
	}
	else if (a == 303)
	{
		cout << "津屋\n";
		cout << "★★★★\n";
		cout << "60塊鍋燒意麵湯頭甘甜，料也很多\n輸保安路的醇涎坊鍋燒意麵一點\n小大一才吃小茂屋\n";
	}
	else if (a == 304)
	{
		cout << "富士達人日式拉麵\n";
		cout << "★★★\n";
		cout << "160塊以上拉麵，叉燒真的是入口即化\n但價位實在是很高\n(其實育樂街的拉麵就夠滿足我了)\n";
	}
	else if (a == 305)
	{
		cout << "大遠百\n";
		cout << "★★★★\n";
		cout << "在成大附近店家就有再買190塊威秀電影票\n看電影首選\n";
	}
	else if (a == 306)
	{
		cout << "櫻井日本料理\n";
		cout << "★★★\n";
		cout << "60塊炒讚岐烏龍麵蠻特別的，評價而且不錯吃\n有單點也可以吃合菜\n";
	}
	else if (a == 307)
	{
		cout << "極屋牛丼\n";
		cout << "★★\n";
		cout << "90塊牛丼很小碗，好吃但沒說特別好吃\n丼飯還是首推光明街吉木和食\n";
	}
	else if (a == 308)
	{
		cout << "明月麵店\n";
		cout << "★★★\n";
		cout << "35塊麻醬乾麵，看到網路上很推\n結果並沒有特別好吃\n";
	}
	else if (a == 309)
	{
		cout << "落成米糕\n";
		cout << "★★★\n";
		cout << "35塊米糕，看到網路上大推\n結果並沒有特別好吃\n米糕就是要吃保安路的木西米糕店\n";
	}
	else if (a == 310)
	{
		cout << "米香之家\n";
		cout << "★★★\n";
		cout << "80塊豬排飯，普普通通\n豬排沒甚麼味道\n長榮路陳媽媽美食坊的豬排比較好吃\n";
	}
	else if (a == 311)
	{
		cout << "小公園擔仔麵\n";
		cout << "★★★\n";
		cout << "40塊擔仔麵，就是擔仔麵\n但比起貴死人的度小月，我會推薦大家吃這家擔仔麵\n";
	}
	else if (a == 312)
	{
		cout << "呷霸浮水魚羹\n";
		cout << "★★★\n";
		cout << "60塊浮水魚羹\n雖然好吃但是吃不飽，只能當奢侈的點心\n";
	}
	else if (a == 313)
	{
		cout << "雙生綠豆沙\n";
		cout << "★★★\n";
		cout << "40塊綠豆沙牛奶，是冰沙\n我覺得要喝綠豆沙牛奶應該還是忠義路民族路巷子內的等咧粉圓比較賺\n";
	}
	else if (a == 314)
	{
		cout << "義豐冬瓜茶\n";
		cout << "★★★\n";
		cout << "普通的20塊冬瓜茶\n30塊冬瓜牛奶也是普通\n但很有名就是了\n";
	}
	else if (a == 315)
	{
		cout << "蔡三毛豬血攤\n";
		cout << "★★★★\n";
		cout << "雖然他賣豬血但我還沒吃過他的豬血\n20塊肉燥飯推推\n";
	}
	else if (a == 316)
	{
		cout << "度小月\n";
		cout << "★★\n";
		cout << "50塊擔仔麵超小碗\n還是去西門圓環吃小公園擔仔麵比較好\n";
	}
	else if (a == 317)
	{
		cout << "李媽媽民族鍋燒老店\n";
		cout << "★★★\n";
		cout << "80元鍋燒意麵，有點小碗\n果然吃保安路的醇涎坊鍋燒意麵好\n";
	}
	else if (a == 318)
	{
	cout << "張家海水伯棺材板\n";
	cout << "★★★★\n";
	cout << "60元棺材板\n目前只吃過家不雷的，所以無法確定是否最推這家\n";
	}
	else if (a == 319)
	{
	cout << "同記安平豆花\n";
	cout << "★★★★\n";
	cout << "35元豆花，還不錯\n但豆花首推是青年路的清祺素食點心部，第二是東豐路的台南豆花綠豆王\n";
	}
	else if (a == 320)
	{
	cout << "石精臼點心城棺材板\n";
	cout << "★★★\n";
	cout << "60元棺材板\n內餡的味道沒張家海水伯棺材板的濃郁\n";
	}
	else if (a == 321)
	{
	cout << "石精臼牛肉湯\n";
	cout << "★\n";
	cout << "110元牛肉湯沒附飯\n雷\n湯完全沒味道\n還是文章好\n";
	}
	else if (a == 322)
	{
	cout << "馬來峰巴生肉骨茶\n";
	cout << "★★★★\n";
	cout << "100元肉骨茶\n第一次吃肉骨茶覺得超好吃\n但根據馬來西亞人表示好像還少了一味\n";
	}
	else if (a == 323)
	{
	cout << "丹丹漢堡\n";
	cout << "★★★★\n";
	cout << "南部的驕傲\n";
	}
	else if (a == 324)
	{
	cout << "永樂燒肉飯\n";
	cout << "★★★★\n";
	cout << "70塊燒肉飯，有附沙拉\n好吃，但吃不飽\n";
	}
	else if (a == 325)
	{
	cout << "江川肉燥飯\n";
	cout << "★★\n";
	cout << "20塊肉燥飯，配菜不知道價錢怎麼算加三樣菜就變70\n肉燥飯不香，油放太少\n";
	}
	else if (a == 326)
	{
	cout << "阿瑞意麵\n";
	cout << "★★★\n";
	cout << "35塊意麵，有特別的味道\n超多人排隊~~但我覺得沒有好吃到這種程度\n";
	}
	else if (a == 327)
	{
	cout << "凰商號\n";
	cout << "★★★★\n";
	cout << "50元鳳梨冰茶\n熬煮四小時真的是蠻好喝的，但也是有點小奢侈\n";
	}
	else if (a == 328)
	{
	cout << "無名小吃\n";
	cout << "★★★★\n";
	cout << "真的是沒有名字\n25塊肉燥飯跟30塊米糕都很好吃\n很有老店的味道\n";
	}
	else if (a == 329)
	{
	cout << "孔廟\n";
	cout << "★★★\n";
	cout << "有很大很漂亮的庭院\n";
	}
	else if (a == 330)
	{
	cout << "水仙宮古早味鍋燒麵\n";
	cout << "★★★★\n";
	cout << "60元鍋燒意麵\n分量稍少但料很豐富，有炸魚和炸蝦，湯頭也很好喝\n不過鍋燒第一是保安路的醇涎坊鍋燒意麵\n";
	}
	else if (a == 331)
	{
	cout << "阿鳳浮水虱目魚羹\n";
	cout << "★★★★\n";
	cout << "60元虱目魚羹麵\n魚羹裡的魚肉超大塊阿阿\n";
	}
	else if (a == 332)
	{
	cout << "葉鳳浮水虱目魚羹\n";
	cout << "★★★\n";
	cout << "60元虱目魚羹麵\n保安路阿鳳的第二代，感覺魚羹裡的魚肉少了點\n";
	}
	else if (a == 501)
	{
		cout << "等咧粉圓\n";
		cout << "★★★★★\n";
		cout << "飲料首選!!!!!!\n30塊粉圓黑糖水最划算\n40塊粉圓綠豆沙牛奶也很賺\n店內擺設超文青，很適合帶妹子來喝飲料打卡\n";
	}
	else if (a == 502)
	{
		cout << "進福大灣花生糖\n";
		cout << "★★★★★\n";
		cout << "伴手禮首推100塊零嘴包很適合當伴手禮買回家\n有黑芝麻.花生捲.原味顆粒花生糖三種口味\n";
	}
	else if (a == 503)
	{
	cout << "所長茶葉蛋(赤崁店)\n";
	cout << "★★★★★\n";
	cout << "茶葉蛋首推，12塊一顆\n實在是有夠香，整顆蛋都很入味\n";
	}
	else if (a == 504)
	{
	cout << "裕成水果店\n";
	cout << "★★★★★\n";
	cout << "果汁水果冰首推，木瓜牛奶50塊超濃\n水果冰也超好吃，但都100多塊蠻奢侈的\n";
	}
	else if (a == 505)
	{
	cout << "醇涎坊古早味鍋燒意麵\n";
	cout << "★★★★★\n";
	cout << "55塊鍋燒意麵\nCP值最高，湯濃料又多，目前吃過最好吃的鍋燒意麵\n";
	}
	else if (a == 506)
	{
	cout << "木西米糕店\n";
	cout << "★★★★★\n";
	cout << "30元米糕20元肉燥飯\n來台南要吃的傳統小吃首選\n雖然台南好吃的肉燥飯很多，但這家最有味道\n";
	}
	system("pause");
}


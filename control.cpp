#include "pch.h"
#include "control.h"
#include "snake.h"
#include<conio.h>
#include<cstdlib>
control::control()
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//m_coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	//*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	//*m_coor = coor;*/
	/*RECT rect;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetClientRect(hOut, &rect);	*/
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;//控制器屏幕缓冲器信息

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);//获取控制器屏幕缓冲器信息
	m_coor.X = scr.srWindow.Right;//右
	m_coor.Y = scr.srWindow.Bottom;//底部
}

control::~control()
{
}

void control::MainMenu()//菜单
{
	snake* s = new snake;
	unit::gotoxy(s->m_HeadX+20,s->m_HeadY);
	cout << "1.开 始 游 戏";
	system("color F4");
	unit::gotoxy(s->m_HeadX+20, s->m_HeadY + 5);
	cout << "2.游 戏 规 则";
	system("color F4");
	unit::gotoxy(s->m_HeadX+20, s->m_HeadY + 10);
	cout << "3.退 出 游 戏";
	system("color F4");
	char choose;
	choose = _getch();
	if (choose == '1')
	{
		system("CLS");
		Run_game();
	}
	else if (choose == '2')
		
	{
		system("CLS");
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY);
		cout << "1.按W S D A移动,大小写不敏感";
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY + 5);
		cout << "2.按空格可以暂停";
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY + 10);
		cout << "3.当分数超过20分时，通关成功。";
	}
	else if (choose == '3')
	{
		system("CLS");
		cout << "            谢   谢   玩   耍   ！         ";
		exit(1);
	}
	delete s;
}
void control::Run_game()//运行函数
{
	system("color F4");//控制台的颜色和界面颜色，0黑1蓝2绿4红5紫6黄7白A浅绿色F亮白色;
	food* myfood;
	int score = 0;
	myfood = new food;
	myfood->createPos();
	myfood->show();
	
	control mycontrol;
	mycontrol.drawGameArea();
	mycontrol.drawGameInfo();

	snake mysnake;
	mysnake.showSnake();//开始时显示蛇

	char ch;
	ch = _getch();
	while (true)
	{
		/*char key;
		if (_kbhit())//监听键盘，看有没有从键盘输入东西
		{
			key = _getch();
			if (key == KUP || key == KDOWN || key == KLEFT || key == KRIGHT)
			{
				mysnake.changeDirection(key);
			}*/
			//}

		if (mysnake.snakeDeahOrAlive())
		{
			mysnake.showSnake();
			mysnake.changeDirection();
			mysnake.eraseSnake();
			mysnake.move();
			if (mysnake.eatFood(myfood))
			{
				if (unit::score > 20)
				{
					system("CLS");
				
					break;
				}
				mycontrol.drawGameInfo();
			}
		}
		/*else
		{
			setcolor(RED);
			if (score < 6)outtextxy(250, 460, "菜鸟水平");
			if (score >= 6 && score < 12)outtextxy(250, 460, "高手水平");
			if (score >= 12 && score < 20)outtextxy(100, 460, "你骨骼精奇，是个奇才");
		}*/
		else
		{
			system("CLS");//下一页输出
			cout << "Game Over" << endl;
			system("pause>nul");
			system("CLS");
			
			break;
		}
	}
}
void control::drawGameArea()//游戏面积
{
	/*for (int i = unit::KLEFT; i <=  m_coor.X - 2*unit::KLEFT; i++)
	{
		unit::gotoxy(i, unit::KUP);
		cout << "-";
		unit::gotoxy(i, unit::KUP+2);
		cout << "-";
		unit::gotoxy(i, m_coor.Y - 2*unit::KUP);
		cout << "-";
	}
	for (int i = unit::KUP+1; i <= m_coor.Y -1- 2 * unit::KUP; i++)
	{
		unit::gotoxy(unit::KLEFT, i);
		cout << "|";
		unit::gotoxy(m_coor.X - 2 * unit::KLEFT, i);
		cout << "|";
	}*/
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()//游戏信息
{
	//todo
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);

	cout << "游戏名称：贪吃蛇";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);

	cout << "编写者：tianshuang";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);

	cout << "当前得分：" << unit::score;

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);

	cout << "当前关卡：" << unit::level;

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}

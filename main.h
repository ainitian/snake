
//#include "pch.h"
//#include "unit.h"
//#include "food.h"
//#include<graphics.h>//图形库头文件
#pragma once
#include <iostream>
#include "snake.h"
#include "control.h"
#include <conio.h> //getch()的头文件
#include<windows.h>//背景颜色改变头文件
#include<dsound.h>//背景音乐的头文件
#include <mmsystem.h>//背景音乐的头文件
#pragma comment(lib, "WINMM.LIB")//背景音乐的头文件

int main()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//去光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//去光标
	mciSendString(TEXT("open F:/qqmusic/5.wma alias mysong"), NULL, 0, NULL);//背景音乐
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//背景音乐
	//mciSendString(TEXT("close mysong"), NULL, 0, NULL);//关闭背景音乐
	system("color F4");//控制台的颜色和界面颜色，0黑1蓝2绿4红5紫6黄7白A浅绿色F亮白色;
	//food* myfood;
	//int score = 0;
	//myfood = new food;
	//myfood->createPos();
	//myfood->show();
	////Sleep(5000);
	////myfood.erase();
	////system("pause");

	//control mycontrol;
	//mycontrol.drawGameArea();
	//mycontrol.drawGameInfo();
	////Sleep(5000);
	////unit myunit;
	////myunit.show();
	////Sleep(5000);//执行挂起一段时间
	////myunit.erase();

	//snake mysnake;
	//mysnake.showSnake();//开始时显示蛇
	//*mysnake.showSnake();
	//Sleep(5000);
	//mysnake.eraseSnake();
	//getchar();*/
	//*while (true)
	//{
	//	mysnake.move();
	//}*/
	//char ch;
	//ch = _getch();
	//while (true)
	//{
	//	/*char key;
	//	if (_kbhit())//监听键盘，看有没有从键盘输入东西
	//	{
	//		key = _getch();
	//		if (key == KUP || key == KDOWN || key == KLEFT || key == KRIGHT)
	//		{
	//			mysnake.changeDirection(key);
	//		}*/
	//		//}

	//	if (mysnake.snakeDeahOrAlive())
	//	{
	//		mysnake.showSnake();
	//		mysnake.changeDirection();
	//		mysnake.eraseSnake();
	//		mysnake.move();
	//		if (mysnake.eatFood(myfood))
	//		{
	//			if (unit::score >= 20)
	//			{
	//				break;
	//			}
	//			mycontrol.drawGameInfo();
	//		}
	//	}
	//	/*else
	//	{
	//		setcolor(RED);
	//		if (score < 6)outtextxy(250, 460, "菜鸟水平");
	//		if (score >= 6 && score < 12)outtextxy(250, 460, "高手水平");
	//		if (score >= 12 && score < 20)outtextxy(100, 460, "你骨骼精奇，是个奇才");
	//	}*/
	//	else
	//	{
	//		system("CLS");//下一页输出
	//		cout << "Game Over" << endl;
	//		system("pause>nul");
	//		system("CLS");
	//		//system("pause>nul");
	//		break;
	//	}
	//}
	control *mycontrol = new control;
	while (1)
	{
		//stem("CLS");
		mycontrol->MainMenu();//菜单
		system("color 7");//固定屏幕颜色
		unit::level = 1;
		unit::score = 0;
		unit::gotoxy(25, 25);//任意键继续的横纵坐标
		system("echo 任意键继续....&pause>nul");
		system("CLS");//下一页显示
	}
	delete mycontrol;
};


//#include "pch.h"
//#include "unit.h"
//#include "food.h"
//#include<graphics.h>//ͼ�ο�ͷ�ļ�
#pragma once
#include <iostream>
#include "snake.h"
#include "control.h"
#include <conio.h> //getch()��ͷ�ļ�
#include<windows.h>//������ɫ�ı�ͷ�ļ�
#include<dsound.h>//�������ֵ�ͷ�ļ�
#include <mmsystem.h>//�������ֵ�ͷ�ļ�
#pragma comment(lib, "WINMM.LIB")//�������ֵ�ͷ�ļ�

int main()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//ȥ���
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//ȥ���
	mciSendString(TEXT("open F:/qqmusic/5.wma alias mysong"), NULL, 0, NULL);//��������
	mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);//��������
	//mciSendString(TEXT("close mysong"), NULL, 0, NULL);//�رձ�������
	system("color F4");//����̨����ɫ�ͽ�����ɫ��0��1��2��4��5��6��7��Aǳ��ɫF����ɫ;
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
	////Sleep(5000);//ִ�й���һ��ʱ��
	////myunit.erase();

	//snake mysnake;
	//mysnake.showSnake();//��ʼʱ��ʾ��
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
	//	if (_kbhit())//�������̣�����û�дӼ������붫��
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
	//		if (score < 6)outtextxy(250, 460, "����ˮƽ");
	//		if (score >= 6 && score < 12)outtextxy(250, 460, "����ˮƽ");
	//		if (score >= 12 && score < 20)outtextxy(100, 460, "��������棬�Ǹ����");
	//	}*/
	//	else
	//	{
	//		system("CLS");//��һҳ���
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
		mycontrol->MainMenu();//�˵�
		system("color 7");//�̶���Ļ��ɫ
		unit::level = 1;
		unit::score = 0;
		unit::gotoxy(25, 25);//����������ĺ�������
		system("echo ���������....&pause>nul");
		system("CLS");//��һҳ��ʾ
	}
	delete mycontrol;
};

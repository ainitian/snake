#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '%');//食物初始化为*
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	static const int KLEFT = 2;//地图距离左边框的距离
	static const int KUP = 1;//地图距离上边框的距离
	static const int KWIDTH = 70;//地图宽度
	static const int KHEIGHT = 20;//地图高度
	int m_x;//随机生成食物的横坐标
	int m_y;//随机生成食物的纵坐标
	char m_pic;//蛇形状定义
	static int score;//分数
	static int level;//等级
};



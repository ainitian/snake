#pragma once
#include <Windows.h>
class control
{
public:
	COORD m_coor;//字符在控制台屏幕上的坐标
public:

	control();
	~control();
	void drawGameArea();//游戏面积
	void drawGameInfo();//游戏信息
	void MainMenu();//菜单函数
	void Run_game();//运行函数
//public:
//	static const int kleft = 100;//界面左边界距离窗口的距离
//	static const int kup = 80;//界面上边界距离窗口的距离
//	static const int kwidth = 100;//窗口的宽度
//	static const int kheight = 100;//窗口的高度
//	static const int kscore_offset = 80;//最高得分
//	static const int klevel_offset = 5;//总关卡
//	int i;
//	int j;//这部分内容定义在unit.h里面
};
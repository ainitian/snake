#pragma once
#include <vector>
//#include "unit.h"
#include "food.h"
typedef enum Dir//enum枚举
{
	KUP,
	KDOWN,
	KLEFT,
	KRIGHT
};
class snake
{
public:
	int m_HeadX;//蛇开始出现的横坐标
	int m_HeadY;//蛇开始出现的纵坐标
	int m_Len;//蛇的长度
	int m_Speed;//蛇移动的速度
	char pic;
	Dir m_Dir;//蛇开始移动的方向
	vector<unit> m_Body;
public:
	snake(int x = 30, int y = 10, int len = 4, int speed = 100, Dir dir = KRIGHT, char pic = '#');//pic蛇形状
	~snake();
	void showSnake();//显示蛇
	void eraseSnake();//擦除蛇
	void move();//蛇移动
	void changeDirection();//蛇移动方向控制
	bool eatFood(food* food);//蛇吃食物
	bool snakeDeahOrAlive();//蛇的生死
};

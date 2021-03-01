#pragma once
#include <vector>
//#include "unit.h"
#include "food.h"
typedef enum Dir//enumö��
{
	KUP,
	KDOWN,
	KLEFT,
	KRIGHT
};
class snake
{
public:
	int m_HeadX;//�߿�ʼ���ֵĺ�����
	int m_HeadY;//�߿�ʼ���ֵ�������
	int m_Len;//�ߵĳ���
	int m_Speed;//���ƶ����ٶ�
	char pic;
	Dir m_Dir;//�߿�ʼ�ƶ��ķ���
	vector<unit> m_Body;
public:
	snake(int x = 30, int y = 10, int len = 4, int speed = 100, Dir dir = KRIGHT, char pic = '#');//pic����״
	~snake();
	void showSnake();//��ʾ��
	void eraseSnake();//������
	void move();//���ƶ�
	void changeDirection();//���ƶ��������
	bool eatFood(food* food);//�߳�ʳ��
	bool snakeDeahOrAlive();//�ߵ�����
};

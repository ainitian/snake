#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '%');//ʳ���ʼ��Ϊ*
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	static const int KLEFT = 2;//��ͼ������߿�ľ���
	static const int KUP = 1;//��ͼ�����ϱ߿�ľ���
	static const int KWIDTH = 70;//��ͼ���
	static const int KHEIGHT = 20;//��ͼ�߶�
	int m_x;//�������ʳ��ĺ�����
	int m_y;//�������ʳ���������
	char m_pic;//����״����
	static int score;//����
	static int level;//�ȼ�
};



#pragma once
#include <Windows.h>
class control
{
public:
	COORD m_coor;//�ַ��ڿ���̨��Ļ�ϵ�����
public:

	control();
	~control();
	void drawGameArea();//��Ϸ���
	void drawGameInfo();//��Ϸ��Ϣ
	void MainMenu();//�˵�����
	void Run_game();//���к���
//public:
//	static const int kleft = 100;//������߽���봰�ڵľ���
//	static const int kup = 80;//�����ϱ߽���봰�ڵľ���
//	static const int kwidth = 100;//���ڵĿ��
//	static const int kheight = 100;//���ڵĸ߶�
//	static const int kscore_offset = 80;//��ߵ÷�
//	static const int klevel_offset = 5;//�ܹؿ�
//	int i;
//	int j;//�ⲿ�����ݶ�����unit.h����
};
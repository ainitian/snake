#include "unit.h"

int unit::score = 0;
int unit::level = 1;

unit::unit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
}


unit::~unit()
{
}

void unit::show()
{
	gotoxy(m_x, m_y);
	cout << m_pic;
}

void unit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}

void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x;
	position.Y = y;
	//�����������Ȼ��ʼ��ӡ
	SetConsoleCursorPosition(screen, position);//���ÿ���̨���λ��
}


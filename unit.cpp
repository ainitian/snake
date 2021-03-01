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
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);//设置控制台光标位置
}


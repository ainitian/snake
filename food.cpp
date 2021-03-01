#include "pch.h"
#include "food.h"
//#include<ctime>
//const int N = 60;
//int m[N][N];
food::food()
{
}

void food::createPos()//随机生成食物
{
	//srand(int(time(0))); //种子函数
	//do {
	//	dx = rand() % 20 + 1;
	//	dy = rand() % 20 + 1;
	//} while (m[dx][dy] != ' ');
	//m[dx][dy] = '*';

	//todo;
	//m_x = randromNum();
	//m_y = randromNum();
	srand((int)time(0));
	m_x = KLEFT + 1 + rand() % (KWIDTH - 4);//左右区间
	m_y = KUP + 3 + rand() % (KHEIGHT - 8);//上下区间
	

}
food::~food()
{
}

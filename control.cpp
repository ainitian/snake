#include "pch.h"
#include "control.h"
#include "snake.h"
#include<conio.h>
#include<cstdlib>
control::control()
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//m_coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // �رձ�׼����豸���
	//*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	//*m_coor = coor;*/
	/*RECT rect;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetClientRect(hOut, &rect);	*/
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;//��������Ļ��������Ϣ

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
	GetConsoleScreenBufferInfo(hOut, &scr);//��ȡ��������Ļ��������Ϣ
	m_coor.X = scr.srWindow.Right;//��
	m_coor.Y = scr.srWindow.Bottom;//�ײ�
}

control::~control()
{
}

void control::MainMenu()//�˵�
{
	snake* s = new snake;
	unit::gotoxy(s->m_HeadX+20,s->m_HeadY);
	cout << "1.�� ʼ �� Ϸ";
	system("color F4");
	unit::gotoxy(s->m_HeadX+20, s->m_HeadY + 5);
	cout << "2.�� Ϸ �� ��";
	system("color F4");
	unit::gotoxy(s->m_HeadX+20, s->m_HeadY + 10);
	cout << "3.�� �� �� Ϸ";
	system("color F4");
	char choose;
	choose = _getch();
	if (choose == '1')
	{
		system("CLS");
		Run_game();
	}
	else if (choose == '2')
		
	{
		system("CLS");
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY);
		cout << "1.��W S D A�ƶ�,��Сд������";
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY + 5);
		cout << "2.���ո������ͣ";
		unit::gotoxy(s->m_HeadX + 10, s->m_HeadY + 10);
		cout << "3.����������20��ʱ��ͨ�سɹ���";
	}
	else if (choose == '3')
	{
		system("CLS");
		cout << "            л   л   ��   ˣ   ��         ";
		exit(1);
	}
	delete s;
}
void control::Run_game()//���к���
{
	system("color F4");//����̨����ɫ�ͽ�����ɫ��0��1��2��4��5��6��7��Aǳ��ɫF����ɫ;
	food* myfood;
	int score = 0;
	myfood = new food;
	myfood->createPos();
	myfood->show();
	
	control mycontrol;
	mycontrol.drawGameArea();
	mycontrol.drawGameInfo();

	snake mysnake;
	mysnake.showSnake();//��ʼʱ��ʾ��

	char ch;
	ch = _getch();
	while (true)
	{
		/*char key;
		if (_kbhit())//�������̣�����û�дӼ������붫��
		{
			key = _getch();
			if (key == KUP || key == KDOWN || key == KLEFT || key == KRIGHT)
			{
				mysnake.changeDirection(key);
			}*/
			//}

		if (mysnake.snakeDeahOrAlive())
		{
			mysnake.showSnake();
			mysnake.changeDirection();
			mysnake.eraseSnake();
			mysnake.move();
			if (mysnake.eatFood(myfood))
			{
				if (unit::score > 20)
				{
					system("CLS");
				
					break;
				}
				mycontrol.drawGameInfo();
			}
		}
		/*else
		{
			setcolor(RED);
			if (score < 6)outtextxy(250, 460, "����ˮƽ");
			if (score >= 6 && score < 12)outtextxy(250, 460, "����ˮƽ");
			if (score >= 12 && score < 20)outtextxy(100, 460, "��������棬�Ǹ����");
		}*/
		else
		{
			system("CLS");//��һҳ���
			cout << "Game Over" << endl;
			system("pause>nul");
			system("CLS");
			
			break;
		}
	}
}
void control::drawGameArea()//��Ϸ���
{
	/*for (int i = unit::KLEFT; i <=  m_coor.X - 2*unit::KLEFT; i++)
	{
		unit::gotoxy(i, unit::KUP);
		cout << "-";
		unit::gotoxy(i, unit::KUP+2);
		cout << "-";
		unit::gotoxy(i, m_coor.Y - 2*unit::KUP);
		cout << "-";
	}
	for (int i = unit::KUP+1; i <= m_coor.Y -1- 2 * unit::KUP; i++)
	{
		unit::gotoxy(unit::KLEFT, i);
		cout << "|";
		unit::gotoxy(m_coor.X - 2 * unit::KLEFT, i);
		cout << "|";
	}*/
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()//��Ϸ��Ϣ
{
	//todo
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);

	cout << "��Ϸ���ƣ�̰����";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);

	cout << "��д�ߣ�tianshuang";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);

	cout << "��ǰ�÷֣�" << unit::score;

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);

	cout << "��ǰ�ؿ���" << unit::level;

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}

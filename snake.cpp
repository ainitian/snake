#include "snake.h"
#include "pch.h"
#include "conio.h"//getch()��ͷ�ļ�
#include "unit.h"
#include "control.h"
//#include<graphics.h>//ͼ�ο�ͷ�ļ�

snake::snake(int x, int y, int len, int speed, Dir dir, char pic)
{
	m_HeadX = x;
	m_HeadY = y;
	m_Len = len;
	m_Speed = speed;
	m_Dir = dir;
	this->pic = pic;

	for (int i = 0; i < m_Len; i++)
	{
		unit myUnit(0, 0, pic);
		m_Body.push_back(myUnit);
		switch (dir)
		{
		case KUP:
			m_Body[i].m_x = m_HeadX;
			m_Body[i].m_y = m_HeadY + i;
			break;
		case KDOWN:
			m_Body[i].m_x = m_HeadX;
			m_Body[i].m_y = m_HeadY - i;
			break;
		case KLEFT:
			m_Body[i].m_x = m_HeadX + i;
			m_Body[i].m_y = m_HeadY;
			break;
		case KRIGHT:
			m_Body[i].m_x = m_HeadX - i;
			m_Body[i].m_y = m_HeadY;
			break;
		default:
			break;
		}
	}
}

void snake::changeDirection()//wasd�ı��ߵ��˶�����
{
	//��ȡ��ǰ��ͷ��λ��
	//int x = m_HeadX;
	//int y = m_HeadY;
	char key;
	if (_kbhit())
	{
		key = _getch();
		if (key == ' ')
		{
			system("pause>nul");//���ո����ͣ			
		}
		switch (key)
		{
		case 'w':
		case 'W'://72���õ�����
			if (m_Dir == KDOWN)
			{
				break;
			}
			m_Dir = KUP;
			break;
		case 's':
		case 'S'://80
			if (m_Dir == KUP)
			{
				break;
			}
			m_Dir = KDOWN;
			break;
		case 'a':
		case 'A'://75
			if (m_Dir == KRIGHT)
			{
				break;
			}
			m_Dir = KLEFT;
			break;
		case 'd':
		case 'D'://77
			if (m_Dir == KLEFT)
			{
				break;
			}
			m_Dir = KRIGHT;
		default:
			break;
		}
	}

}

void snake::showSnake()//��ʾ��
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].show();
	}
}

void snake::eraseSnake()//������
{
	for (int i = 0; i < m_Len; i++)
	{
		m_Body[i].erase();
	}
}
void snake::move()//���ƶ�
{
	//ʵ��������ƶ�
	/*for (int i = m_Len - 1; i > 0; i--)
	{
		m_Body[i].m_x = m_Body[i - 1].m_x;
		m_Body[i].m_y = m_Body[i].m_y;

	}*/
	vector<unit> head = m_Body;
	//ʵ����ͷ���ƶ�
	switch (m_Dir)
	{
	case KUP:
		head[0].m_y--;
		break;
	case KDOWN:
		head[0].m_y++;
		break;
	case KLEFT:
		head[0].m_x--;
		break;
	case KRIGHT:
		head[0].m_x++;
		break;
	default:
		break;
	}
	m_Body.insert(m_Body.begin(), head[0]);//���µ���ͷ���뵽����ͷ��
	//m_Body.erase(m_Body.end() - 1);
	showSnake();
	Sleep(m_Speed);
	eraseSnake();
}

bool snake::eatFood(food* food)//�߳�ʳ��
{
	if (m_Body[0].m_x == food->m_x && m_Body[0].m_y == food->m_y)//�Ե�ʳ��
	{
		m_Len++;//����+1
		if (unit::score >= 0 && unit::score < 6)
		{
			unit::score += 2;//����+2
			unit::level = 1;
		}
		if (unit::score >= 6 && unit::score <= 12)
		{
			unit::score += 3;//����+3
			unit::level = 2;//�ȼ�+1
			snake::m_Speed -= 20;//�ٶȼӿ�

		}
		if (unit::score > 12 && unit::score <= 20)
		{
			unit::score += 4;//����+4
			unit::level = 3;
			snake::m_Speed -= 10;
		}
		if (unit::score > 20)
		{
			unit::gotoxy(m_HeadX + 10, m_HeadY);
			cout << "���سɹ�" << endl;
			system("pause>nul");
		}
		while (1)
		{
			food->createPos();//�ٴ���һ��ʳ��
			for (int i = 1; i < m_Len; i++)
			{
				if (food->m_x != m_Body[i].m_x && food->m_y != m_Body[i].m_y)//ʳ�������غ�
				{
					food->show();
					return 1;
				}
				else if (food->m_x == m_Body[i].m_x && food->m_y == m_Body[i].m_y)
				{
					break;
				}
			}
			
		}
		//food->createPos();//�ٴ���һ��ʳ��
		//food->show();//��ʾʳ��
		//return 1;
	}
	else
	{
		m_Body.erase(m_Body.end() - 1);
		return 0;
	}
}


bool snake::snakeDeahOrAlive()//�ж����������Ǵ��
{
	if (m_Body[0].m_x <= 2 || m_Body[0].m_x == 71 || m_Body[0].m_y == 3 || m_Body[0].m_y == 22)//�Ե���ͼ
	{
		return 0;
		/*judge();*/
	}
	for (int i = 1; i < m_Len; i++)
	{
		if (m_Body[0].m_x == m_Body[i].m_x && m_Body[0].m_y == m_Body[i].m_y)//�Ե��Լ�
		{
			return 0;
			/*judge();*/
		}
	}
	return 1;
}

snake::~snake()
{

}


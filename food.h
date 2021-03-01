#pragma once
#include "unit.h"
#include <cstdlib>
#include <ctime>

class food :
	public unit
{
public:

	food();
	~food();
	void createPos();//随机生成食物
};





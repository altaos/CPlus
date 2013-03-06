#pragma once

#include"Man.h"
#include<set>

class BusStop
{
private:
	string name;//Название остановки
	set<Man> men;//Список людей на остановке
public:
	BusStop(string name);
	~BusStop(void);

	bool AddMan(Man man);//Добавление человека на остановку
};


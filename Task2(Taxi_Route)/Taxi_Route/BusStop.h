#pragma once

#include"Man.h"
#include<set>

class BusStop
{
private:
	string name;		//Название остановки
	set<Man*> men;		//Список людей на остановке
public:
	BusStop(string name);
	BusStop(void);
	~BusStop(void);

	void AddMan(Man* man);		//Добавление человека на остановку
	void PrintSetMen() const;	//Выводит на консоль список людей на остановке
};


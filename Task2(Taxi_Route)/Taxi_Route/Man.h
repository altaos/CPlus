#pragma once

#include<string>
#include<iostream>
#include"Route.h"

using namespace std;

class Man
{
private:
	string goalBusStop;				//Конечная остановка
public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalBusStop() const;				//Получить конечную остановку
	void Print() const;							//Вывести одного человека на консоль
	bool CheckRoute(const Route& route) const;	//Проверка, есть ли в маршруте автобуса нужная остановка
};


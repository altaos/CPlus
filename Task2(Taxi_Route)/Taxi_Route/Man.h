#pragma once

#include<string>
#include<iostream>

using namespace std;

class Man
{
private:
	string goalBusStop; //Конечная остановка
public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalBusStop() const;//Получить конечную остановку
};


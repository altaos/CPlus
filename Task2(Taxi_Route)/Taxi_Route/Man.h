#pragma once

#include<string>

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


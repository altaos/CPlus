#pragma once

#include<string>
#include<set>

using namespace std;

class Man
{
private:
	string goalBusStop;											//Конечная остановка

public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalStop() const;									//Получить конечную остановку
	bool CheckIsThereGoalBusStop(const set<string>* route);			//Проверить, есть ли необходимая остановка в маршруте автобуса
	bool IsItGoalBusStop(string busStop);						//Проверить, является ли данноя остановка необходимой
};


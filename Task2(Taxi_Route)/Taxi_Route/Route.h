#pragma once

#include<string>
#include<map>
#include<set>
#include<vector>
#include"BusStop.h"

using namespace std;

class BusStop;

class Route
{
private:
	string name;													//Номер маршрута
	map<string, BusStop*> busStops;									//Коллекция остановок <название остановки, остановка*>
	set<string> busStopsNames;										//Список названий остановок маршрута

public:
	Route(string name);
	Route(string name, int* arr, int size, vector<BusStop*>* bStop);
	~Route(void);

	string GetName() const;
	void AddBusStop(BusStop* busStop);								//Добавление остановки в маршрут
	const map<string, BusStop*>* GetBusStops() const;				//Получить список остановок маршрута для чтения
	const set<string>* GetBusStopsNames() const;					//Получить список названий остановок
};


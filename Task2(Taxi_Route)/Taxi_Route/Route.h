#pragma once

#include"BusStop.h"
#include<map>

enum DIRECT { FOWARD, REVERSE};

class Route
{
private:
	string name;
	map<string, BusStop*> busStops;								//Список остановок
	map<string, BusStop*>::iterator route_iterator;				//Итератор, указывающий на текущую остановку
public:
	Route(string name, map<string, BusStop*>& busStops);
	Route(const Route& r);
	Route(void);
	~Route(void);
	Route& Route::operator=(const Route& r);

	string GetName() const;										//Возвращает название маршрута
	map<string, BusStop*>::iterator GetIterator() const;		//Возвращает итератор на текущую остановку
	void ChangeIterator(DIRECT& direct);						//Изменение  итератора при передвижении автобуса
	const map<string, BusStop*>* GetBusStops() const;			//Возвращает список остановок
};


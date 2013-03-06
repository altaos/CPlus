#pragma once

#include"BusStop.h"
#include<map>

class Route
{
private:
	string name;
	map<string, BusStop> busStops;
public:
	Route(string name, map<string, BusStop>& busStops);
	~Route(void);

	string GetName() const; //Возвращает название маршрута
};


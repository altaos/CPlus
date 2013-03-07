#include "stdafx.h"
#include "Route.h"


Route::Route(string name, map<string, BusStop*>& busStops)
{
	route_iterator = busStops.begin;
	this->name = name;
	this->busStops = busStops;
}

Route::Route(const Route& r)
{
	name = r.name;
	busStops = r.busStops;
	route_iterator = busStops.begin();
}

Route& Route::operator=(const Route& r)
{
	if(this != &r)
	{
		name = r.name;
		busStops = r.busStops;
		route_iterator = busStops.begin();
	}
	return *this;
}

Route::Route(void)
{
}

Route::~Route(void)
{
}

//Возвращает название маршрута
string Route::GetName() const
{
	return name;
}

//Возвращает итератор на текущую остановку
map<string, BusStop*>::iterator Route::GetIterator() const
{
	return route_iterator;
}

//Изменение итератора
bool Route::ChangeIterator(DIRECT& direct)
{
	switch (direct)
	{
	case FOWARD: 
		route_iterator++;
		if(route_iterator == busStops.end())
			direct = REVERSE;
		break;
	case REVERSE: 
		route_iterator--;
		if(route_iterator == busStops.begin())
			direct = FOWARD;
		break;
	default:
		break;
	}
}

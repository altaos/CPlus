// Taxi_Route.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Bus.h"



int _tmain(int argc, _TCHAR* argv[])
{
	//Создаем остановки
	BusStop bs1("BusStop1");
	BusStop bs2("BusStop2");
	BusStop bs3("BusStop3");
	BusStop bs4("BusStop4");

	//Создаем map остановок и маршрут
	map<string, BusStop*> busStops;
	busStops.insert(pair<string, BusStop*>("BusStop1", &bs1));
	busStops.insert(pair<string, BusStop*>("BusStop2", &bs2));
	busStops.insert(pair<string, BusStop*>("BusStop3", &bs3));
	busStops.insert(pair<string, BusStop*>("BusStop4", &bs4));
	Route new_route("27", busStops);

	//Создание автобуса
	Bus bus(new_route);

	return 0;
}


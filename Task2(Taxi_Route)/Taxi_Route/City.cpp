#include "stdafx.h"
#include "City.h"
#include "LittleBus.h"
#include "MiddleBus.h"
#include "BigBus.h"
#include "Man.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define BusStopsCount 12

City::City(void)
{

}


City::~City(void)
{
	for(vector<Man*>::iterator it = men.begin(); it != men.end(); it++)
		delete *it;
	for(vector<Bus*>::iterator it = buses.begin(); it != buses.end(); it++)
		delete *it;
	for(vector<Route*>::iterator it = routes.begin(); it != routes.end(); it++)
		delete *it;
	for(vector<BusStop*>::iterator it = busStops.begin(); it != busStops.end(); it++)
		delete *it;
}

//Создание остановок
void City::CreatingBusStops()
{
	for(int i = 1; i < BusStopsCount; i++) 
	{
		busStops.push_back(new BusStop(to_string(i)));
	}
}

//Создание маршрутов
void City::CreatingRoutes()
{
	int r1[8] = {1, 2, 3, 8, 7, 10, 9, 4};
	int r2[7] = {6, 5, 8, 9, 10, 3, 7};
	int r3[6] = {1, 5, 7, 9, 4, 3};
	int r4[5] = {6, 8, 4, 3, 2};

	routes.push_back(new Route(to_string(80), r1, 8, &busStops));
	routes.push_back(new Route(to_string(27), r2, 7, &busStops));
	routes.push_back(new Route(to_string(95), r3, 6, &busStops));
	routes.push_back(new Route(to_string(90), r4, 5, &busStops));
}

void City::CreatingBuses(int count)
{
	int i = 0, k = 0;
	srand(time(NULL));

	for(int j = 0; j < count; j++)
	{
		i = rand() % routes.size();
		k = rand() % 3;
		switch(k)
		{
		case 0:
			buses.push_back(new LittleBus(routes[i], routes[i]->GetName()));
			break;
		case 1:
			buses.push_back(new MiddleBus(routes[i], routes[i]->GetName()));
			break;
		case 2:
			buses.push_back(new BigBus(routes[i], routes[i]->GetName()));
			break;
		}
	}
}

void City::CreatingMen(int count)
{
	int intRand = 0;
	srand(time(NULL));

	for(int i = 0; i < count; i++)
	{
		//Нужная остановка
		intRand = rand() % busStops.size(); 
		Man* m = new Man(busStops[intRand]->GetName());

		//Начальная остановка
		do
		{
			intRand = rand() % busStops.size();
		}
		while (busStops[intRand]->GetName() == m->GetGoalStop());//Чтобы начальная и конечная остановки не совпадали

		men.push_back(m);

		busStops[intRand]->AddManIn(m);
	}
}

void City::onTimer()
{
	for(vector<Bus*>::iterator it = buses.begin(); it != buses.end(); it++)
	{
		//Передвижение автобуса на новую остановку
		(*it)->Move();
		//Выход пассажиров, если необходимо
		(*it)->CheckPassengers();
		//Проверка пассажирами автобуса, посадка
		(*it)->GetCurrentBusStop()->CheckAndSeatIntoBus(*it);
		//Создание людей
		CreatingMen(deltaMen);
	}

	for(int i = 0; i < busStops.size(); i++)
		cout << *(busStops[i]);

	for(int i = 0; i < buses.size(); i++)
		cout << *(buses[i]);
}

void City::SetDeltaMen(int deltaMen)
{
	this->deltaMen = deltaMen;
}

#pragma once

#include<vector>

using namespace std;

class BusStop;
class Bus;
class Route;
class Man;

class City
{
private:
	vector<BusStop*> busStops;							//Вектор остановок города
	vector<Bus*> buses;									//Вектор автобусов
	vector<Route*> routes;								//Вектор маршрутов
	vector<Man*> men;									//Вектор людей
	int deltaMen;

public:
	City(void);
	~City(void);

	void onTimer();

	void CreatingBusStops();
	void CreatingRoutes();
	void CreatingBuses(int count);
	void CreatingMen(int count);
	void SetDeltaMen(int deltaMen);
	
};


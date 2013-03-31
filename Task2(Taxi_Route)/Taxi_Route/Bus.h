#pragma once

#include"Route.h"
#include <vector>

class Man;
class Route;

enum Direct { Forward, Reverse};

class Bus
{
protected:
	string name;
	Route* route;													//Маршрут
	map<string, BusStop*>::const_iterator current_stop;				//Текущая остановка
	Direct direction;												//Направление
	int total_number_of_seats;										//Общее количество мест в автобусе
	int number_of_free_seats;										//Количество свободных мест
	vector<Man*> men;

public:
	Bus(Route* route, string name);
	virtual ~Bus(void);

	void Move();													//Передвижение автобуса на следующую остановку
	int GetTotalNumberOfSeats() const;								//Получить общее количество мест
	int GetNuberOfFreeSeats() const;								//Получить количество свободных мест
	string GetName() const;											//Получить название автобуса
	string GetCurrentBusStopName() const;								//Получить название текущей остановки
	BusStop* GetCurrentBusStop();
	string GetDirection() const;									//Получить направление движения автобус
	void AddMan(Man* man);											//Добавить человека
	void CheckPassengers();											//Проверить пассажиров при передвижении на новую остановку и выхо пассажиров
	const set<string>* GetRoute() const;							//Получить список названий остановок маршрута

	friend ostream& operator<<(istream& os, const Bus& bus);
};

ostream& operator<<(ostream& os, Bus& bus);

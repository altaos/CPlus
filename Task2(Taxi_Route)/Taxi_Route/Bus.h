#pragma once

#include"Route.h"

class Bus
{
private:
	string name;
	Route route;				//Маршрут
	set<Man*> men;				//Список людей в автобусе
	int total_number_of_seats;	//Количество мест всего в автобусе
	int number_of_free_seats;	//Количество свободных мест
	BusStop* current_busStop;	//Текущая остановка
	DIRECT direction;			//Направление движения
public:
	Bus(const Route& route);
	~Bus(void);

	BusStop* GetCurrentBusStop() const;	//Получить указатель на текущую остановку автобуса
	void PrintSetMen() const;			//Вывести список пассажиров
	void Move();						//Передвигает автобус на следующую остановку
	//void CheckBusStop();				//Проверка текущей остановки пассажирами
};


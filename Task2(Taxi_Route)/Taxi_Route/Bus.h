#pragma once

#include"Route.h"

class Bus
{
private:
	string name;
	Route route;
	set<Man> men;
	int total_number_of_seats;
	int number_of_free_seats;
	BusStop* current_busStop;
	DIRECT direction;//Направление движения
public:
	Bus(const Route& route);
	~Bus(void);

	BusStop* GetCurrentBusStop() const;
	void Move();
};


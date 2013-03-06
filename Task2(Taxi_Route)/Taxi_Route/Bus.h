#pragma once

#include"Route.h"

enum DIRECT { FOWARD, REVERSE};

class Bus
{
private:
	string name;
	Route& route;
	set<Man> men;
	int total_number_of_seats;
	int number_of_free_seats;
	BusStop current_busStop;
	DIRECT direction;//Направление движения
public:
	Bus(Route& route, DIRECT direction);
	~Bus(void);
};


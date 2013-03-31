#include "stdafx.h"
#include "BusStop.h"
#include"Man.h"
#include"Bus.h"


BusStop::BusStop(string name)
{
	this->name = name;
}


BusStop::~BusStop(void)
{
}

//Получить название остановки
string BusStop::GetName() const
{
	return name;
}

//Добавить человека на остановку
void BusStop::AddManIn(Man *man)
{
	if(man != NULL)
		men.push_back(man);
}

//Добавить приехавшего человека на остановку
void BusStop::AddManOut(Man *man)
{
	if(man != NULL)
		menOut.push_back(man);
}

//Проверить людей на остановке на посадку
void BusStop::CheckAndSeatIntoBus(Bus *bus)
{
	int i = 0;
	while(i < men.size())
	{
		//Есть ли в маршруте автобуса необходимая остановка, и есть ли в автобусе свободные места
		if(men[i]->CheckIsThereGoalBusStop(bus->GetRoute()) && (bus->GetNuberOfFreeSeats() > 0))
		{
			bus->AddMan(men[i]);
			men.erase(men.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

int BusStop::GetMenCount() const
{
	return men.size();
}

ostream& operator<< (ostream& os, BusStop& busStop)
{
	os<<"name : "<<busStop.GetName()<<" Count of people : "<<busStop.GetMenCount()<<endl<<endl;

	return os;
}
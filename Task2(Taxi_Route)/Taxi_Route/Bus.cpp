#include "stdafx.h"
#include "Bus.h"


Bus::Bus(const Route& route)
{
	this->route = route;//Копирование маршрута
	current_busStop = this->route.GetIterator()->second;//Текущая остановка - первая в маршруте
	direction = FOWARD;//Направление движения
}


Bus::~Bus(void)
{
}

//Возврат текущей остановки
BusStop* Bus::GetCurrentBusStop() const
{
	return current_busStop;
}

//Передвигает автобус на следующую остановку
void Bus::Move()
{
	route.ChangeIterator(direction);
	cout<<"Bus number is "<<name<<" Current busStop is "<<route.GetIterator()->first<<" Direction is "<<direction<<endl;
}

void Bus::PrintSetMen() const
{
	for(set<Man*>::iterator it = men.begin(); it != men.end(); it++)
		(*it)->Print();
}

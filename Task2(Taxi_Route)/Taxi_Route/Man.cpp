#include "stdafx.h"
#include "Man.h"


Man::Man(string goalBusStop)
{
	this->goalBusStop = goalBusStop;
}


Man::~Man(void)
{
}

//�������� �������� ���������
string Man::GetGoalBusStop() const
{
	return goalBusStop;
}

void Man::Print() const
{
	cout<<"### Goal: "<<goalBusStop<<endl;
}

//��������, ���� �� � �������� �������� ������ ���������
bool Man::CheckRoute(const Route& route) const
{
	map<string, BusStop*>::const_iterator it = route.GetBusStops()->begin();
	while(it != route.GetBusStops()->end() && it->first != goalBusStop) it++;

	if(it == route.GetBusStops()->end)
		return false;

	return true;
}
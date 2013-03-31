#include "stdafx.h"
#include "Bus.h"
#include "Man.h"

Bus::Bus(Route* route, string name)
{
	this->name = name;
	this->route = route;
	direction = Forward;
	current_stop = route->GetBusStops()->begin();
}


Bus::~Bus(void)
{
}

//������������ �������� �� ��������� ���������
void Bus::Move()
{
	switch (direction)
	{
	case Forward: 
		current_stop++;
		if(current_stop == route->GetBusStops()->end())
		{
			direction = Reverse;
			current_stop--;
		}
		break;
	case Reverse: 
		current_stop--;
		if(current_stop == route->GetBusStops()->begin())
			direction = Forward;
		break;
	default:
		break;
	}
}

//�������� ���������� ��������� ����
int Bus::GetNuberOfFreeSeats() const
{
	return number_of_free_seats;
}

//�������� ����� ���������� ����
int Bus::GetTotalNumberOfSeats() const
{
	return total_number_of_seats;
}

//�������� �������� ��������
string Bus::GetName() const
{
	return name;
}

//�������� �������� ������� ���������
string Bus::GetCurrentBusStopName() const
{
	return current_stop->first;
}

BusStop* Bus::GetCurrentBusStop()
{
	return current_stop->second;
}

//�������� ����������� �������� ��������
string Bus::GetDirection() const
{
	if(direction == Forward)
		return "Forward";
	else
		return "Reverse";
}

//�������� �������� � �������
void Bus::AddMan(Man* man)
{
	if(man != NULL)
	{
		men.push_back(man);
		number_of_free_seats--;
	}
}

//��������� ���������� ��� ������������ �� ����� ��������� � ����� ����������
void Bus::CheckPassengers()
{
	int i = 0;
	while(i < men.size())
	{
		if(current_stop->first.compare(men[i]->GetGoalStop()) == 0)
		{
			number_of_free_seats++;
			current_stop->second->AddManOut((men[i]));
			men.erase(men.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

//�������� ������ �������� ��������� ��������
const set<string>* Bus::GetRoute() const
{
	return route->GetBusStopsNames();
}

ostream& operator<< (ostream& os, Bus& bus)
{
	string name = bus.GetCurrentBusStopName();
	os<<"name : "<<bus.GetName()<<" current bus stop : "<<name<<" Total seats : "<<bus.GetTotalNumberOfSeats();
	os<<" Free seats : "<<bus.GetNuberOfFreeSeats()<<endl;

	return os;
}
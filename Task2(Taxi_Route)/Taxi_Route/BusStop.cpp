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

//�������� �������� ���������
string BusStop::GetName() const
{
	return name;
}

//�������� �������� �� ���������
void BusStop::AddManIn(Man *man)
{
	if(man != NULL)
		men.push_back(man);
}

//�������� ����������� �������� �� ���������
void BusStop::AddManOut(Man *man)
{
	if(man != NULL)
		menOut.push_back(man);
}

//��������� ����� �� ��������� �� �������
void BusStop::CheckAndSeatIntoBus(Bus *bus)
{
	int i = 0;
	while(i < men.size())
	{
		//���� �� � �������� �������� ����������� ���������, � ���� �� � �������� ��������� �����
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
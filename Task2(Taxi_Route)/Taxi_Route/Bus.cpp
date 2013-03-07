#include "stdafx.h"
#include "Bus.h"


Bus::Bus(const Route& route)
{
	this->route = route;//����������� ��������
	current_busStop = this->route.GetIterator()->second;//������� ��������� - ������ � ��������
	direction = FOWARD;//����������� ��������
}


Bus::~Bus(void)
{
}

//������� ������� ���������
BusStop* Bus::GetCurrentBusStop() const
{
	return current_busStop;
}

void Bus::Move()
{
	route.ChangeIterator(direction);
	cout<<"Bus number is "<<name<<" Current busStop is "<<route.GetIterator()->first<<" Direction is "<<direction<<endl;
}

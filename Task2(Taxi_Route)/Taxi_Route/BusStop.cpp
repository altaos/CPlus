#include "stdafx.h"
#include "BusStop.h"

BusStop::BusStop(string name)
{
	this->name = name;

}

BusStop::BusStop()
{
	
}

BusStop::~BusStop(void)
{
}

//���������� �������� �� ���������
void BusStop::AddMan(Man* man)
{
	men.insert(man);
}

//������� �� ������� ������ ����� �� ���������
void BusStop::PrintSetMen() const
{
	for(set<Man*>::iterator it = men.begin(); it != men.end(); it++)
		(*it)->Print();
}

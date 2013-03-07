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

//ƒобавление человека на остановку
void BusStop::AddMan(Man* man)
{
	men.insert(man);
}

//¬ыводит на консоль список людей на остановке
void BusStop::PrintSetMen() const
{
	for(set<Man*>::iterator it = men.begin(); it != men.end(); it++)
		(*it)->Print();
}

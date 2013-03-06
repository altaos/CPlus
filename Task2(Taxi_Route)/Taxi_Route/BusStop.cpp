#include "stdafx.h"
#include "BusStop.h"


BusStop::BusStop(string name)
{
	this->name = name;
}


BusStop::~BusStop(void)
{
}

bool BusStop::AddMan(Man man)
{
	men.insert(man);

	return true;
}

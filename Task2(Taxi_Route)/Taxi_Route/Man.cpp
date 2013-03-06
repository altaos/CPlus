#include "stdafx.h"
#include "Man.h"


Man::Man(string goalBusStop)
{
	this->goalBusStop = goalBusStop;
}


Man::~Man(void)
{
}

//Получить конечную остановку
string Man::GetGoalBusStop() const
{
	return goalBusStop;
}
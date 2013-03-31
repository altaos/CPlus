#include "stdafx.h"
#include "MiddleBus.h"


MiddleBus::MiddleBus(Route* route, string name) : Bus(route, name)
{
	number_of_free_seats = total_number_of_seats = 14;
}


MiddleBus::~MiddleBus(void)
{
}

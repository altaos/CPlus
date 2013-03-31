#include "stdafx.h"
#include "BigBus.h"


BigBus::BigBus(Route* route, string name) : Bus(route, name)
{
	number_of_free_seats = total_number_of_seats = 20;
}


BigBus::~BigBus(void)
{
}

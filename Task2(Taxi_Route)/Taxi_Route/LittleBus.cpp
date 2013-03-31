#include "stdafx.h"
#include "LittleBus.h"


LittleBus::LittleBus(Route* route, string name) : Bus(route, name) 
{
	number_of_free_seats = total_number_of_seats = 7;
}


LittleBus::~LittleBus(void)
{
}

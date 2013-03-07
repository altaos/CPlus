#include "stdafx.h"
#include "Bus.h"


Bus::Bus(Route& route)
{
	this->route = route;
	direction = FOWARD;
}


Bus::~Bus(void)
{
}

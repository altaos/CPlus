#pragma once
#include "bus.h"
class MiddleBus :
	public Bus
{
public:
	MiddleBus(Route* route, string name);
	virtual ~MiddleBus(void);
};


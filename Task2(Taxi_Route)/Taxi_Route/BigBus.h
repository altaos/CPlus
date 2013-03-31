#pragma once
#include "bus.h"
class BigBus :
	public Bus
{
public:
	BigBus(Route* route, string name);
	virtual ~BigBus(void);
};


#pragma once
#include "bus.h"

class LittleBus :
	public Bus
{
public:
	LittleBus(Route* route, string name);
	virtual ~LittleBus(void);
};


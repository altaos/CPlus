#include "stdafx.h"
#include "Route.h"


Route::Route(string name, map<string, BusStop>& busStops)
{
	this->name = name;
	this->busStops = busStops;
}


Route::~Route(void)
{
}

//���������� �������� ��������
string Route::GetName() const
{
	return name;
}

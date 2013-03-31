#include "stdafx.h"
#include "Route.h"


Route::Route(string name)
{
	this->name = name;
}

Route::Route(string name, int* arr, int size, vector<BusStop*>* bStop)
{
	this->name = name;
	for(int i = 0; i < size; i++)
	{
		busStops.insert(pair<string, BusStop*>((*bStop)[arr[i]]->GetName(), (*bStop)[arr[i]]));
		busStopsNames.insert((*bStop)[arr[i]]->GetName());
	}
}

Route::~Route(void)
{
}

//Добавление остановки
void Route::AddBusStop(BusStop* busStop)
{
	if(busStop != NULL)
	{
		busStops.insert(pair<string, BusStop*>(busStop->GetName(), busStop));
		busStopsNames.insert(busStop->GetName());
	}
}

const map<string, BusStop*>* Route::GetBusStops() const
{
	return &busStops;
}

//Получить список названий остановок
const set<string>* Route::GetBusStopsNames() const
{
	return &busStopsNames;
}

string Route::GetName() const
{
	return name;
}
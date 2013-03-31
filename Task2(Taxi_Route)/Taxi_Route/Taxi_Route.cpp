// Taxi_Route.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include"City.h"

using namespace std;

#define N 15

int _tmain(int argc, _TCHAR* argv[])
{
	City* city;
	int menCount = 20;
	int busCount = 5;
	int deltaMen = 2;
	int choice;

	bool isStarted = false;

	do
	{
		cout << "1. Bus count " << endl;
		cout << "2. Start count of people " << endl;
		cout << "3. Count of new people for every step " << endl;
		if(!isStarted)
			cout << "4. Start " << endl;
		else
			cout << "4. Next step " << endl;
		cout << "5. Stop " << endl << endl;
		cout << "6. Exit " << endl << endl;
		cout << "Type command number " << endl << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Bus count : ";
			cin >> busCount;
			break;
		case 2:
			cout << "Start count of people : ";
			cin >> menCount;
			break;
		case 3:
			cout << "Count of new people for every step : ";
			cin >> deltaMen;
			break;
		case 4:
			if(!isStarted)
			{
				isStarted = !isStarted;
				city = new City;
				city->CreatingBusStops();
				city->CreatingRoutes();
				city->CreatingBuses(busCount);
				city->CreatingMen(menCount);
				city->SetDeltaMen(deltaMen);
			}
			else
			{
				city->onTimer();
			}
			break;
		case 5:
			if(isStarted)
			{
				isStarted = !isStarted;
				delete city;
			}
			break;
		case 6:
			if(isStarted)
				delete city;
			break;
		}
	}
	while(choice != 6);

	return 0;
}


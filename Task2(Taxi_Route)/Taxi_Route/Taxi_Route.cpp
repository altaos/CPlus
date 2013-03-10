// Taxi_Route.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Bus.h"



int _tmain(int argc, _TCHAR* argv[])
{
	//������� ���������
	BusStop bs1("BusStop1");
	BusStop bs2("BusStop2");
	BusStop bs3("BusStop3");
	BusStop bs4("BusStop4");

	//������� map ��������� � �������
	map<string, BusStop*> busStops;
	busStops.insert(pair<string, BusStop*>("BusStop1", &bs1));
	busStops.insert(pair<string, BusStop*>("BusStop2", &bs2));
	busStops.insert(pair<string, BusStop*>("BusStop3", &bs3));
	busStops.insert(pair<string, BusStop*>("BusStop4", &bs4));
	Route new_route("27", busStops);

	//�������� ��������
	Bus bus(new_route);
	Bus bus2(new_route);
	cout<<"==============bus1=================================="<<endl;
	bus.Move();
	bus.Move();
	bus.Move();
	bus.Move();
	bus.Move();
	cout<<"==============bus2=================================="<<endl;
	bus2.Move();
	bus2.Move();
	cout<<"==============bus1=================================="<<endl;
	bus.Move();
	bus.Move();
	bus.Move();
	cout<<"==============creating men=================================="<<endl;
	Man man("BusStop3");
	busStops["BusStop2"]->AddMan(&man);
	bs2.PrintSetMen();

	cout<<"Test"<<endl;

	cin.ignore();

	return 0;
}


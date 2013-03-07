#pragma once

#include"BusStop.h"
#include<map>

enum DIRECT { FOWARD, REVERSE};

class Route
{
private:
	string name;
	map<string, BusStop*> busStops;
	map<string, BusStop*>::iterator route_iterator;
public:
	Route(string name, map<string, BusStop*>& busStops);
	Route(const Route& r);
	Route(void);
	~Route(void);
	Route& Route::operator=(const Route& r);

	string GetName() const; //���������� �������� ��������
	map<string, BusStop*>::iterator GetIterator() const; //���������� �������� �� ������� ���������
	bool ChangeIterator(DIRECT& direct);//���������  ��������� ��� ������������ ��������
};


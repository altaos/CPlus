#pragma once

#include<string>
#include<map>
#include<set>
#include<vector>
#include"BusStop.h"

using namespace std;

class BusStop;

class Route
{
private:
	string name;													//����� ��������
	map<string, BusStop*> busStops;									//��������� ��������� <�������� ���������, ���������*>
	set<string> busStopsNames;										//������ �������� ��������� ��������

public:
	Route(string name);
	Route(string name, int* arr, int size, vector<BusStop*>* bStop);
	~Route(void);

	string GetName() const;
	void AddBusStop(BusStop* busStop);								//���������� ��������� � �������
	const map<string, BusStop*>* GetBusStops() const;				//�������� ������ ��������� �������� ��� ������
	const set<string>* GetBusStopsNames() const;					//�������� ������ �������� ���������
};


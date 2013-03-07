#pragma once

#include<string>
#include<iostream>
#include"Route.h"

using namespace std;

class Man
{
private:
	string goalBusStop;				//�������� ���������
public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalBusStop() const;				//�������� �������� ���������
	void Print() const;							//������� ������ �������� �� �������
	bool CheckRoute(const Route& route) const;	//��������, ���� �� � �������� �������� ������ ���������
};


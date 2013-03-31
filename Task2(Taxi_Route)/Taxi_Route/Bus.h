#pragma once

#include"Route.h"
#include <vector>

class Man;
class Route;

enum Direct { Forward, Reverse};

class Bus
{
protected:
	string name;
	Route* route;													//�������
	map<string, BusStop*>::const_iterator current_stop;				//������� ���������
	Direct direction;												//�����������
	int total_number_of_seats;										//����� ���������� ���� � ��������
	int number_of_free_seats;										//���������� ��������� ����
	vector<Man*> men;

public:
	Bus(Route* route, string name);
	virtual ~Bus(void);

	void Move();													//������������ �������� �� ��������� ���������
	int GetTotalNumberOfSeats() const;								//�������� ����� ���������� ����
	int GetNuberOfFreeSeats() const;								//�������� ���������� ��������� ����
	string GetName() const;											//�������� �������� ��������
	string GetCurrentBusStopName() const;								//�������� �������� ������� ���������
	BusStop* GetCurrentBusStop();
	string GetDirection() const;									//�������� ����������� �������� �������
	void AddMan(Man* man);											//�������� ��������
	void CheckPassengers();											//��������� ���������� ��� ������������ �� ����� ��������� � ���� ����������
	const set<string>* GetRoute() const;							//�������� ������ �������� ��������� ��������

	friend ostream& operator<<(istream& os, const Bus& bus);
};

ostream& operator<<(ostream& os, Bus& bus);

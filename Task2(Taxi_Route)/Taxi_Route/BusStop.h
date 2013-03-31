#pragma once

#include<string>
#include<vector>
//#include"Man.h"

class Bus;
class Man;

using namespace std;

class BusStop
{
private:
	string name;						//�������� ���������
	vector<Man*> men;					//������ �����, ������ �������
	vector<Man*> menOut;				//������ ��������� �����

public:
	BusStop(string name);
	~BusStop(void);

	string GetName() const;				//�������� �������� ���������
	vector<Man*>* GetMen();				//�������� ������ �����, ������ �������
	void AddManIn(Man *man);			//�������� �������� �� ���������
	void AddManOut(Man *man);			//�������� ����������� �������� �� ���������
	void CheckAndSeatIntoBus(Bus *bus);	//��������� ����� �� ��������� �� �������
	int GetMenCount() const;

	friend ostream& operator<<(istream& os, const BusStop& bus);
};

ostream& operator<< (ostream& os, BusStop& busStop);


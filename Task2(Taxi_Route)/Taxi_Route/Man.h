#pragma once

#include<string>

using namespace std;

class Man
{
private:
	string goalBusStop; //�������� ���������
public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalBusStop() const;//�������� �������� ���������
};


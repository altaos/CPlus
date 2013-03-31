#pragma once

#include<string>
#include<set>

using namespace std;

class Man
{
private:
	string goalBusStop;											//�������� ���������

public:
	Man(string goalBusStop);
	~Man(void);

	string GetGoalStop() const;									//�������� �������� ���������
	bool CheckIsThereGoalBusStop(const set<string>* route);			//���������, ���� �� ����������� ��������� � �������� ��������
	bool IsItGoalBusStop(string busStop);						//���������, �������� �� ������ ��������� �����������
};


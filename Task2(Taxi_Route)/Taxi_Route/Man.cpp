#include "stdafx.h"
#include "Man.h"

Man::Man(string goalBusStop)
{
	this->goalBusStop = goalBusStop;
}


Man::~Man(void)
{
}

//�������� �������� ���������
string Man::GetGoalStop() const
{
	return goalBusStop;
}

//���������, ���� �� ����������� ��������� � �������� ��������
bool Man::CheckIsThereGoalBusStop(const set<string>* route)
{
	set<string>::iterator it = route->begin();
	while((*it).compare(goalBusStop) == 0 && it != route->end()) it++;
	
	return it != route->end();
}

//���������, �������� �� ������ ��������� �����������
bool Man::IsItGoalBusStop(string busStop)
{
	if(goalBusStop.compare(busStop) == 0)
		return true;

	return false;
}

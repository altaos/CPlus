#pragma once

#include"Man.h"
#include<set>

class BusStop
{
private:
	string name;//�������� ���������
	set<Man> men;//������ ����� �� ���������
public:
	BusStop(string name);
	BusStop(void);
	~BusStop(void);

	bool AddMan(Man man);//���������� �������� �� ���������
};


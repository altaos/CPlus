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
	string name;						//Название остановки
	vector<Man*> men;					//Вектор людей, ждущих автобус
	vector<Man*> menOut;				//Вектор риехавших людей

public:
	BusStop(string name);
	~BusStop(void);

	string GetName() const;				//Получить название остановки
	vector<Man*>* GetMen();				//Получить список людей, ждущих автобус
	void AddManIn(Man *man);			//Добавить человека на остановку
	void AddManOut(Man *man);			//Добавить приехавшего человека на остановку
	void CheckAndSeatIntoBus(Bus *bus);	//Проверить людей на остановке на посадку
	int GetMenCount() const;

	friend ostream& operator<<(istream& os, const BusStop& bus);
};

ostream& operator<< (ostream& os, BusStop& busStop);


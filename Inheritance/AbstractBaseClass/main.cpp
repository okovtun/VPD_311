#include<iostream>
using namespace std;

class Vehicle
{
public:
	virtual void move() = 0;
};

class GroundVehicle :public Vehicle{};

class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едит на четырех колесах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Car bmw;
	bmw.move();
}
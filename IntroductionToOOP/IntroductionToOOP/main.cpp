﻿#include<iostream>
using namespace std;

class Point	//Создаем структуру 'Point', которая будет описывать точки на плоскости.
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
				//Создание объекта 'A' структуры 'Point'
				//Создание экземпляра структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(Point) << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}

/*
-------------------------------------------------------------
.  - оператор прямого доступа, используется для обращения к полям объекта по имени объекта;
-> - оператор косвенного доступа, используется для обращения к полям объекта по адресу объекта;
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	private:	закрытые поля, доступные только внутри класса;
	public:		открытые поля, доступные в любом месте программы;
	protected:	защищенные поля, доступные внутри класса, и его дочерних классов;

	get/set-методы
	get (взять, получить) - открывают доступ к закрытым переменным на чтение, т.е.,
							позволяют получить значения закрытых переменных в классе.
	set (задать, установить) - открывают доступ к закрытым переменным на запись, т.е.,
							   позволяют задать значения закрытых переменных.
							   Кроме того, set-методы обеспечивают фильтрацию данных,
							   т.е., предотвращают попадание некорректных данных
							   в переменные члены класса, именно поэтому, set-методы
							   так же рекомендуют использовать внутри класса, не смотря на то,
							   что внутри класса есть прямой доступ к переменным.
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------------
*/
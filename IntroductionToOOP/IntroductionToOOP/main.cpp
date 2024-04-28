#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------\n"

namespace MySpace
{
	int a = 22;
}

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

	//				Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//				Methods
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		//other.y *= 10;
		//this->y *= 10;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define LIFETIME
//#define CONSTRUCTORS_CHECK

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

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B'" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A'" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A': " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef LIFETIME
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	int a = 2;
	{
		int a = 2;
	}
	cout << MySpace::a << endl;
#endif // LIFETIME

#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
#endif // CONSTRUCTORS_CHECK

	//Point A(2, 3);
	////Point B = A;	//CopyConstructor
	//Point B;
	//B = A;			//CopyAssignment

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
	/*
	Point(2, 3);здесь явно вызывается конструктор, и создается временный безымянный объект.
	*/
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

/*
-------------------------------------------------------------
1. Constructor - это метод, который создает объект;
	-С параметрами;
	-Без параметров;
	-По умолчанию (Default constructor) - это конструктор, который может быть вызван без параметров;
	-Конструктор копирования (Deep copy);
	-Конструктор переноса;
2. ~Destructor - это метод, который уничтожает объект по истечении его времени жизни;
3. CopyAssignment; Memory leak
-------------------------------------------------------------
*/
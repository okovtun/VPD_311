#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;	//размер строки в Байтах
	char* str;	//адрес строки в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	//The rule of zero - !CopyConstructor, !CopyAssignment и !Destructor;
	//The rule of three - CopyConstructor, CopyAssignment и Destructor;
	String(const String& other)
	{
		this->size = other.size;
		//Deep copy - побитовое копирование:
		//1) Выделяем новую память:
		this->str = new char[size] {};
		//2) Копируем содержимое этой памяти из другого объекта:
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;	//shallow copy
		//MoveConstructor должен работать так, как НЕ должен работать CopyConstrcutor
		//После копирования удаляемый объект обязательно нужно обнулить:
		other.str = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		int a = 2;
		int b = 3;
		a = b;
		if (this == &other)return *this;
		delete[] this->str;
		//Deep copy:
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	//Hello + World = HelloWorld;
	//String cat = left.get_size() + right.get_size() - 1;	//explicit Constructor невозможно вызвать вот так,
	String cat(left.get_size() + right.get_size() - 1);		//но его всегда можно выбвать вот так
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str;				//Default constructor
	str.print();

	String str1 = "Hello";	//Single-argument constructor
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;		//Copy constructor
	cout << str2 << endl;

	String str3;			//Default constructor
	str3 = str2;			//Copy assignment
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;

	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
}

/*
-------------------------------
C++11:	The rule of three => The rule of five:
MoveConstructor;
MoveAssignment;
Shallow copy - поверхностное копирование
r-value reference на объект нашего класса
-------------------------------
*/
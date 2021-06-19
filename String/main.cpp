#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------\n"

using std::cin;
using std::cout;
using std::endl;

class String
{
	int size;	//Размер строки в байтах
	char* str;	//Указатель на сторку
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

	//Constructors:
	//Конструктор по умолчанию который будет создавать строку размером 80 byte, параметром по умолчанию.
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}

	String(const char str[])			//Конструктор принимающий массив char.
	{
		this->size = strlen(str) + 1;	//В size записываем размер строки через функцию strlen().
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}

	//Конструктор копирования принимает постоянную ссылку и выделяет новую память для нового объекта,
	//и копирует содержимое старого объекта в новый.
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//Operators
	//Оператор присвоить принимает константную ссылку на объект.
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;		//Копируем размер
		this->str = new char[size] {};	//Выделяем память
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

//ostream возвращает ссылку на поток
//(принимает ostream по ссылке и константную ссылку на объект нашего класса obj)
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//get_str() получает адрес начала строки.
//Этот оператор изменяет объект, поэтому передаем не как константу.
istream& operator>>(istream& is, String& obj)
{
	return is >> obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);	//Default constructor создается объект в который поместим результат
	for (int i = 0; i < left.get_size(); i++)
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
	return cat;	//CopyConstructor вызывается когда происходит возврат значения cat на место вызова
}

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	cout << "Str1: " << str1 << endl;
	cout << delimiter << endl;

	cout << "User write: World" << endl;
	String str2;
	cin >> str2;
	cout << "Str2: " << str2 << endl;
	cout << delimiter << endl;

	String str3 = str1 + str2;
	cout << delimiter << endl;
	cout << "Str3 = Str1 + Str2: " << tab << str3 << endl;
	cout << delimiter << endl;
}
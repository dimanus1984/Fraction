#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------\n"

using std::cin;
using std::cout;
using std::endl;

class Point //Описывает точку на плоскости
{
	double x; //Координата по X
	double y; //Координата по Y
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
	//			Constructors:
	/*Point()
	{
		//Конструктор по умолчанию создает точку в начале координат
		x = y = int();	//Якобы вызываем констуктор по умолчанию для 'int', и он возвращает значение по умолчанию
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		//Конструктор с одним параметром создает точку на прямой.
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		//Конструктор с параметрами создает точку на плоскости
		//Этот конструктор с параметрами может быть вызван
		//-без параметров;
		//-с одним параметром;
		//-с двумя параметром;
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//other - это другой объект, копию которого мы создаем
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)     // Перегрузка оператора '=' для Point
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=\t\t" << this << endl;
		return *this;
	}

	//				Increment/Decriment
	Point& operator++() //Prefix increment
	{
		this->x++;
		this->y++;
		cout << "Prefix increment++:\t" << this << endl;
		return *this;
	}

	Point operator++(int) //Postfix increment
	{
		Point old = *this; //CopyConstructor
		this->x++;
		this->y++;
		cout << "Postfix increment:\t" << this << endl;
		return old;
	}

	//Point operator+(const Point& other)const //Перегрузка оператора '+' для Point
	//{
	//	Point result;
	//	result.x = this->x + other.x;
	//	result.y = this->y + other.y;
	//	cout << "operator+" << endl;
	//	return result;
	//}

	//Point operator-(const Point& other)const //Перегрузка оператора '-' для Point
	//{
	//	Point result(this->x - other.x, this->y - other.y);
	//	cout << "operator-" << endl;
	//	return result;
	//}

	//Point operator*(const Point& other)const //Перегрузка оператора '*' для Point
	//{
	//	cout << "operator*" << endl;
	//	return Point (this->x * other.x, this->y * other.y);
	//}

	//Point operator/(const Point& other)const //Перегрузка оператора '/' для Point
	//{
	//	cout << "operator/" << endl;
	//	return Point(this->x / other.x, this->y / other.y);
	//}

	//				Methods:
	double distance(const Point& other) const
	{
		this;  //точка, в которой мы сейчас находимся        (this  - этот)
		other; //точка, до которой нужно вычислить расстояние (other - другой)
		double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); //sqrt- Square Root (квадратнфй корень)
		return distance;

	}

	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//Создавая структуру или класс, мы создаем новый тип данных,
//а объявляя объекты этого класса или структуры мы создаем переменные нашего типа.
//			КЛАСС - ЭТО ТИП ДАННЫХ
//		СТРУКТУРА - ЭТО ТИП ДАННЫХ
//		   ОБЪЕКТ - ЭТО САМАЯ ОБЫЧНАЯ ПЕРЕМЕННАЯ.

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Plus" << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	cout << "Minus" << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	cout << "Multiply" << endl;
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

Point operator/(const Point& left, const Point& right)
{
	cout << "Divide" << endl;
	return Point(left.get_x() / right.get_x(), left.get_y() / right.get_y());
}


//#define DISTANCE_AND_CONSTRUCTORS
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Rus");

#ifdef DISTANCE_AND_CONSTRUCTORS
	Point A(2.3, 4.5); //Constructor
//A.set_x(2);
//A.set_y(3);
	cout << sizeof(A) << endl;
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;			//DefaultConstructor
	B.print();

	Point C = A;		//CopyConstructor

	Point D(6.7, 8.3);
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки D: " << A.distance(D) << endl; //A - this, D - other
	cout << "Расстояние от точки D до точки A: " << D.distance(A) << endl; //D - this, A - other
	cout << "Расстояние между точками A и D:   " << distance(A, D) << endl;
	cout << "Расстояние между точками D и A:   " << distance(D, A) << endl;
	cout << delimiter << endl;

	B = D;       //CopyAssignment

	/////////////////////////////////////////////////////////////////
	cout << delimiter << endl;
	Point E = A; //CopyConstructor
	Point F;	 //DefaultConstructor
	F = D;       //CopyAssigment
	cout << delimiter << endl;
	/////////////////////////////////////////////////////////////////
#endif // DISTANCE_AND_CONSTRUCTORS

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2.3, 4.5);		//Point(2.3, 4.5) - явный вызов конструктора.
										//Создается временный безымянный объект,
										//который существует только в пределах этого выражения.
	cout << delimiter << endl;
	//l-value = r-value;
	//  Point
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK


	Point A(2.3, 4.5);
	Point B(2.7, 3.14);
	cout << delimiter << endl;
	Point C = A + B;
	cout << delimiter << endl;
	C.print();
	Point D = A - B;
	D.print();
	cout << delimiter << endl;
	(A * B).print();
	cout << delimiter << endl;
	//Point E = A.operator/(B);
	Point E = operator/(A, B);
	E.print();
	cout << delimiter << endl;
	++C;
	C.print();
	cout << delimiter << endl;
	C++;
	C.print();

}
#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------\n"

using std::cin;
using std::cout;
using std::endl;

class Fraction;										//Class declaration - Объявление класса
Fraction operator+(Fraction left, Fraction right);	//Прототип оператора +
Fraction operator-(Fraction left, Fraction right);	//Прототип оператора -
Fraction operator*(Fraction left, Fraction right);	//Прототип оператора *
Fraction operator/(Fraction left, Fraction right);	//Прототип оператора /

bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);

bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	//get/set - методы
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		else this->denominator = denominator;
	}

	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		//cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		//cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		//cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		//cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Increment/Decriment:
	Fraction& operator++()		//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)	//Postfix increment
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator--()		//Prefix decriment
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//				Methods:
	Fraction& to_improper()	//Переводим в неправильную дробь
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()	//Переводим в правильную дробь
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		Fraction inverted(denominator, numerator);
		return inverted;
	}
	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		int more, less, rest;
		//Выясняем кто больше, числитель, или знаменатель:
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		//Находим наибольший общий делитель:
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		//В more сохраняется GCD - наибольший общий делитель
		int GCD = more;
		//Сокращаем дробь
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void print()
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());	//Числитель
	result.set_denominator(left.get_denominator() * right.get_denominator());	//Знаменатель
	result.to_proper();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_improper();
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator> (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator< (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}

bool operator>= (const Fraction& left, const Fraction& right)
{
	if (left == right || left > right) return true;
	else return false;
}
bool operator<= (const Fraction& left, const Fraction& right)
{
	if (left == right || left < right) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())cout << "(";
	if (obj.get_numerator())cout << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())cout << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)cout << 0;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");

	Fraction A = 5;
	cout << "Fraction A = " << A << endl;
	Fraction B(1, 2);
	cout << "Fraction B = " << B << endl;
	Fraction C(2, 3, 4);
	cout << "Fraction C = ";
	C.print();

	cout << delimiter << endl;

	Fraction D(2, 18, 36);
	cout << "Fraction D:\t\t" << D << endl;
	cout << "Proper fraction:\t" << (D.to_proper()) << endl;
	cout << "Improper fraction:\t" << (D.to_improper()) << endl;
	cout << "Reduce fraction:\t" << (D.reduce()) << endl;

	cout << delimiter << endl;

	cout << "ARITHMETICAL_OPERATORS_CHECK" << endl << endl;
	Fraction E(2, 3, 4);
	Fraction F(5, 6, 7);
	cout << E << " + " << F << " = " << E + F << endl;
	cout << E << " - " << F << " = " << E - F << endl;
	cout << E << " * " << F << " = " << E * F << endl;
	cout << E << " / " << F << " = " << E / F << endl;

	cout << delimiter << endl;

	cout << "COMPARISON_OPERATORS" << endl << endl;
	cout << "E = " << E << "\tF = " << F << std::endl << endl;
	cout << "E == F\t" << ((E == F) ? "true" : "false") << endl;
	cout << "E != F\t" << ((E != F) ? "true" : "false") << endl;
	cout << "E >  F\t" << ((E > F) ? "true" : "false") << endl;
	cout << "E <  F\t" << ((E < F) ? "true" : "false") << endl;
	cout << "E >= F\t" << ((E >= F) ? "true" : "false") << endl;
	cout << "E <= F\t" << ((E <= F) ? "true" : "false") << endl;

	cout << delimiter << endl;
}
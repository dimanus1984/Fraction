#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//Methods:
	void print()
	{
		cout << last_name << " " << first_name << " " << age << " лет." << endl;
	}
};

class Student :public Human
{
	string specialty;
	string group;
	double rating;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//Methods:
	void print()
	{
		Human::print();
		cout << "Специальность: " << specialty << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};

class Teacher :public Human
{
	string specialty;
	unsigned int experience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->experience = experience;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//Methods:
	void print()
	{
		Human::print();
		cout << "Специальность: " << specialty << ", опыт преподавания: " << experience << " лет" << endl;
	}
};

class Graduate :public Student
{
	string diploma_project;	//Тема дипломного проекта.
public:
	const string& get_diploma_project()const
	{
		return this->diploma_project;
	}
	void set_diploma_project(const string& diploma_project)
	{
		this->diploma_project = diploma_project;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,	//Атрибуты базового класса
		const string& speciality, const string& group, double rating,
		const string& diploma_project
	) :Student(last_name, first_name, age, speciality, group, rating),
		diploma_project(diploma_project)
	{
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDistructor:\t" << this << endl;
	}
	void print()
	{
		Student::print();
		cout << "Тема дипломного проеекта: " << diploma_project << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Teacher Albert("Einstein", "Albert", 150, "Astophisics", 120);
	Albert.print();

	Graduate Dima("Nuss", "Dmitriy", 37, "C++ software development", "DIM_05", 100, "Class Graduate");
	Dima.print();
}
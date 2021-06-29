#include"Human.h"

const string& Human::get_last_name()const
{
	return last_name;
}
const string& Human::get_first_name()const
{
	return first_name;
}
unsigned int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	if (age >= 18 && age <= 100)
		this->age = age;
	else
		this->age = 0;
}

//Constructors:
Human::Human(const string& last_name, const string& first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
//Methods:
void Human::print()
{
	cout << last_name << " " << first_name << " " << age << " лет." << endl;
}

ostream& operator<<(ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << ", " << obj.get_age() << " лет" << endl;
}
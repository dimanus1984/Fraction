#include"Student.h"

const string& Student::get_specialty()const
{
	return specialty;
}
const string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
void Student::set_specialty(const string& specialty)
{
	this->specialty = specialty;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	if (rating > 0 && rating <= 100)
		this->rating = rating;
	else
		this->rating = 100;
	if (this->rating >= 20)
		cout << "Good rating!" << endl;
}
//Constructors:
Student::Student
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
Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}
//Methods:
void Student::print()
{
	//Human::print();
	//cout << "Специальность: " << specialty << ", группа: " << group;
	//cout << ", успеваемость: " << rating << (rating >= 50 ? " Good rating" : "") << endl;
}

ostream& operator<<(ostream& os, const Student& obj)
{
	return os << (Human&)obj << "Специальность: " << obj.get_specialty()
		<< ", группа: " << obj.get_group() << ", успеваемость: " << obj.get_rating()
		<< (obj.get_rating() >= 100 ? " Best rating" : "");
}
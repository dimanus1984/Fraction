#include"Teacher.h"

const string& Teacher::get_specialty()const
{
	return specialty;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_specialty(const string& specialty)
{
	this->specialty = specialty;
}
void Teacher::set_experience(unsigned int experience)
{
	if (experience > 0 && experience <= 100)
		this->experience = experience;
	else
		this->experience = 100;
	if (this->experience >= 20)
		cout << "Teacher experience Good!" << endl;
}
//Constructors:
Teacher::Teacher
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& specialty, unsigned int experience
) :Human(last_name, first_name, age)
{
	this->specialty = specialty;
	this->experience = experience;
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}
//Methods:
void Teacher::print()
{
	//Human::print();
	//cout << "�������������: " << specialty;
	//cout << ", ���� ������������: " << experience << " ���" << (experience >= 20 ? " Best experience" : "") << endl;
}

ostream& operator<<(ostream& os, const Teacher& obj)
{
	return os << (Human&)obj << "�������������: " << obj.get_specialty()
		<< ", ���� ������������: " << obj.get_experience() << " ���"
		<< (obj.get_experience() >= 20 ? " Best experience" : "") << endl;
}
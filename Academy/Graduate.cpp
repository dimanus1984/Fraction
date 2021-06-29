#include"Graduate.h"

const string& Graduate::get_diploma_project()const
{
	return this->diploma_project;
}
void Graduate::set_diploma_project(const string& diploma_project)
{
	this->diploma_project = diploma_project;
}
Graduate::Graduate
(
	const string& last_name, const string& first_name, unsigned int age,
	const string& speciality, const string& group, double rating,
	const string& diploma_project
) :Student(last_name, first_name, age, speciality, group, rating),
diploma_project(diploma_project)
{
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDistructor:\t" << this << endl;
}
void Graduate::print()
{
	Student::print();
	cout << "Тема дипломного проекта: " << diploma_project << endl;
}
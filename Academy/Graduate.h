#pragma once
#include"Student.h"

class Graduate :public Student
{
	string diploma_project;
public:
	const string& get_diploma_project()const;
	void set_diploma_project(const string& diploma_project);

	Graduate(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_project);

	~Graduate();
	void print();
};

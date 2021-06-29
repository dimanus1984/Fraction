#pragma once
#include"Human.h"

class Teacher :public Human
{
	string specialty;
	unsigned int experience;
public:
	const string& get_specialty()const;
	unsigned int get_experience()const;
	void set_specialty(const string& specialty);
	void set_experience(unsigned int experience);

	//Constructors:
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience);
	~Teacher();

	//Methods:
	void print();
};

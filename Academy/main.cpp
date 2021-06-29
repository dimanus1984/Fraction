#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------------\n"

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
		if (age >= 18 && age <= 100)
			this->age = age;
		else
			this->age = 0;
	}
	//Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//Methods:
	virtual void print()
	{
		cout << last_name << " " << first_name << " " << age << " лет." << endl;
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	os << obj.get_last_name() << " " << obj.get_first_name() << ", " << obj.get_age() << " лет";
	return os;
}

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
		if (rating >= 0 && rating <= 100)
			this->rating = rating;
		else
			this->rating = 100;
		if (this->rating >= 20)
			cout << "Good rating!" << endl;
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
		cout << "Специальность: " << specialty << ", группа: " << group;
		cout << ", успеваемость: " << rating << (rating >= 50 ? " Good rating" : "") << endl;
	}
};

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human&)obj << " ";
	os << "Специальность: " << obj.get_specialty() << ", группа: " << obj.get_group() << ", успеваемость: " << obj.get_rating();
	return os;
}

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
		if (experience > 0 && experience <= 100)
			this->experience = experience;
		else
			this->experience = 100;
		if (this->experience >= 20)
			cout << "Teacher experience Good!" << endl;
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
		cout << "Специальность: " << specialty;
		cout << ", Опыт преподавания: " << experience << " лет" << (experience >= 20 ? " Best experience" : "") << endl;
	}
};

ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human&)obj << " ";
	os << "Специвльность: " << obj.get_specialty()
		<< ", опыт преподавания: " << obj.get_experience() << " лет";
	return os;
}

class Graduate :public Student
{
	string diploma_project;
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
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const string& group, double rating,
		const string& diploma_project
	) :Student(last_name, first_name, age, speciality, group, rating)
	{
		set_diploma_project(diploma_project);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDistructor:\t" << this << endl;
	}
	void print()
	{
		Student::print();
		cout << "Тема дипломного проекта: " << diploma_project << endl;
	}
};

ostream& operator<<(ostream& os, const Graduate& obj)
{
	os << (Student&)obj;
	return os << ". Тема диплома: " << obj.get_diploma_project();
}

//#define INHERITANCE_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_BASICS
	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();

	Teacher Albert("Einstein", "Albert", 90, "Astophisics", 50);
	Albert.print();

	Graduate Dima("Nuss", "Dmitriy", 37, "C++ software development", "DIM_05", 95, "Class Graduate");
	Dima.print();
#endif // INHERITANCE_BASICS

	//					POINTERS TO BASE CLASS
	Human* group[] =
	{
		new Student("Васильев", "Александр",23,"РПО","ПВ_011",90),
		new Student("Васильева","Маргарита",25,"РПО","ПВ_011",90),
		new Teacher("Ковтун","Олег",36,"Разработка приложений на C++",6),
		new Student("Ивлев","Александр",25,"РПО","ПВ_011",95),
		new Graduate("Рахманин","Николай",28,"РПО","ПВ_011",98, "Разработка обучающей игры"),
		new Teacher("Романов","Андрей",30,"HardwarePC",5),
		new Student("Нусс","Дмитрий",22,"РПО","ПВ_011",100),
		new Student("Борн","Евгений",35,"РПО","ПВ_011",99),
	};

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		cout << delimiter << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}
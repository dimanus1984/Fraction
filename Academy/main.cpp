#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

ostream& operator<<(ostream& os, const Human& obj)
{
	os << obj.get_last_name() << " " << obj.get_first_name() << ", " << obj.get_age() << " лет";
	return os;
}

ostream& operator<<(ostream& os, const Student& obj)
{
	os << (Human&)obj << " ";
	os << "Специальность: " << obj.get_specialty() << ", группа: " << obj.get_group() << ", успеваемость: " << obj.get_rating();
	return os;
}

ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human&)obj << " ";
	os << "Специвльность: " << obj.get_specialty()
		<< ", опыт преподавания: " << obj.get_experience() << " лет";
	return os;
}

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

	cout << delimiter << endl;
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
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define delimitr "\n--------------------------------------------------\n"

namespace Geometry
{
	class Geometric_figures
	{
		string color;
	public:
		Geometric_figures(const string color)
		{
			this->color = color;
		}
		virtual double area()const = 0;			//Площадь.
		virtual double perimeter()const = 0;	//Периметер.
		virtual void figure_output()const = 0;	//Вывод фигуры.
	};

	class Square :public Geometric_figures		//Квадрат.
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side > 0)this->side = side;
			else this->side = 1;
		}
		explicit Square(double side, const string& color = "white") :Geometric_figures(color)
		{
			set_side(side);
		}
		~Square()
		{
		}
		double area()const
		{
			return side * side;
		}
		double perimeter()const
		{
			return side * 4;
		}
		void figure_output()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
	};

	class Rectangle :public Geometric_figures				//Прямоугольник.
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width > 0)this->width = width;
			else this->width = 1;
		}
		void set_length(double length)
		{
			if (length > 0)this->length = length;
			else this->length = 1;
		}
		explicit Rectangle(double width, double length, const string& color = "white") :Geometric_figures(color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle()
		{
		}
		double area()const
		{
			return width * length;
		}
		double perimeter()const
		{
			return (width * length) * 2;
		}
		void figure_output()const
		{
			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < length; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
	};

	/*class Triagle :public Geometric_figures
	{
		double side1, side2, side3;
	public:
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
		}
		double get_side3()const
		{
			return side3;
		}
		double set_side1(double side1)
		{
			if (side1 < 0)side1 = -side1;
			return this->side1 = side1;
		}
		double set_side2(double side2)
		{
			if (side2 < 0)side2 = -side2;
			return this->side2 = side2;
		}
		double set_side3(double side3)
		{
			if (side3 < 0)side3 = -side3;
			return this->side3 = side3;
		}

		Triagle(double side1, double side2, double side3)
		{
			set_side1(side1);
			set_side2(side2);
			set_side3(side3);
			if (side3 >= (side1 + side2) || side1 >= (side2 + side3) || side2 >= (side1 + side3))
				throw std::exception("Triangle Bad side");
			std::cout << "TrConstructor:\t" << this << std::endl;
		}
		~Triagle()
		{
			std::cout << "TrDestructor:\t" << this << std::endl;
		}
		double area()const
		{
			return 0;
		}
		double perimeter()const
		{
			return 0;
		}
		void draw()const
		{}
	};*/
}
void main()
{
	setlocale(LC_ALL, "Russian");

	Geometry::Square square(5);
	cout << "Square" << endl;
	cout << "Площадь: " << square.area() << endl;
	cout << "Периметр: " << square.perimeter() << endl;
	square.figure_output();

	cout << delimitr << endl;

	Geometry::Rectangle rectangle(5, 10);
	cout << "Rectangle" << endl;
	cout << "Площадь: " << rectangle.area() << endl;
	cout << "Периметр: " << rectangle.perimeter() << endl;
	rectangle.figure_output();

	/*try
	{
		Geometry::Triagle triagle(1, 2, 3);
	}
	catch (const std::exception& triagle)
	{
		std::cerr << e.what() << std::endl;
	}*/
}
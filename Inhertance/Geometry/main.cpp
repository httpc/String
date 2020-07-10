#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

namespace Geometry
{
	class Shape
	{
		string color;
	public:
		Shape(string color = "white")
		{
			this->color = color;
		}
		virtual ~Shape() {};

		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side() const
		{
			return side;
		}
		double set_side(double side)
		{
			if (side < 0)side = -side;
			return this->side = side;
		}

		Square(double side) :side(set_side(side))
		{
			cout << "SqConstructor:\t" << this << endl;
		}
		~Square()
		{
			cout << "SqDestuctor:\t" << this << endl;
		}

		double area()const
		{
			return side * side;
		}
		double perimeter()const
		{
			return side * 4;
		}
		void draw() const
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

	class Rectangle :public Shape
	{
		double side1;
		double side2;
	public:
		double get_side1()const
		{
			return side1;
		}
		double get_side2()const
		{
			return side2;
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

		Rectangle(double side1, double side2)
		{
			set_side1(side1);
			set_side2(side2);
			cout << "RectConstructor:\t" << this << endl;
		}
		~Rectangle()
		{
			cout << "RectDestructor:\t" << this << endl;
		}

		double area()const
		{
			return side1 * side2;
		}
		double perimeter()const
		{
			return (side1 + side2) * 2;
		}
		double diag()const
		{
			return sqrt(pow(side1, 2) + pow(side2, 2));
		}
		void draw() const
		{
			for (int i = 0; i < side1; i++)
			{
				for (int j = 0; j < side2; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square sq(5);
	cout << "Square area:\t" << sq.area() << endl;
	cout << "Square perimeter:\t" << sq.perimeter() << endl;
	sq.draw();

	Geometry::Rectangle rect(5, 8);
	cout << "Rectangle area:\t" << rect.area() << endl;
	cout << "Rectangle perimeter:\t" << rect.perimeter() << endl;
	rect.draw();
}
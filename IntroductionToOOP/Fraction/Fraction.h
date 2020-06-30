#pragma once
#include<iostream>
#include<string>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(const Fraction& left, const Fraction& right);
ostream& operator<<(ostream& os, const Fraction& obj);
class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	explicit Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		decimal *= 100000000;
		numerator = decimal;
		denominator = 100000000;
		reduce();
	}
	explicit Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	explicit Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Fraction& operator*=(Fraction other)
	{
		this->reduce().to_improper();
		other.reduce().to_improper();
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return this->reduce().to_proper();
	}

	//Fraction operator*(const Fraction& other) const
	//{
	//	Fraction result;
	//	Fraction left = this->to_improper();
	//	Fraction right = other.to_improper();
	//	/*left.to_improper();
	//	right.to_improper();*/
	//	result.numerator = left.numerator*right.numerator;
	//	result.denominator = left.denominator*right.denominator;
	//	result.reduce();
	//	result.to_proper();
	//	return result;
	//}

	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)	//Suffix increment
	{
		Fraction buffer = *this;
		integer++;
		return buffer;
	}

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Operator()\t" << this << endl;
		return *this;
	}

	//		Type-cast operators:
	explicit operator int() const
	{
		return integer;
	}

	explicit operator double() const
	{
		return integer + (double)numerator / denominator;
	}

	operator string()const
	{
		return "Hello World";
	}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "+";
			//if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			//if (integer)cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		//numerator = numerator % denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce()
	{
		/*if (numerator == 0)
		{
			denominator = 1;
			return *this;
		}*/
		//В дроби, в любом случае что-то больше. Числитель может быть больше знаменателя, или наоборот.
		int more;	//большее значение
		int less;	//меньшее значение
		int reminder = 0;	//остаток от деления
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more;	//Greatest Common Divider - Наибольший Общий Делитель.
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};
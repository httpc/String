#include "Fraction.h"



//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define METHODS_CHECK
//#define ARITHMETIC_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define PRIMIRIVE_TYPE_CONVERSIONS

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;		//DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	/*Fraction A(1, 2);
A.print();
Fraction B;
B.print();
cout << "\n-------------------------------------------\n";
B = A;
cout << "\n-------------------------------------------\n";*/

	int a, b, c;
	a = b = c = 0;
	Fraction D(1, 2);

	Fraction A, B, C;
	A = B = C = D;
#endif // ASSIGNMENT_CHECK

#ifdef METHODS_CHECK
	/*Fraction A(7, 5);
A.print();
A.to_proper();
A.print();
A.to_improper();
A.print();*/

	Fraction A(148, 44);
	A.reduce();
	A.print();
	Fraction B(251, 934);
	B.reduce();
	B.print();
	Fraction C = A * B;
#endif // METHODS_CHECK

#ifdef ARITHMETIC_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	cout << a << endl;
	cout << b << endl;
	cout << "\n-------------------------\n";
	int c = a * b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << "\n-------------------------\n";

	Fraction A(2, 3, 4);
	Fraction B(5, 7, 8);
	//cout << A << " + " << B << " = " << A + B << endl;
	/*A.print();
	B.print();
	Fraction C = A + B;
	A.print();
	B.print();
	C.print();
	(A *= B).print();*/
#endif // ARITHMETIC_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = 2.5; i < 10; i++)cout << i << "\t"; cout << endl;
	Fraction A(1, 2);
	Fraction B = A++;
	B.print();
	A.print();
	cout << A + B << endl;
#endif // INCREMENT_CHECK

#ifdef PRIMIRIVE_TYPE_CONVERSIONS
	double weight = 3.25;
	//Explicit conversions (явное преобразование типов)
	cout << (int)weight << endl;	//C-like cast notation
	cout << int(weight) << endl;	//Functional notation

	int a = 2;
	cout << a + weight << endl;		//implicit conversion 'a' to double
									//неявное преобразование 'a' в double

	double pi = 3.14;
	int b = pi;	//Conversion from more to less with loss of data.
				//Преобразование от бОльшего к меньшему с потерей данных
	cout << b << endl;

	double c = 5;
	int d = c;	//Преобразование от бОльшего к меньшему БЕЗ потери данных.
	double e = d;//Преобразование от меньшего к большему.

	unsigned short f = 100000;
	cout << f << endl;
#endif // PRIMIRIVE_TYPE_CONVERSIONS

	double a = 5;	//
	cout << a << endl;
	Fraction A;// = 5;	//Single argument constructor.
	cout << A << endl;
	A = (Fraction)8;
	cout << A << endl;

	Fraction B(2, 1, 2);
	double b = (double)B;
	cout << b << endl;
	int c = (int)B;
	cout << c << endl;

	/*double b = A;
	double pi = 3.14;
	Fraction PI = pi;*/

	Fraction C(3.14);	//explicit constructor можно вызвать только так, 
						//его нельзя вызвать оператором '='.
	cout << C << endl;

	/*C.set_integer(2);
	C.set_numerator(7);
	C.set_denominator(8);*/
	C(2, 7, 8);
	cout << C << endl;

	string fr = C;
	cout << fr << endl;
	//Type-cast operators
}

//Operator overloading:
/*
1. Перегрузить можно только существующие операторы.
	+ перегружается;
	* перегружается;
	++ перегружается;
	** НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
	Не перегружаются:
	?: - тернарный оператор
	.  - опертор прямого доступа
	.* -
	:: - оператор разрешения видимости
	#
	##
3. Перегруженные оперторы сохраняют приоритет.
4. Изменить поведение операторов со встроенными типами данных НЕВОЗМОЖНО!
--------------------------------------------------------------------------------------------

=, +=, -=, *=, /=, %=;

--------------------------------------------------------------------------------------------
*/
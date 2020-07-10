#include<iostream>
#include<string>
using namespace std;

#define DEBUG

class Human
{
	string name;
	string surname;
	unsigned int age;
public:
	const string& get_name()const
	{
		return name;
	}
	const string& get_surname()const
	{
		return surname;
	}
	unsigned int get_age()const
	{
		return age;
	}
	string& set_name(const string& name)
	{
		return this->name = name;
	}
	string& set_surname(const string& surname)
	{
		return this->surname = surname;
	}
	unsigned int set_age(unsigned int age)
	{
		return this->age = age;
	}
	//		Constructors:
	Human(const string& name, const string& surname, unsigned int age)
	{
		set_name(name);
		set_surname(surname);
		set_age(age);
		cout << "HConstuctor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//		Methods:
	virtual void print()const
	{
		cout << name << " " << surname << " " << age << " лет.\n";
	}
};

class Student :public Human
{
	string group;
	unsigned int rating;
	unsigned int attendance;
public:
	const string& set_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	unsigned int get_attendance()const
	{
		return attendance;
	}
	string& set_group(const string& group)
	{
		return this->group = group;
	}
	unsigned int set_rating(unsigned int rating)
	{
		return this->rating = rating;
	}
	unsigned int set_attendance(unsigned int attendance)
	{
		return this->attendance = attendance;
	}
	//		Constuctors:
	Student(
		const string& name, const string& surname, unsigned int age,
		const string& group, unsigned int rating, unsigned int attendance
		):Human(name,surname, age)
	{
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstuctor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//		Methods:
	void print()const
	{
		Human::print();
		cout << group << " успеваемость: " << rating << " посещаемость: " << attendance << endl;
	}
};

class Teacher :public Human
{
	string spec;
	unsigned int exp;
public:
	const string& get_spec()const
	{
		return spec;
	}
	unsigned int get_exp()const
	{
		return exp;
	}
	string& set_spec(const string& spec)
	{
		return this->spec = spec;
	}
	unsigned int set_exp(unsigned int exp)
	{
		return this->exp = exp;
	}
	//		Constuctors:
	Teacher
	(
		const string& name, const string& surname, unsigned int age,
		const string& spec, unsigned int exp
		) :Human(name, surname, age)
	{
		set_spec(spec);
		set_exp(exp);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestuctor:\t" << this << endl;
	}
	//		Methods:
	void print()const
	{
		Human::print();
		cout << spec << " Опыт преподавания:" << exp <<" лет."<< endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	string& set_diploma_theme(const string& diploma_theme)
	{
		return this->diploma_theme = diploma_theme;
	}
	//		Constuctors:
	Graduate(
		const string& name, const string& surname, unsigned int age,
		const string& group, unsigned int rating, unsigned int attendance,
		const string& diploma_theme
	) :Student(name, surname, age, group, rating, attendance)
	{
		set_diploma_theme(diploma_theme);
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate(const Student& stud, const string& diploma_theme) :Student(stud)
	{
		set_diploma_theme(diploma_theme);
#ifdef DEBUG
		cout << "GCConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Graduate()
	{
#ifdef DEBUG
		cout << "GDestructor:\t" << this << endl;
#endif // DEBUG

	}
	//		Methods:
	void print()const
	{
		Student::print();
		cout << "Тема дипломного проекта: "<<diploma_theme << endl;
	}
};

#define POLYMORPHISM
//#define FUNCTION_POINTERS

int __stdcall add(int a, int b)
{
	return a + b;
}

void main()
{
	setlocale(LC_ALL, "");

	/*Human h("Василий", "Петренко", 18);
	h.print();

	Student stud("Василий", "Петренко", 18, "PV_911", 20, 30);
	stud.print();

	Teacher Albert("Albert", "Einshein", 141, "Theory of relativity", 120);
	Albert.print();

	Graduate petia(stud,"qwerty");
	petia.print();	*/

#ifdef POLYMORPHISM
	//UpCast
	Human* group[] =
	{
		new Student("Даня","Дудченко",17,"PV_911",100,100),
		new Student("Дмитрий","Никулин",16,"PV_911",100,99),
		new Teacher("Адрей","Кобылинский",40,"HardwarePC",20),
		new Student("Макс","Пышненко",16,"PV_911",98,95),
		new Teacher("Роман","Шерстюк",30,"Web development",5),
		new Graduate("Даня","Котыгорошко",19,"PV_911",100,100,"Расширение конструкции сопоставления с образцом в языке OCaml")
	};
	//DownCast (Specialization)
	for (int i = 0; i < size(group); i++)
	{
		(*group[i]).print();
		cout << endl;
	}
	for (int i = 0; i < size(group); i++)
	{
		delete[] group[i];
	}
#endif // POLYMORPHISM

#ifdef FUNCTION_POINTERS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	cout << *pa << endl;
	cout << add(2, 3) << endl;
	int(*function)(int, int) = add;
	cout << function(2, 3) << endl;
#endif // FUNCTION_POINTERS

}
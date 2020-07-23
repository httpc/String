#include <iostream>
using namespace std;

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConctructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestctructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		this->Head = nullptr;
		cout << "LConctructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestctructor:\t" << this << endl;
	}

	//			Methods:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	}
	void pop_front()
	{
		if (Head == nullptr)
		{
			cout << "Error" << endl;
			return;
		}
		else if (count() == 1)
		{
			Head = nullptr;
			return;
		}
		Element* Temp = Head;
		Head = Temp->pNext;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data); 
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
	}
	void pop_back()
	{
		if (Head == nullptr)
		{	
			cout << "Error" << endl;
			return;
		}
		else if (count() == 1)
		{
			Head = nullptr;
			return;
		}
		Element* Temp = Head;
		int toy = count();
		for (int i = 0; i < toy-2; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = nullptr;
	}

	void insert(int Data, int index)
	{
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		New->pNext = Temp;
		Temp = Head;
		for (int i = 0; i < index-2; i++)
		{
			Temp = Temp->pNext;
		}
		
		Temp->pNext = New;
	}
	void erase(int index)
	{
		Element* Low = Head;
		Element* High = Head;
		for (int i = 0; i < index-2; i++)
		{
			Low = Low->pNext;
		}
		for (int i = 0; i < index; i++)
		{
			High = High->pNext;
		}
		Low->pNext = High;
	}
	int count(int n=0)
	{
		Element* Temp = Head;
		int i = 0;
		if (n == 0)
		{
			while (Temp != nullptr)
			{
				Temp = Temp->pNext;
				i++;
			}
		}
		/*else
		{
			while (Temp != nullptr)
			{
				if (i == n)break;
				Temp = Temp->pNext;
				i++;
			}
		}*/
		return i;
	}

	void print()
	{
		Element* Temp = Head;
		cout << Head << endl;
		while (Temp!=nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl; Temp = Temp->pNext;
		}
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Input list size: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.push_back(123);
	list.print();
	list.erase(3);
	list.print();
}
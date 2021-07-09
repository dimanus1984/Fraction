#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimitr "\n--------------------------------------------------\n"

class Element
{
	int Data;
	Element* pNext;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
/*=======================================================================================================================*/
class ForwardList
{
	Element* Head;
public:
	ForwardList()				//Default constructor - создает пустой список.
	{
		this->Head = nullptr;	//Если голова указывает на 0, то список пуст.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	/*=======================================================================================================================*/
	//			Adding elements:
	void push_front(int Data)
	{
		/*
		// Добавление элемента в начало списка.
		// 1) Создаем элемент:
		Element* New = new Element(Data);
		// 2) Прикрепляем новый элемент к списку:
		New->pNext = Head;
		// 3) Адрес нового элемента помещаем в голову, после чего новый элемент является начальным элементом списка.
		Head = New;
		*/
		// Упрощенная запись:
		Head = new Element(Data, Head);
	}
	/*=======================================================================================================================*/
	void push_back(int Data)
	{
		if (Head == nullptr)	//Если список пуст, вызываем метод, который умеет добавлять элемент в пустой список.
		{
			return push_front(Data);
			//return;
		}
		// 1) Создаем новый элемент
		// Element* New = new Element(Data);
		// 2) Дойти до конца списка (до последнего элемента):
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;	// Переходим на следующий элемент.
		// 3) В pNext последнего элемента добавить адрес нового элемента:
		Temp->pNext = new Element(Data);
	}
	/*=======================================================================================================================*/
	void insert(int Index, int Data)			//insert вставляет значение в список по указанному индексу.
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)		//i < Index - 1; т.е. сделать на один переход меньше, потому-что мы вместо него вставляем элемент
		{
			Temp = Temp->pNext;
			if (Temp->pNext == nullptr)break;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}
	/*=======================================================================================================================*/
	void pop_front()
	{
		Element* del_element = Head;	// Запоминаем адрес удаляемого элемента
		Head = Head->pNext;				// Исключает элемент из списка.
		delete del_element;				// Удаляем элемент из памяти.
	}
	/*========================================================================================================================*/
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
			Temp = Temp->pNext;			// Переход на следующий элемент
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}
	/*=======================================================================================================================*/
	void erase(int Index)						// Удаляет значение из списка по индексу.
	{
		if (Index == 0)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)		// i < index - 1; т.е. сделать на один переход меньше, чем индекс удаляемого элемента.
			Temp = Temp->pNext;					// Дошли до нужного элемента
		Element* del_element = Temp->pNext;		// Запоминаем адрес удаляемого элемента.

		delete del_element;
	}
	/*=======================================================================================================================*/
	//			Methods:
	void print()const
	{
		Element* Temp = Head;	// Temp - это итератор.
		while (Temp)			// Итератор - это указатель при помощи которого можно получить доступ к элементам структуры данных.
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	// Переход на следующий элемент.
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();

	int index, value;
	cout << "Введите добавляемое значение в конец списка: "; cin >> value;
	list.push_back(value);
	list.print();

	cout << delimitr << endl;

	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	list.insert(index, value);
	list.print();

	cout << delimitr << endl;

	cout << "Удаляемое значение в начале списка:" << endl;
	list.pop_front();
	list.print();

	cout << delimitr << endl;

	cout << "Удаляемое значение в конце списка:" << endl;
	list.pop_back();
	list.print();
}
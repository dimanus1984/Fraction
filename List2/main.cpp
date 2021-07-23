#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

class List
{
	class Element
	{
		int Data;		// Значение элемента.
		Element* pNext;	// Указатель на следующий элемент.
		Element* pPrev;	// Указатель на предыдущий элемент.
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) :Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head, * Tail;
	//Element* Head;	// Указатель на начальный элемент списка.
	//Element* Tail;	// Указатель на конечный элемент списка.
	size_t size;		// Размер списка.
public:
	/*=======================================================================================================================*/
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "ITConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ITDestructor:\t" << this << endl;
		}
		Iterator& operator++()		// Prefix increment.
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)	// Postfix increment.
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()		// Prefix decrement будет переходить на предыдущий элемент.
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)	// Postfix decrement.
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	/*=======================================================================================================================*/
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
			cout << "RIConstructor:\t" << this << endl;
		}
		~ReverseIterator()
		{
			cout << "RIDestructor:\t" << this << endl;
		}
		ReverseIterator& operator++()		// Prefix increment.
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)		// Postfix increment.
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()		// Prefix decrement.
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)		// Postfix decrement.
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
		{
			return Temp->Data;
		}
	};
	/*=======================================================================================================================*/
	size_t get_size()const
	{
		return size;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	ReverseIterator rev_begin()
	{
		return Tail;
	}
	ReverseIterator rev_end()
	{
		return nullptr;
	}
	/*=======================================================================================================================*/
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	explicit List(size_t size, int value = int()) :List()
	{
		while (size--)push_back(value);
	}
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* i = il.begin(); i != il.end(); i++)push_back(*i);
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t" << this << endl;
	}
	/*=======================================================================================================================*/
	//			Operators:
	int& operator[](size_t index)
	{
		Element* Temp;
		if (index >= size)throw std::exception("Error: out of range");
		if (index < size / 2)
		{
			Temp = Head;
			for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (size_t i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;	//i < size - Index - 1; - это просто количество переходов, делаем на один переход меньше.
		}
		return Temp->Data;
	}
	/*=======================================================================================================================*/
	//			Addidng elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;*/
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}
	void insert(size_t index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		if (index == size)return push_back(Data);
		// 1) Доходим до позиции, на которую нужно вставить элемент:
		Element* Temp;
		if (index < size / 2)	// Если index < size / 2, тогда идем сначала.
		{
			Temp = Head;
			for (size_t i = 0; i < index; i++)Temp = Temp->pNext;	// Заходим через голову, и идем по списку вперед.
		}
		else
		{
			Temp = Tail;
			for (size_t i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;	// Переходим на предыдущий элемент. i < size - Index - 1; - это просто количество переходов.
		}
		// 2) Создаем элемент и включаем его в список:
		/*Element* New = new Element(Data);
		New->pPrev = Temp->pPrev;
		New->pNext = Temp;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
		size++;
	}
	/*=======================================================================================================================*/
	//			Removing elements:
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		// 1) Исключаем элемент из списка:
		Head = Head->pNext;
		// 2) Удаляем элемент из списка:
		delete Head->pPrev;
		// 3) "Забываем" об удаляемом элементе:
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
			size--;
			return;
		}
		// 1) Исключаем элемент из списка:
		Tail = Tail->pPrev;
		// 2) Удаляем элемент из списка:
		delete Tail->pNext;
		// 3) Затираем об удаляемом элементе:
		Tail->pNext = nullptr;
		size--;
	}
	void erase(size_t index)	// Удаляет значение по индексу.
	{
		if (index == 0)return pop_front();
		if (index == size - 1)return pop_back();	// Удаление последнего элемента
		if (index >= size)return;
		Element* Temp;
		if (index < size / 2)	// Иду сначала списка.
		{
			Temp = Head;
			for (size_t i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (size_t i = 0; i < size - index - 1; i++)Temp = Temp->pPrev;
		}
		// Для удаления элемента из списка сначала нужно исключить элемент из списка.
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
	}
	/*=======================================================================================================================*/
	//			Methods:
	void print()const
	{
		cout << "Head:" << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
	}
	void reverse_print()const
	{
		cout << "Tail:" << Tail << endl;
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
	}
};

//#define BASE_CHECK
//#define SIZE_CONSTRUCTOR_AND_SYBSCRIPT
//#define HARDCORE
#define ITERATORS_CHECK
//#define COPY_CONSTRUCTOR_CHECK
//#define COPY_ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef BASE_CHECK
	int n; cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	size_t index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();
	list.reverse_print();
	/*list.pop_front();
	list.print();
	list.reverse_print();*/

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_SYBSCRIPT
	int n; cout << "Введите размер списка: "; cin >> n;
	List list(n);
	for (size_t i = 0; i < list.get_size(); i++)list[i] = rand() % 100;
	for (size_t i = 0; i < list.get_size(); i++)cout << list[i] << tab; cout << endl;
	for (int i = list.get_size() - 1; i >= 0; i--)cout << list[i] << tab; cout << endl;
#endif // SIZE_CONSTRUCTOR_AND_SYBSCRIPT

#ifdef HARDCORE
	List list = { 3,5,8,13,21 };						// Initializer List
	list.print();
	for (int i : list)cout << i << tab; cout << endl;	// Здесь нужны методы begin() и and() реализованные в конструкторе List. 

#endif // HARDCORE

#ifdef ITERATORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	for (List::Iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << tab;
	cout << endl;
	for (List::ReverseIterator i = list.rev_begin(); i != list.rev_end(); ++i)	// Выводит список в обратном направлении.
		cout << *i << tab;
	cout << endl;
#endif // ITERATORS_CHECK

#ifdef COPY_CONSTRUCTOR_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	list.reverse_print();
	List list2 = list;
	list2.print();
	list2.reverse_print();
#endif // COPY_METHODS_CHECK

#ifdef COPY_ASSIGNMENT_CHECK
	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	list.reverse_print();
	List list2;
	list2 = list;
	list2.print();
	list2.reverse_print();
#endif // COPY_ASSIGNMENT_CHECK
}
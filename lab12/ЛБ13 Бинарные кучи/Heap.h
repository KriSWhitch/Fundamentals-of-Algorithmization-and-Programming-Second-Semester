#pragma once
//------------ Прототипы функций ------------

struct AAA // Служебная структура
{
	int x; // Наш ключ
	void print(); // Вывод значения ключа
	int getPriority() const; // Приоритет элемента кучи
};


namespace heap
{
	enum CMP // Данные, требуемые для функции сравнения
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};

	// Структура нашей кучи
	struct Heap
	{
		int size; // Размер кучи
		int maxSize; // Максимальный размер кучи
		void** storage; // Хранимые данные    

		CMP(*compare)(void*, void*); // Функция сравнения

		//---------- Конструктор кучи ----------

		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0; // По умолчанию размер кучи ноль
			storage = new void *[maxSize = maxsize]; // Выделяем место для хранения данных(у нас это массив)
			compare = f; // Указываем на функцию CMP
		};

		int left(int ix); // Левое поддерево
		int right(int ix); // Правое поддерево
		int parent(int ix); // Родитель

		// Проверка на заполненность кучи
		bool isFull() const
		{
			return (size >= maxSize);
		};

		// Проверка на пустоту кучи
		bool isEmpty() const
		{
			return (size <= 0);
		};

		//----------- Функции сравнения элементов -----------

		bool isLess(void* x1, void * x2) const
		{
			return compare(x1, x2) == LESS; // Один меньше другого
		};

		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT; // Один больше другого
		};

		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL; // Один равен другому
		};

		void swap(int i, int j); // Перетасовка элементов
		void heapify(int ix); // Сортировка кучи max -> min
		void insert(void* x); // Вставка элемента
		void* extractMax(); // Удалить максимальный элемент
		void scan(int i) const; // Вывод элементов на экран

		//-------------- Новые функции --------------

		void* extractMin(); // Удалить минимальный элемент
		void* extractI(int ix); // Удалить элемент, введённый с клавиатуры
		int findMin(); // Поиск минимального элемента
		void swapParent(int ix); // Смена индексов с родителем
		void deleteHeap(); // Удаление кучи (нужно для объединения куч)
		void* extractHead();
	};

	Heap create(int maxsize, CMP(*f)(void*, void*)); // Создание кучи(максимальный размер, сравнение элементов)
};

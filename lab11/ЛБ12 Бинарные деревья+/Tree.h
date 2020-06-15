#pragma once
//---------------- Прототипы функций ----------------
#include <iostream>
namespace btree // Дпнное пространство имён используется для того, чтобы избежать конфликтов
{
	enum CMP // Используется для сравнения
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	// Node выступает как одна огромная структура с функциями, 
	//Которые можно вызвать через demoTree.Root->название_функции(аргументы)

	//---------------- Структура звеньев нашего дерева ----------------

	struct Node 
	{
		Node* parent;  // Указатель на родителя  
		Node* left;    // Указатель на левую ветвь
		Node* right;   // Указатель на правую ветвь
		void* data;    // Указатель на данные 

		//-------------- Конструктор --------------

		Node(Node* p, Node* l, Node* r, void* d) 
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}

		Node* next();  // Следующий по ключу
		//Node* prev(); // Предыдущий по ключу
		Node* min(); // Минимум в поддереве
		Node* max();  // Максимум в поддереве  

		//-------- Новые функции --------
		void scanDown(void(*f)(void* n)); // Обход поддерева сверху вниз (Нисходящий)
		void scanUp(void(*f)(void* n)); // Обход дерева снизу вверх (Восходящий)
		void scanMix(void(*f)(void* n)); // Смешанный обход
		bool isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)); // Проверка сбалансированности дерева
		int testDepth(int(*f)(int a, int b)); // Проверка глубины
		int amount_vetvi(Node *p); // Количество ветвей до вершины с искомым ключом

		//void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int); // Обход по уровню
		int getLevel(); // Получить значение уровня
		void scanByLevel(void(*f)(void* n));
	};

	//------------------------ Интерфейс бинарного дерева ------------------------

	struct Object 
		// В нашем случае структура Object выступает как набор методов demoTree
		//Эти методы вызываются так: demoTree.название_метода(аргументы)
	{
		Node* Root;  // Указатель на корень 
		CMP(*compare)(void*, void*);  // Функция сравнения, где *compare - указатель на функцию с аргументами (void*, void*)
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL; // Указатель на корень(как значение по умолчанию)
			compare = f; // ! Указатель на функцию с типом данных CMP !
		};

		//-------- Новые функции --------
		int show_vetvi(void* d, Node* n); //Вывод САМИХ ВЕТВЕЙ и количества ветвей до вершины с ключом
		int amount_vetvi2(Node *p); // Количество ветвей до вершины с искомым ключом
		void view_vetvi(Node *n); // Для вывода ветвей

		// Данные функции возвращают нам результаты сравнения двух элементов нашего дерева
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS; // Меньше
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT; // Больше
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL; // Равно
		};
		bool insert(void* data); // Добавить элемент
		Node* search(void* d, Node* n); // Найти элемент
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);  // Удалить по адресу элемента 
		bool deleteByData(void* data) // Удалить по ключу
		{
			return deleteByNode(search(data));
		};

		bool isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)) // Проверка сбалансированности
		{
			Root->isBalanced(f1, f2);
		}

		int testDepth(int(*f)(int a, int b)) // Проверка глубины
		{
			Root->testDepth(f);
		}
	};

	Object create(CMP(*f)(void*, void*)); // Создать бинарное дерево    
};

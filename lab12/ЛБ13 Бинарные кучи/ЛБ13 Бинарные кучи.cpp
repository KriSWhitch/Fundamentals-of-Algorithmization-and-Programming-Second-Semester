// ЛБ13 Бинарные кучи.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Heap.h"
#include <iostream>
using namespace std;

//------- Функция сравнения -------
heap::CMP cmpAAA(void*  a1, void* a2)  
{
	// Здесь мы создаём два элемента для сравнения
	#define A1 ((AAA*)a1)
	#define A2 ((AAA*)a2)
	// Сравниваем их
	heap::CMP
		rc = heap::EQUAL; 
		if (A1->x  >  A2->x) // если первый больше второго
			rc = heap::GREAT; // Присваиваем значение БОЛЬШЕ
		else
			if (A2->x  > A1->x) // если второй больше первого
			rc = heap::LESS; // Присваиваем значение МЕНЬШЕ
		return rc;
	#undef A2
	#undef A1 
}

//---------- Объединение нескольких куч ----------
void Union(heap::Heap &h, heap::Heap &newh) // В качестве аргументов принимает адреса первой и второй кучи
{
	int k;
	cout << "\tДля прекращения ввода введите ноль" << endl;
	cout << "Введите ключи для новой кучи: ";
	do
	{
		AAA *a = new AAA;
		cin >> k;
		if (k == 0) // Если ключ равен нулю
			break; // Прекращаем ввод
		a->x = k; // Если нет, то заносим введённое значение в поле ключа
		newh.insert(a); // Вставляем его в новую кучу
	} while (true);
	cout << "Новая куча: " << endl;
	newh.scan(0); // Выводим кучу от 
	// В этом цикле мы вставляем элементы из новой кучи в старую
	while (newh.size) 
	{
		h.insert(newh.extractI(1)); // Вставку производим путём извлечения из новой кучи
		//элементов, начиная с первого
	}
	newh.deleteHeap();// После удаляем нашу кучу
	cout << "Объединение завершено!" << endl;
}

//------- Основная функция -------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, choice;

	heap::Heap h1 = heap::create(30, cmpAAA); // Первая куча
	heap::Heap h2 = heap::create(15, cmpAAA); // Вторая куча
	for (;;)
	{
		cout << "1 - Вывод кучи на экран" << endl;
		cout << "2 - Добавить элемент (dop1)" << endl;
		cout << "3 - Удалить максимальный элемент" << endl;
		cout << "4 - Удалить минимальный элемент" << endl;
		cout << "5 - Удалить введённый элемент" << endl;
		cout << "6 - Объеденить две кучи в одну" << endl;
		cout << "7 - Упорядочить кучу (dop2)" << endl;
		cout << "8 - Удаление вершины кучи (dop3)" << endl;
		cout << "0 - Выход" << endl;
		cout << "\nСделайте выбор: "; cin >> choice;
		switch (choice)
		{
			case 0:  exit(0);
			case 1:  h1.scan(0);
				break;
			case 2: 
				{		
					AAA *a = new AAA;
					cout << "\nВведите ключ: "; cin >> k;
					a->x = k;
					h1.insert(a);
				}
				break;
			case 3:
				if (h1.extractMax())
				{
					cout << "Элемент был успешно удалён!" << endl;
				}
				break;
			case 4: 
				if (h1.extractMin())
				{
					cout << "Элемент был успешно удалён!" << endl;
				}
				break;
			case 5:
					int i;
					cout << "Введите индекс удаляемого элемента: "; cin >> i;
					if (h1.extractI(i))
					{
						cout << "Элемент был успешно удалён!" << endl;
					}
					break;
			case 6: Union(h1, h2);
				break;
			case 7:
				int f;
				cout << "Введите индекс элемента относительно которого упорядочиваем очередь: "; cin >> f;
				h1.heapify(f);
				break;
			case 8:
				if (h1.extractHead())
				{
					cout << "Элемент был успешно удалён!" << endl;
				}
				break;
			default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} 
	return 0;
}

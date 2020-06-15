// Библиотека. Создать хеш-таблицу со следующими полями: номер книги, название книги. Ключ – номер книги. Номер книги – случайное число.

#include "stdafx.h"
#include "stdafx.h"
#include "HashTwinChain.h"
#include <iostream>
using namespace std;


struct AAA // Данная структура будет записываться в хеш-таблицу
{
	int key; // Ключ (Номер книги)
	char* mas; // Строка (Название книги)
	AAA(int k, char* z) // Конструктор
	{
		key = k;
		mas = z;
	}
	AAA() // Указываем значения по умолчанию
	{
		key = 0;
		mas = (char*)"";
	}
};

//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}

//------ Вывод пары ключ-значение ------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->Data)->key << " - " << ((AAA*)e->Data)->mas << " / ";
}

//-------- Вывох элементов хеш-таблицы --------
void listx::Object::scan()
{
	listx::Element* e = this->getFirst();
	while (e != NULL)
	{
		std::cout << ((AAA*)e->Data)->key << " - " << ((AAA*)e->Data)->mas << " |----| ";
		e = e->getNext();
	};
}


//------- Поиск элемента хеш-таблицы -------
listx::Element* listx::Object::search(void* data)
{
	listx::Element* rc = head;
	while ((rc != NULL) && ((((AAA*)rc->Data)->key) != ((AAA*)data)->key))
		rc = rc->Next;
	return rc;
}


void main_menu()
{
	cout << "1 - Вывод хеш-таблицы" << endl;
	cout << "2 - Добавление элемента" << endl;
	cout << "3 - Удаление элемента" << endl;
	cout << "4 - Поиск элемента" << endl;
	cout << "0 - Выход" << endl;
}
//------------ Основная функция ------------

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int current_size = 10;
	//cout << "Введите размер хеш-таблицы - "; cin >> current_size;

	hashTC::Object H = hashTC::create(current_size, hf);

	// Вставляем некоторые элементы
	AAA a1(4312, (char*)"Кто-то || Буратино"),
		a2(4574, (char*)"А.С.Пушкин || Сборник стихов"),
		a3(9901, (char*)"Л.Н.Толстой || Война и Мир. Полное собрание"),
		a4(3245, (char*)"Жуль Верн || 20 000 лье под водой");
	H.insert(&a1);
	H.insert(&a2);
	H.insert(&a3);
	H.insert(&a4);
	H.Scan(); // Выводим их на экран


	int choice;
	int k;
	for (;;)
	{
		main_menu();
		choice = NULL;
		cout << "Сделайте выбор: "; cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.Scan();
			break;
		case 2:
		{
			AAA* a = new AAA;
			char* str = new char[60];
			cout << "Максимальное значение ключа - 10 000!\n";
			cout << "Введите номер книги (от 1 до 10 000): "; cin >> k;
			a->key = k;
			cout << "Введите название книги: "; cin >> str;
			a->mas = str;
			H.insert(a);
		} break;
		case 3:
		{
			AAA* b = new AAA;
			cout << "Введите номер книги: "; cin >> k;
			b->key = k;
			H.deleteByData(b);
		} break;
		case 4:
			AAA * c = new AAA;
			cout << "Введите номер книги: "; cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Книга не найдена!" << endl;
			else
			{
				cout << "Первая книга с данным ключом" << endl;
				AAA_print(H.search(c));
				cout << endl;
			} break;
		}
	}
	return 0;
}

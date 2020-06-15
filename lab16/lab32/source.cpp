//Клиенты банка. Реализовать хеш-таблицу со следующими полями: номер счета, ФИО. Ключ – номер счета.

#include "stdafx.h"
#include "Hash.h"
#include <iostream>
using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
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
listx::Element* listx::Object::search(void* Data)
{
	listx::Element* rc = head;
	while ((rc != NULL) && ((((AAA*)rc->Data)->key) != ((AAA*)Data)->key))
		rc = rc->Next;
	return rc;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->Data)->key << ' - ' << ((AAA*)e->Data)->mas << " / ";
}
void listx::Object::scan()
{
	listx::Element* e = this->getFirst();
	while (e != NULL)
	{
		std::cout << ((AAA*)e->Data)->key << '-' << ((AAA*)e->Data)->mas << " / ";
		e = e->getNext();
	};
}
//-------------------------------
void menu()
{
	cout << "1 - вывод хэш-таблицы" << endl;
	cout << "2 - добавление элемента" << endl;
	cout << "3 - удаление элемента" << endl;
	cout << "4 - поиск элемента" << endl;
	cout << "0 - выход" << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int table_size = 256;
	hashTC::Object H = hashTC::create(table_size, hf);
	AAA a1(22360015, (char*)"Mukovozchik Alexel Vitalievich"), 
		a2(22360019, (char*)"NoName User"),
		a3(22360029, (char*)"NoName User2"), 
		a4(22360002, (char*)"NoName User3");
	H.insert(&a1);
	H.insert(&a2); H.insert(&a3); H.insert(&a4);
	H.Scan();
	menu();
	int choice;
	int k;
	for (;;)
	{
		cout << "Ввод: ";
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {
			AAA* a = new AAA;
			char* str = new char[20];
			cout << "Введите номер счета: ";
			cin >> k;
			a->key = k;
			cout << "Введите ФИО: ";
			cin.ignore();
			gets_s(str, 20);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {
			AAA* b = new AAA;
			cout << "Введите номер счета: ";
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "Введите номер счета: ";
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден" << endl;
			else
			{
				cout << "Первый человек с данным номером счета" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}


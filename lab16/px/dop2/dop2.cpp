// ЛБ15 Хеш-таблицы с цепочками.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Hash Twin-chain.h"
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

//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}

//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int current_size;
	cout << "Введите размер хеш-таблицы: " << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - Вывод хеш-таблицы" << endl;
		cout << "2 - Добавление элемента" << endl;
		cout << "3 - Удаление элемента" << endl;
		cout << "4 - Поиск элемента" << endl;
		cout << "0 - Выход" << endl;
		cout << "\nСделайте выбор: "; cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1: H.Scan();
			break;
		case 2:
		{
			AAA* a = new AAA;
			char* str = new char[5];
			cout << "Введите ключ: "; cin >> k;
			a->key = k;
			cout << "Введите строку: "; cin >> str;
			a->mas = str;
			H.insert(a);
		} break;
		case 3:
		{
			AAA* b = new AAA;
			cout << "Введите ключ: "; cin >> k;
			b->key = k;
			H.deleteByData(b);
		} break;
		case 4:
			AAA * c = new AAA;
			cout << "Введите ключ: "; cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Элемент не найден!" << endl;
			else
			{
				cout << "Первый элемент с данным ключом - ";
				AAA_print(H.search(c));
				cout << endl;
			} break;
			//default: cout << "Введено неверноее значение! Попробуйте снова" << endl;
		}
	}
	return 0;
}



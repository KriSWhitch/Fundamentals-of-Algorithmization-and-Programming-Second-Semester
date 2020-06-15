//Составить хеш-таблицу, содержащую буквы и количество их вхождений во введенной строке. 
//Вывести таблицу на экран. Осуществить поиск введенной буквы в хеш-таблице.

#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Twin_Chain.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// Структура "вхождение буквы"
struct Letter
{
	// Буква
	char character;
	// Количество вхождений
	int number;

	// Конструктор буквы
	Letter(char c, int i)
	{
		character = c;
		number = i;
	}

	// Конструктор без параметров
	Letter()
	{
		number = 0;
	}
};

// Хеш-функция
int hf(void* key)
{
	return (int)((Letter*)key)->character;
}



// Получение данных
void readString(hashTC::Object& H)
{
	char str[256];
	cout << "Введите строку: ";
	cin >> str;

	// Цикл по символам строки
	for (size_t i = 0; i < strlen(str); i++)
	{
		Letter* l = new Letter;
		Letter* l1 = new Letter;
		l->character = str[i];
		l1->character = str[i];
		// Если символ не найден
		if (H.search(l) == NULL)
		{
			// Тогда это первое вхождение
			l1->number = 1;
			// Вставляем в таблицу
			H.insert(l1);
		}
		else
		{
			// Иначе увеличиваем на 1 число вхождений
			l1->number = ((Letter*)(H.search(l)->data))->number + 1;
			H.setValue(l, l1);
		}
	}
}

// Вывод на экран
void Letter_print(listx::Element* e)
{
	std::cout << ((Letter*)e->data)->character << '-' << ((Letter*)e->data)->number << " / ";
}

// Основная программа
int main()
{
	setlocale(LC_ALL, "rus");

	int current_size = 7;
	// Создание таблицы
	cout << "Введите размер хеш-таблицы: ";
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	char c;
	// Бесконечный цикл
	for (;;)
	{

		cout <<endl<< "1 - вывод хеш-таблицы" << endl;
		cout << "2 - ввод строки" << endl;
		cout << "3 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		
		cout << "Сделайте выбор: ";
		cin >> choice;
	
		cout << endl;
		switch (choice)
		{
			// 0 - выход
		case 0:
			exit(0);
			// 1 - вывод таблицы
		case 1:
			H.Scan();
			break;
			// 2 - добавление элемента
		case 2:
		{
			readString(H);
			break;
		}
		break;
		// 3 - поиск элемента
		case 3:
		{
			Letter* l = new Letter;
			cout << "Введите букву: ";
			cin >> c;
			l->character = c;
			// Если поиск не увенчался успехом
			if (H.search(l) == NULL)
				// Вывод сообщения
				cout << "Буква не найдена!" << endl;
			else
			{
				// Иначе вывод найденного первого элемента
				cout << "Буква с данным ключом: ";
				Letter_print(H.search(l));
			}
			cout << endl;
		}
		break;
		}
	}
	return 0;
}

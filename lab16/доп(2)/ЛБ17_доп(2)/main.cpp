/*Построить хеш-таблицу из слов произвольного текстового файла, задав ее размерность с экрана. Вывести построенную таблицу слов на экран. Осуществить поиск введенного слова. 
Выполнить программу для различных размерностей таб-лицы и сравните количество сравнений. Удалить все слова, начинающиеся на указанную букву, выведите таблицу.*/

#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Twin_Chain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int choice;
// Структура "строка из файла"
struct StrFile
{
	// Первая буква строки
	char character;
	// Строка
	string str;

	// Конструктор строки из файла
	StrFile(char c, string s)
	{
		character = c;
		str = s;
	}

	// Конструктор без параметров
	StrFile()
	{
	}
};

// Хеш-функция
int hf(void* key)
{
	return (int)((StrFile*)key)->character;
}

// Чтение файла
void readFile(hashTC::Object& H)
{
	ifstream file("2.txt");
	if (file.is_open())
	{
		// Пока файл не закончился
		string line;
		while (getline(file, line))
		{
			StrFile* sf = new StrFile;
			// Читаем по строке
			sf->character = line[0];
			sf->str = line;
			H.insert(sf);
		}
		file.close();
	}
}

// Вывод на экран
void StrFile_print(listx::Element* e)
{
	std::cout << ((StrFile*)e->data)->character << '-' << ((StrFile*)e->data)->str << " / ";
}

void menu() {
	cout << endl;
	cout << "1 - вывод хеш-таблицы" << endl;
	cout << "2 - чтение из файла" << endl;
	cout << "3 - поиск элемента" << endl;
	cout << "4 - удаление элемента" << endl;
	cout << "5 - анализ количества сравнений" << endl;
	cout << "0 - выход" << endl;

	cout << "Сделайте выбор: ";
	cin >> choice;
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
	char c;
	// Бесконечный цикл
	for (;;)
	{
	

		menu();
		
		switch (choice)
		{
			// 0 - выход
		case 0:
			exit(0);
			// 1 - вывод таблицы
		case 1:
			cout << endl;
			H.Scan();
			break;
			// 2 - добавление элемента
		case 2:
		{
			readFile(H);
			break;
		}
		break;
		// 3 - поиск элемента
		case 3:
		{
			cout << endl;
			StrFile* l = new StrFile;
			cout << "Введите слово: ";
			char str[256];
			cin >> str;
			l->character = str[0];
			l->str = str;
			// Если поиск не увенчался успехом
			int index;
			if (H.search(l, index) == NULL)
				// Вывод сообщения
				cout << "Слово не найден!" << endl;
			else
			{
				cout << "Поиск слова: ";
				cout << "Ячейка: " << index << ". Слово:  ";
				StrFile_print(H.search(l, index));
			}
			cout << endl;
		}
		break;
		// Удаление по букве
		case 4:
		{
			cout << endl;
			StrFile* l = new StrFile;
			cout << "Введите букву: ";
			cin >> c;
			l->character = c;
			int index, cmp;
			// Пока есть строки, начинающиеся на эту букву, удаляем
			while (H.search(l, index, cmp) != NULL)
				H.deleteByData(l);
			H.Scan();
		}
		break;
		// Сравнение
		case 5:
		{
			cout << endl;
			int cmp, index;
			hashTC::Object H1 = hashTC::create(3, hf);
			readFile(H1);
			StrFile* l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "Размер: 3. Количество сравнений: " << cmp << endl;

			H1 = hashTC::create(5, hf);
			readFile(H1);
			l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "Размер: 5. Количество сравнений: " << cmp << endl;

			H1 = hashTC::create(20, hf);
			readFile(H1);
			l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "Размер: 20. Количество сравнений: " << cmp << endl;
		}
		}
	}
	return 0;
}

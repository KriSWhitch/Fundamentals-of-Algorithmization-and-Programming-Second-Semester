//Создать очередь для символов и функции для ввода, вывода и определения размера очереди.Вве - сти символы с экрана в очередь.В случае совпадения вводимого символа с последним элементом оче - реди удалить первых три элемента.

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
using namespace std;

void mainMenu() {
	cout << "\t\tВыберите, что вы хотите сделать:\n";
	cout << "1 - Создание очереди\n";
	cout << "2 - Вывод очереди\n";
	cout << "3 - Ввод нового элемента в очередь\n";
	cout << "4 - Размер очереди\n";
	cout << "0 - Выход из программы\n";
}

//--------------------------- Основная программа ---------------------


int main()
{
	setlocale(LC_ALL, "Russian");

	Queue* begin = NULL, * end, * t; // Сформировали напчало списка
	t = new Queue;

	int menu; // Для навигации в меню
	int size; // size - максимальный размер очереди
	char p; // Вводимый символ

	do
	{
		mainMenu();
		cin >> menu;

		//------------- Меню программы -------------
		switch (menu)
		{
		case 1: 	cout << "Введите максимальный размер очереди: "; cin >> size;
			cout << "\nВведите символ(Один! Латиницей!): "; cin >> p;
			// Первый элемент
			t->info = p;
			t->next = NULL;
			begin = end = t;
			for (int i = 1; i < size; i++) // Создание очереди
			{
				cout << "Введите символ: "; cin >> p;
				createQueue(&begin, &end, p);
			}
			break;
		case 2: 	cout << "\n\tЭлементы очереди: \n";
			viewQueue(begin);
			break;
		case 3:
			cout << "Введите символ для нового звена очереди: "; cin >> p;
			insertInQueue(&begin, &end, p, size);
			cout << "Новая очередь\n";
			viewQueue(begin);
			break;
		case 4: cout << "В очереди " << QueueSize(begin) << " элементов/та\n";
			break;
		case 0: exit(0); break;
		default: cout << "Неверный ввод, попробуйте ещё раз!\n";
			break;
		}
	} while (menu != 0);
}
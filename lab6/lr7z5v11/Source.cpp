#include <iostream>
#include <Windows.h>
#include "MyStack.h"

using namespace std;

void menu() {
	cout << "Выберите действие:" << endl;
	cout << "1. Ввести новое значение." << endl;//выполнить команду push (число вводится с клавиатуры)
	cout << "2. Последнее занесенное значение." << endl;//выполнить команду pop (результат будет выведен на экран)
	cout << "3. Удалить все элемнты из стека кратные 3-м." << endl;
	cout << "4. Прочитать стек из файла (имя файла должно быть указано с клавиатуры)." << endl;
	cout << "5. Записать стек в файл (имя файла должно быть указано с клавиатуры)." << endl;
	cout << "6. Слово наоборот." << endl; //дополнительное задание №2 
	cout << "7. Самое короткое слово" << endl; //дополнительное задание №3
	cout << "8. Очистить стек." << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	stack *p = nullptr;
	StackEl *myStk = new StackEl; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	
	int buff[20];
	int choice;
	while (true) 
	{
//		system("cls");

		menu();
		
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Введите значение для занесения в стек:" << endl;
			int val;
			cin >> val;
			push(p, val);
			break;
		}
		case 2: 
		{
			cout << "Последнее занесённое значение: " << pop(p)<<endl;
			break;
		}
		case 3:
		{
			deleteNeKrat3(p);
			break;
		}
		case 4:
		{
			cout << "Введите имя файла, из которого вы хотите прочитать стек:" << endl;
			string filename;
			cin >> filename;
			readStackFromFile(filename, p);
			break;
		}
		case 5: 
		{
			cout << "Введите имя файла в который вы хотите записать стек:" << endl;
			string filename;
			cin >> filename;
			writeStackToFile(filename, p);
			break;
		}
		case 6:
		{
			switch_word();
			break;
		}
		case 7:
		{
			operate stek = create();
			stek.read();
			stek.print();
		}
		case 8: 
		{
			clear(p);
			break;
		}
		default: 
		{
			cout << "Неверный выбор!" << endl;
		}
		}

		//Sleep(2500);
	}

	return 0;
}

//Изменить функцию вычисления хеш для решения коллизии на функцию, которая строится на основе формулы:
//h(key, i) = (h1(key) + i∙h2(key))mod hashTableSize, где  h1 (key) = key*mod hashTableSize , h2(key) = 1 + (key*mod hashTableSize ). 

#include <iostream>
#include "HashTable.h"

const int SIZE = 300;

using namespace std;

void menu() {
	cout << "1 - Добавить новый номер" << endl;
	cout << "2 - Удалить номер" << endl;
	cout << "3 - Найти номер" << endl;
	cout << "4 - Показать таблицу" << endl;
	cout << "0 - exit" << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	HashTable table(SIZE);
	while (true) {
		menu();

		int choice;
		bool exit = false;
		cin >> choice;
		switch (choice) {
		case 0:
			exit = true;
			break;
		case 1: {
			cout << "Введите номер: ";
			int x;
			cin >> x;
			table.insert(x);
			break;
		}
		case 2: {
			cout << "Введите номер: ";
			int x;
			cin >> x;
			table.erase(x);
			break;
		}
		case 3: {
			cout << "Введите номер: ";
			int x;
			cin >> x;
			if (table.find(x) != -1) {
				cout << "Найдено!" << endl;
			}
			else {
				cout << "Не найдено!" << endl;
			}
			break;
		}
		case 4:
			table.displayTable(); cout << endl;
			break;
		default:
			break;
		}
		if (exit) break;
	}
	system("pause");
	return 0;
}
#include <iostream>
#include <string>
#include "HashTable.h"

const int SIZE = 100;

using namespace std;

void elementEntering(Element& elem) {

	cout << "Фамилия: ";
	cin >> elem.productName;
	cout << "Номер счёта: ";
	cin >> elem.year;
}

int main() {
	HashTable table(SIZE);
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "1 - Вставка нового элемента" << endl;
		cout << "2 - Удаление элемента" << endl;
		cout << "3 - Поиск элемента" << endl;
		cout << "4 - Показать таблицу" << endl;
		cout << "0 - Выход" << endl;

		int choice;
		bool exit = false;
		cin >> choice;
		switch (choice) {
		case 0:
			exit = true;
			break;
		case 1: {
			Element elem;
			elementEntering(elem);
			table.insert(elem);
			break;
		}
		case 2: {
			Element elem;
			elementEntering(elem);
			table.erase(elem);
			break;
		}
		case 3: {
			Element elem;
			elementEntering(elem);
			if (table.find(elem) != -1) {
				cout << "Found!" << endl;
			}
			else {
				cout << "Not found!" << endl;
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
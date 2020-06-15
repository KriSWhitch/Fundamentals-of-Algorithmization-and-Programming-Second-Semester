//Список электронных адресов. Создать хеш-таблицу со следующими полями:
//адрес, фами-лия абонента, год создания. Ключ – год создания.
#include <iostream>
#include <string>
#include "HashTable.h"

const int SIZE = 100;

using namespace std;

void elementEntering(Element& elem) {
	cout << "Enter Last name: ";
	cin >> elem.lastName;
	cout << "Enter address: ";
	cin >> elem.address;
	cout << "Enter year: ";
	cin >> elem.year;
}

int main() {
	HashTable table(SIZE);

	while (true) {
		cout << "1 - Insert a new element" << endl;
		cout << "2 - Delete an element" << endl;
		cout << "3 - Find an element" << endl;
		cout << "4 - Show the table" << endl;
		cout << "0 - exit" << endl;

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
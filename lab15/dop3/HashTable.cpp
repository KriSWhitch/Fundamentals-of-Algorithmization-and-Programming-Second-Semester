#include <iostream>
#include "HashTable.h"

using namespace std;

const int EMPTY_ELEMENT(numeric_limits<int>::min());   //определение пустого элемента(самого малого)

bool HashTable::isEmptyElement(const int& elem) const {
	return elem == EMPTY_ELEMENT;
}

HashTable::HashTable(const int& size) : arr(new int[size]), size(size), elemCount(0) { //конструктор
	for (int i = 0; i < size; i++) {                     //заполнение таблицы пустыми элементами
		arr[i] = EMPTY_ELEMENT;
	}
}

HashTable::~HashTable() {
	delete[] arr;
}

void HashTable::insert(const int& elem) {   //добавление
	int ind = 0, hash = -1;
	do {
		hash = computeHash(elem, ind++);    //Вычисляет хэш-значение для входных данных.
	} while (!isEmptyElement(arr[hash]));
	arr[hash] = elem;
	elemCount++;
}

void HashTable::erase(const int& elem) {  //удаление
	int hash = find(elem);
	if (hash != -1) arr[find(elem)] = EMPTY_ELEMENT;
	elemCount--;
}

int HashTable::find(const int& elem) {   //поиск
	const int ATTEMPTS = 1000;
	int ind = 0, hash = -1;

	do {
		hash = computeHash(elem, ind++);
		if (arr[hash] == elem) break;
	} while (!isEmptyElement(arr[hash]) && (ind != ATTEMPTS));
	return (arr[hash] == elem) ? hash : -1;
}

void HashTable::displayTable() const {   //показать таблицу
	for (int i = 0; i < size; i++) {
		if (!isEmptyElement(arr[i])) {
			cout << arr[i] << ' ';
		}
	}
}

void HashTable::showCoeff() const {   //показать коэффициент
	cout << "Occupancy rate is " << double(elemCount) / size << endl;
}

int HashTable::computeHash(const int& key, const int& index) const {   //задание
	const double GOLD = (sqrt(5) - 1) / 2;
	int hash1 = (int)(size * fmod(key * GOLD, 1) + index) % size;
	return (hash1 + 3 * index + 5 * index * index) % size;
}

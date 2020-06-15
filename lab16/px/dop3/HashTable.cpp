#include <iostream>
#include <vector>
#include <string>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(const int &size) : arr(size), size(size) {}

HashTable::~HashTable() {
	arr.clear();
}

void HashTable::insert(const Element &elem) {
	int hash = -1;
	hash = computeHash(elem.year, 0);
	if (find(elem) == -1) arr[hash].push_back(elem);
}

void HashTable::erase(const Element &elem) {
	int hash = computeHash(elem.year, 0);
	// arr[hash].begin() - итератор (указатель, который работает с объектами STL) на начало списка элементов с хэшем hash
	// Прибавляем к нему индекс искомого элемента, чтобы удалить его
	if (hash != -1) arr[hash].erase(arr[hash].begin() + find(elem));
}

int HashTable::find(const Element &elem) const {
	int hash = computeHash(elem.year, 0);
	for (int i = 0; i < arr[hash].size(); i++) {
		if (arr[hash][i] == elem) return i;
	}
	return -1;
}

void HashTable::displayTable() const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j].year << " | " << arr[i][j].address << " | " << arr[i][j].lastName << endl;
		}
	}
}

int HashTable::computeHash(const int &key, const int &index) const {
	return multiplicativeHash(key, index);
}

int HashTable::universalHash(const int &key, const int &index) const {
	int hash1 = 0, hash2 = 0;
	int tmp = key;

	for (int i = 1; tmp; i++) {
		hash1 += (tmp % 10) * i;
		tmp /= 10;
	}

	hash2 = (hash1 + 5 * index + 3 * index * index) % size;

	return hash2;
}

int HashTable::modulusHash(const int &key, const int &index) const {
	const int MOD = 100000007;
	return (key + index) % MOD;
}

int HashTable::multiplicativeHash(const int &key, const int &index) const {
	const double GOLD = (sqrt(5) - 1) / 2;
	return (int)(size * fmod(key * GOLD, 1) + index) % size;
}


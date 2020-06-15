#pragma once

extern const int EMPTY_ELEMENT;

class HashTable {
private:
	int* const arr;
	const int size;
	int elemCount;

	bool isEmptyElement(const int& elem) const;
public:
	HashTable(const int& size);
	~HashTable();


	void insert(const int& elem);
	void erase(const int& elem);

	int find(const int& elem);
	void displayTable() const;
	void showCoeff() const;


	int computeHash(const int& key, const int& index) const;
};


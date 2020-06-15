#pragma once
#include <string>
#include <vector>

using namespace std;

struct Element {
	int year; // key

	string address;
	string lastName;

	Element() : year(-1) {}
	Element(const int &yearr, const string &addresss, const string &lastNamee) : year(yearr), address(addresss), lastName(lastNamee) {}
	bool operator== (const Element &x) const {
		return ((this->year == x.year) &&
			(this->address == x.address) &&
			(this->lastName == x.lastName));
	}
};

class HashTable {
private:
	vector<vector<Element>> arr;
	const int size;
public:
	HashTable(const int &size);
	~HashTable();

	void insert(const Element &elem);
	void erase(const Element &elem);

	int find(const Element &elem) const;
	void displayTable() const;

	int computeHash(const int &key, const int &index) const;
	int universalHash(const int &key, const int &index) const;
	int modulusHash(const int &key, const int &index) const;
	int multiplicativeHash(const int &key, const int &index) const;
};


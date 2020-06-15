#include <iostream>
#pragma once


struct DataCell
{
	int number;
	int value = 1; //��� ������� ����
	std::string name;
	DataCell* nextptr;

	DataCell(int number, std::string name, DataCell* nexptr);
};

struct HashSet
{
	int size;
	DataCell** data;

	HashSet(int Size);
	~HashSet();

	void Print();
	void AddData(int number, std::string name);
	void DeleteData(int number);
	DataCell* FindData(int number);
};
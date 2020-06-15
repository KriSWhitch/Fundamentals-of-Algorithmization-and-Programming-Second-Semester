#include <iostream>
#include <Windows.h>
#include "Hash.h"

DataCell::DataCell(int number, std::string name, DataCell* nexptr) 
{
	this->number = number;
	this->name = name;
	this->nextptr = nexptr;
}

HashSet::HashSet(int size) 
{
	this->size = size;

	data = new DataCell*[size];

	for (int i = 0; i < size; i++) 
	{
		data[i] = nullptr;
	}
}

HashSet::~HashSet() 
{
	for (int i = 0; i < size; i++) 
	{
		delete data[i];
	}
	delete data;
}

void HashSet::Print()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << std::endl;
	for (int i = 0; i < size; i++) 
	{
		std::cout << "\tHASH: " << i << " DATA: ";
		if (data[i] == nullptr) 
		{
			std::cout << "null" << std::endl;
		}
		else 
		{
			DataCell* dataCell = data[i];
			while (dataCell != nullptr)
			{
				std::cout << dataCell->number << "(" << dataCell->name << ") -> ";
				dataCell = dataCell->nextptr;
				SetConsoleTextAttribute(hConsole, 12);
			}
			SetConsoleTextAttribute(hConsole, 15);
			std::cout << "null" << std::endl;
		}
	}
}

int HashFunction(int key, int size) 
{
	return abs((19 * key - 17) % size);
}

void HashSet::AddData(int number, std::string name) 
{
	int hash = HashFunction(number, size);

	if (data[hash] == nullptr)
	{
		data[hash] = new DataCell(number, name, nullptr);
	}
	else 
	{
		DataCell* lastDataCell = data[hash];
		while (lastDataCell->nextptr != nullptr)
		{
			lastDataCell = lastDataCell->nextptr;
		}
		lastDataCell->nextptr = new DataCell(number, name, nullptr);
	}
}

void HashSet::DeleteData(int number) 
{
	int hash = HashFunction(number, size);

	if (data[hash] != nullptr) 
	{
		DataCell* prev = nullptr;
		DataCell* curr = data[hash];

		while (curr != nullptr) 
		{
			if (curr->number == number) 
			{
				DataCell* tmp = curr;
				if(prev != nullptr)
				prev->nextptr = curr->nextptr;
				//костыль на месте
				if (curr == data[hash]) data[hash] = data[hash]->nextptr;
				delete tmp;
				break;
			}
			prev = curr;
			curr = curr->nextptr;
		}
	}
}

DataCell* HashSet::FindData(int number)
{
	int hash = HashFunction(number, size);

	if (data[hash] == nullptr) 
	{
		return nullptr;
	}
	DataCell* curr = data[hash];
	while (curr != nullptr)
	{
		if (curr->number == number) 
		{
			return curr;
		}
		curr = curr->nextptr;
	}			
	return nullptr;
}
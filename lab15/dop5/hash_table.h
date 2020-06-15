#pragma once
#include <string>
#include <fstream>
#include <iostream>

typedef struct Word {
	std::string word;
	std::string descript;
	Word* next;
} WORD;

class Hash_Table {
private:
	WORD** words;
	int size;
public:
	Hash_Table(int);
	int hash(std::string);
	bool insert(std::string, std::string);
	bool search(std::string);
	void print() const;
	void read_file(std::fstream* f);
	void restruct(int size);
};
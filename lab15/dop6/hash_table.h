#pragma once

typedef struct Word {
	std::string str;
	Word* next;
} WORD;

template<typename T>
class Hash_Table {
private:
	WORD** words;
	int size;
public:
	Hash_Table(int);
	~Hash_Table();
	int hash(char);
	bool insert(std::string);
	void read_file(std::fstream* f);
	void print() const;
	bool del(char);
	void search(std::string);
};

#include "D:\������\�����\2 �������\laba\14 ���� ��� 2\14 ���� ��� 2\hash_table.t"
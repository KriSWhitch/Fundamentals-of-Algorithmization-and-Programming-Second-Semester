#include "hash_table.h"

Hash_Table::Hash_Table(int size) : size(size) {
	words = new WORD * [size];
	for (int i = 0; i < size; i++) {
		words[i] = NULL;
	}
}

int Hash_Table::hash(std::string str) {
	int hash = 0;
	for (char a : str)
		hash += (int)a;
	return hash % size;
}

bool Hash_Table::insert(std::string str, std::string descr) {
	int key = hash(str);

	WORD* tmp = new WORD();
	tmp->word = str;
	tmp->descript = descr;
	tmp->next = NULL;

	if (!words[key])
		words[key] = tmp;
	else {
		WORD* it = words[key];
		while (it->next && it->word != str)
			it = it->next;
		if (it->word == str) {
			it->descript = descr;
			return true;
		}
		it->next = tmp;
	}

	return true;
}

void Hash_Table::read_file(std::fstream* f) {
	std::string str;
	std::string descr;
	while (!(*f).eof()) {
		getline((*f), str, ' ');
		getline(*f, descr);
		insert(str, descr);
	}
}

void Hash_Table::print() const {
	for (int i = 0; i < size; i++) {
		if (words[i]) {
			WORD* tmp = words[i];
			while (tmp) {
				std::cout << tmp->word << '\n' << tmp->descript << '\n' << std::endl;
				tmp = tmp->next;
			}
		}
	}
}

bool Hash_Table::search(std::string str) {
	int hsh = hash(str);

	try {
		WORD* tmp = words[hsh];
		while (tmp && str != tmp->word)
			tmp = tmp->next;
		if (tmp) {
			std::cout << tmp->descript << '\n' << std::endl;
			return true;
		}
		else {
			std::cout << "Не найдено" << std::endl;
			return false;
		}
	}
	catch (int e) {
		std::cerr << "Exception #" << e << std::endl;
		return false;
	}
}
#include <string>
#include <iostream>
#include <fstream>

#include "hash_table.h"

using namespace std;

#define PATH "file.txt"

int main(int argc, char const* argv[])
{
	setlocale(LC_ALL, "Russian");
	fstream f;
	int choice;
	string word;
	string descr;
	Hash_Table table(100);

	do
	{
		cout << "1.Ввести цифру\n"
			<< "2.Вывести\n"
			<< "3.Прочитать файл\n"
			<< "4.Поиск\n"
			<< "0.Выход\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			cin >> word >> descr;
			table.insert(word, descr);
			break;
		case 2:
			table.print();
			break;
		case 3:
			(f).open(PATH, ios_base::in);
			table.read_file(&f);
			(f).close();
			break;
		case 4:
			cin >> word;
			table.search(word);
			break;
		default:
			cout << "Введите корректный вариант" << endl;
			break;
		}
	} while (choice);


	return 0;
}
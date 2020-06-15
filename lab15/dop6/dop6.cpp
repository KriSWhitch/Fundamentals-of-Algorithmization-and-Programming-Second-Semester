#include <iostream>
#include <fstream>
#include <string>

#include "hash_table.h"

#define PATH "text.txt"

using namespace std;

int main(int argc, char const* argv[])
{
	setlocale(LC_ALL, "Russian");
	int choice;
	char a;
	string str;
	fstream f;
	Hash_Table <string> table(27);

	do
	{
		cout << "1.Вывести\n"
			<< "2.Ввести слово\n"
			<< "3.Поиск\n"
			<< "4.Удалить по первой букве\n"
			<< "0.Выход\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			table.print();
			break;
		case 2:
			cin >> str;
			table.insert(str);
			break;
		case 3:
			cin >> str;
			table.search(str);
			break;
		case 4:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			a = getchar();
			table.del(a);
			break;
		default:
			cout << "Enter the correct word" << endl;
			break;
		}
	} while (choice);

	return 0;
}
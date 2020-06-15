#include <iostream>
#include "hash_table.h"

using namespace std;

int main(int argc, char const* argv[])
{
	setlocale(LC_ALL, "Russian");
	int choice;
	string str;
	char a;
	Hash_Table <string> stat(27);

	do
	{
		cout << "1.Ввести строку\n" <<
			"2.Вывести статистику\n" <<
			"3.Поиск\n" <<
			"0.Выход\n" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, str);
			if (!stat.processing(str))
				cerr << "Ваша строка не была обработана" << endl;
			break;
		case 2:
			stat.print();
			break;
		case 3:
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			a = getchar();
			stat.search(a);
			break;
		default:
			cout << "Введите корректный вариант" << endl;
			break;
		}
	} while (choice);
	system("pause");
	return 0;
}

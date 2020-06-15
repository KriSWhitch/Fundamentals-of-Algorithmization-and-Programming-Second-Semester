/*В текстовом файле содержатся целые числа. Построить хеш-таблицу из чисел файла. 
Осуществить поиск введенного це-лого числа в хеш-таблице. Сравнить результаты количества сравнений при различном наборе данных в файле.*/

#include <iostream>
#include <fstream>
#include <chrono>
#include "Hash.h"

int main()
{

	std::ifstream fin("E:\\Университет\\ОАиП\\lab32\\доп(3)\\numbers.txt");
	HashSet* hash = new HashSet(20);

	while (true)
	{
		int number;
		fin >> number;

		if (fin.eof() == true)
			break;

		hash->AddData(number, "");
	}
	hash->Print();

	int number;
	std::cout << std::endl;
	std::cout << "\tFind number: ";
	std::cin >> number;

	if (hash->FindData(number) != nullptr) {
		std::cout << "\tthis number was found" << std::endl;
	}
	else {
		std::cout << "\tthis number was't found" << std::endl;
	}


	fin.close();

	return 0;
}

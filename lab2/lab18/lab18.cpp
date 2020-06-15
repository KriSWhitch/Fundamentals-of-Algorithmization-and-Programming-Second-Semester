#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <Windows.h>
#include <iterator>
#include <unordered_set>
#include <algorithm>
#define  BUFSIZE   512
#define  BUFWORD   64
using namespace std;


/*Скопировать из файла FILE1 в файл FILE2 все строки, в которых содержится не менее двух одинаковых слов.
Определить слово, в котором больше всего цифр.*/


int first()
{	//копирование из файла F1 в файл F2 строк, которые содержат не менее двух одинаковых слов
	ifstream is("f1_first.txt"); // открываем файл f1_first.txt для чтения
	ofstream os("f2_first.txt"); // открываем файл f2_first.txt для записи
	if (!is || !os) return 1; //если не удалось открыть файл - возвращаем значение 1
	string str, word;
	unordered_set<string> uset; // используем ассоциативный контейнер для хранения слова и поиска его пары
	while (getline(is, str)) { //считываем строки из объекта is
		uset.clear(); // очищаем контейнер содержащий слово
		stringstream ss(str); // считываем слова из сстроки

		while (ss >> word) { // передаём слово из строки в переменную
			if (!uset.insert(word).second) { // если вставленное слово совпадает с каким-либо другим
				os << str << '\n'; // переписываем строку во второй файл
				break;
			}
		}
	}
	is.close();
	os.close();
	//Определяем номер слова, в котором больше всего цифр
	ifstream isss("f1_first.txt"); // открываем объект isss для чтения
	string str1;
	while (getline(isss, str1)) { //считываем по очереди все строки из файла
		string s, word, mostDig, mostLet;
		int i, count_letters, count_digits, max_letters = 0, max_digits = 0;
		while (isss >> word) { //передаём слова из строки в переменную word
			i = 0;
			count_letters = 0;
			count_digits = 0;
			while (word[i])
			{
				if (word[i] >= '0' && word[i] <= '9') count_digits++; //если в слове содержится символ цифры, то увеличиваем значение счётчика на 1 за каждый такой символ
				if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) count_letters++; /*если в слове содержится символ латинского алфавита,
				                                                                                              то увеличиваем значение счётчика на 1 за каждый такой символ*/
				i++;
			}
			if (count_digits > max_digits) { max_digits = count_digits; mostDig = word; } /*если в текущем слове больше цифр, чем в слове с максимально большим кол-ом цифр до этого,
			                                                                              то мы заменяем слово в переменной на текущее*/

			if (count_letters > max_letters) { max_letters = count_letters; mostLet = word; }/*если в текущем слове больше букв, чем в слове с максимально большим кол-ом букв до этого,
			                                                                              то мы заменяем слово в переменной на текущее*/
		}
		cout << "Word with max digits: " << mostDig; // выводим слово с наибольшим количеством цифр
	}
	return 0;
}

/*Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл. 
Прочитать из файла данные и вывести все слова, которые содержат букву «х».*/

void second() {
	FILE* F1;
	int i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_second.txt", "w");
	fflush(stdin);
	printf("введите строку: \n");
	gets_s(str);
	fputs(str, F1);
	fputs("\n", F1);
	fclose(F1);
	err = fopen_s(&F1, "f1_second.txt", "r");
	char c = 'x';
	char S[255];
	fgets(S, 255, F1);
	istringstream ist(S);
	string tmp;
	while (ist >> tmp) {
		i = 0;
		while (tmp[i]) {
			if (tmp[i] == c) {
				cout << tmp << endl;
				break;
			}
			i++;
		}

	}
}


/*Скопировать из файла F1 в файл F2 все строки, в которых есть слова, совпадающие со первым словом.
Определить количество цифр в последней строке  файла F2.*/

//done
int dop1()
{
	ifstream in("f1_dop1.txt");
	ofstream out("f2_dop1.txt");
	string line, firstWord, word;
	while (getline(in, line))
	{
		stringstream ss(line);
		bool hasEquals = false;
		ss >> firstWord;
		while (ss >> word)
		{
			if (word == firstWord)
			{
				hasEquals = true;
				break;
			}
		}
		if (hasEquals) out << line << endl;
	}
	string consonants("0123456789");
	int consCount = 0;
	for (auto it = line.begin(); it != line.end(); it++)
		if (consonants.find(*it) != string::npos)
			consCount++;
	cout << "Число цифр в последней строке: " << consCount;
	in.close();
	out.close();
	return 0;
}

/* Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами,
и записать ее в файл. Прочитать из файла данные и вывести четные числа строки.*/

//done
void dop2() {
	FILE* F1;
	FILE* F2;
	int i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_dop2.txt", "w");
	for (int i = 0; i < 8; i++)
	{
		fflush(stdin);
		printf("введите строку %d : \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	fclose(F1);
	err = fopen_s(&F1, "f1_dop2.txt", "r");
	err = fopen_s(&F2, "f2_dop2.txt", "w");

	for (int i = 0; i < 8 && fgets(str, 255, F1) != NULL; i++)
	{
		if (i % 2 == 1)
			fputs(str, F2);
	}
	fclose(F1);
	fclose(F2);
}


/*Скопировать в файл FILE2 только четные строки из FILE1. Подсчитать размер файлов FILE1 и FILE2 (в байтах).*/

//done
int dop3() {

	FILE* F1;
	FILE* F2;
	int i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_dop3.txt", "w");
	for (int i = 0; i < 8; i++)
	{
		fflush(stdin);
		printf("введите строку %d : \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	fclose(F1);
	err = fopen_s(&F1, "f1_dop3.txt", "r");
	err = fopen_s(&F2, "f2_dop3.txt", "w");

	for (int i = 0; i < 8 && fgets(str, 255, F1) != NULL; i++)
	{
		if (i % 2 == 1)
			fputs(str, F2);
	}

	fclose(F1);
	fclose(F2);

	for (i = 0; i<2 ; i++){
	char cname_file[80];
	FILE* sz;
	cout << "Введите название файла, чей размер вы хотите вывести на экран" << endl;
	cin >> cname_file;
	sz = fopen(cname_file, "rt+");
	long size;
	fseek(sz, 0, SEEK_END);
	size = ftell(sz);
	fseek(sz, 0, SEEK_SET);
	fclose(sz);
	cout << "Размер файла " << cname_file << " = " <<  size << "байт" << endl;
	}
	return 0;
}



int main() {
	setlocale(LC_ALL, "Russian");
	//first();
	second();
	//dop1();
	//dop2();
	//dop3();
}
#include <fstream>
#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
# include <iostream> 
#include <string.h>
#include <stdlib.h>
using namespace std;



/*
В соответствии со своим вариантом разработать программу для данных, приведенных в таблице ниже.  
Определить структурированный тип, разработать меню для работы с массивом структур. 
В программу должны войти функции:
-	ввод элементов структуры с клавиатуры; 1
-	вывод элементов структуры в консольное окно; 1
-	удаление заданной структурированной переменной; 1
-	поиск информации; 1
-	запись информации в файл; 1
-	чтение данных из файла. 1
Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по фамилии.*/

# define tch 5

typedef struct teacher {
	char lastName[tch];
	char examName[5];
	char examDate[30*tch];
}teacher;

struct teacher Teacher[tch];
struct teacher bad;
int number, currentTeacher; 
int r;
FILE* f; 
errno_t err;
int tmp;

void enter_new() {
	cout << "Ввод информации" << endl;
	if (currentTeacher < tch) { 
		cout << "Запись номер " << currentTeacher + 1 << endl; 
		cout << "Фамилия " << endl; 
		cin >> Teacher[currentTeacher].lastName; 
		cout << "Название экзамена " << endl; 
		cin >> Teacher[currentTeacher].examName; 
		cout << "Введите дату экзамена для преподавателя " << Teacher[currentTeacher].lastName;
		cin >> Teacher[currentTeacher].examDate;
		currentTeacher++; }
	else
		cout << "Введено максимальное кол-во записей"; 
		cout << "Что дальше?" << endl; 
		cin >> r;
}

void del() { 
	int d; 
	cout << "\nНомер записи, которую надо удалить" << endl; 
	cout << "Если надо удалить все записи, нажмите '99'" << endl; 
	cin >> d; 
	if (d != 99) { 
		for (int de_1 = (d - 1); de_1 < 4; de_1++)
			Teacher[de_1] = Teacher[de_1 + 1]; 
		currentTeacher = currentTeacher - 1; } 
	if (d == 99) 
		for (int i = 0; i < tch; i++) 
			Teacher[i] = bad; 
	cout << "Что дальше?" << endl; 
	cin >> r; }

void out() { 
	int sw, o; 
	cout << endl << "Введите: " << endl; 
	cout << "1-вывод одной записи" << endl; 
	cout << "2-вывод всех записей" << endl; 
	cin >> sw; if (sw == 1) { 
		cout << "Введите номер записи, которую нужно вывести" << endl; 
		cin >> o; cout << endl; 
		cout << endl << "Фамилия: " ; 
		cout << Teacher[o - 1].lastName << endl; 
		cout << "Название экзамена: " ; 
		cout << Teacher[o - 1].examName << endl; 
		cout << "Дата экзамена: "; 
		cout << Teacher[o - 1].examDate << endl;} 

	if (sw == 2) { for (int i = 0; i < currentTeacher; i++) {
		cout << endl << "Фамилия "; 
		cout << Teacher[i].lastName << endl; 
		cout << "Название экзамена "; 
		cout << Teacher[i].examName << endl; 
		cout << "Дата экзамена "; 
		cout << Teacher[i].examDate << endl;} } 
	cout << "Что делать дальше?" << endl; 
	cin >> r; }

void input2(int size) {
	teacher buf = { ' ', ' ' }; 
	if (!fopen_s(&f, "base.bin", "ab")) {
		for (int p = 1; p <= size; p++) {
			cout << endl << "Фамилия " << endl; 
			cin >> buf.lastName; 
			cout << "Название экзамена " << endl; 
			cin >> buf.examName; 
			cout << "Дата экзамена " << endl;
			cin >> buf.examDate; 
			fwrite(&buf, sizeof(buf), 1, f);
		} fclose(f);
	}
	else { cout << "Ошибка открытия файла"; return; }
}

void find(char lastName[25]) {
	bool flag = false; 
	teacher buf; 
	if (!fopen_s(&f, "base.bin", "rb")) {
		while (!feof(f)) {
			fread(&buf, sizeof(buf), 1, f); if (strcmp(lastName, buf.lastName) == 0) //сравнение строк
			{ 
			cout << "\nФамилия ";
			cout << buf.lastName << endl; 
			cout << "Название экзамена "; 
			cout << buf.examName << endl; 
			cout << "Дата экзамена "; 
			cout << buf.examDate << endl; 
			flag = true; 
			break; } } 
		fclose(f); 
		if (!flag) cout << "Ничего не найдено\n";} 
	else { cout << "Ошибка открытия файла"; 
	return; } }

int first() {
	char fio[25];
	int number2; 
	cout << "Записей пока нет" << endl; 
	cout << "Введите:" << endl; 
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl; 
	cout << "3-для вывода записи(ей)" << endl; 
	cout << "4-для поиска по фамилии" << endl; 
	cout << "5-для ввода записи(ей) в файл" << endl; 
	cout << "6-для выхода" << endl; 
	cin >> r; 
	do { switch (r) { 
	case 1: del(); 
	break; 
	case 2: enter_new(); 
	break; 
	case 3: out(); 
	break; 
	case 4: {
	cout << "Введите фамилию: "; 
	cin >> fio; 
	find(fio); 
	break; } 
	case 5: {
		cout << "Введите количество преподавателей: "; 
		cin >> number2; 
		input2(number2);
		break; }

	} } 
	while (r != 6);
		return 0;
}
	

/*Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: ФИО студен-та, число экзаменов, полученные оценки.
Определить функции для обработки отдельного объекта (например, для проверки, сданы ли все экзамены на 4 и 5). Написать функцию для обработки массива структур.
В результате обработки требуется вычислить характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах. */

struct Spisok
{
	char Fam[4];
	int Exam[5];
	int Ball[5];
};


int dop1() {
	const int n = 4;
	Spisok stud[4]; // sozdaem massiv strok
	int mas[n] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cout << "Введите фамилию: \n";
		cout << "\n";
		cin >> stud[i].Fam;
		cout << "Введите балл по предметам: \n";
		cout << "\n";
		cout << "математика | физика | информатика | этика | психология \n";

		for (int j = 0; j < 5; j++)
		{
			cout << "\n";
			cin >> stud[i].Ball[j];
		}
	}

	char namePredmets[5][32];
	strcpy_s(namePredmets[0], "математика");//Присваиваем namePredmets[0] строку "matematika"
	strcpy_s(namePredmets[1], "физика");
	strcpy_s(namePredmets[2], "информатика");
	strcpy_s(namePredmets[3], "этика");
	strcpy_s(namePredmets[4], "психология");
	for (int j = 0; j < 5; j++)//j - текущий предмет, всего 5 предметов
	{
		int badRes = 0, goodRes = 0;

		for (int i = 0; i < n; i++)//i - текущий студент, n - всего студентов
		{
			if ((stud[i].Ball[j] == 4) || (stud[i].Ball[j] == 5))
			{
				goodRes++;
			}
			else
			{
				badRes++;
			}
		}

		cout << namePredmets[j] << ": " << (goodRes * (100 / 4)) << endl;
	}
	return 0;
}

/*Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время отправления. 
Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN 
(записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); 
вывод на экран информации о поездах, отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).*/

typedef struct
{
	string station;
	int number;
	int time;
}   TRAIN, * PTRAIN;


int dop2() {
	vector<TRAIN> v;
	TRAIN t;

	// Ввод
	ifstream ifs("in.txt", ios::in);
	while (ifs)
	{
		ifs >> t.station;
		ifs >> t.number;
		ifs >> t.time;

		v.push_back(t);
	}
	ifs.close();

	string name;
	cout << "enter station: ";
	cin >> name;

	// Вывод
	bool c = false;
	for (int i = 0; i < v.size() - 1; ++i)
	{
		if (name == v[i].station)
		{
			cout << "---------------------------------------" << endl;
			cout << "STATION: " << v[i].station << endl;
			cout << "NUMBER: " << v[i].number << endl;
			cout << "TIME: " << v[i].time << endl;
			cout << "---------------------------------------" << endl;
			c = true;
		}
	}
	if (!c)
		cout << "not found!" << endl;
	return 0;
}

/*Описать структуру с именем MARSH, содержащую следующие поля: название начального пункта маршрута; название конечного пункта маршрута; номер маршрута.
Написать программу, выполняющую следующие действия: ввод с клавиатуры данных в массив, состоящий из восьми элементов типа MARSH; записи должны быть упорядочены по номерам маршрутов;
вывод на экран информации о маршрутах, которые начинаются или кон¬чаются в пункте, название которого введено с клавиатуры; если таких маршрутов нет,
выдать на дисплей соответствующее сообщение.
*/

struct marsh {
	char start[100];
	char end[100];
	unsigned int nuber;
};

void inputMarsh(marsh& a) {
	cout << "Введите начальный пункт: ";
	cin >> a.start;
	cout << "Введите конечный пункт: ";
	cin >> a.end;
	cout << "Введите номер маршрута: ";
	cin >> a.nuber;
}

void sort(marsh* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (a[j].nuber > a[j + 1].nuber)
				swap(a[j], a[j + 1]);
		}
	}
}

void outputMarsh(marsh& a) {
	cout << "Номер маршрута: " << a.nuber << endl;
	cout << "Начальный пункт: " << a.start << endl;
	cout << "Конечный пункт: " << a.end << endl;
	cout << endl << endl;
}

void searchInform(marsh* a, int n) {
	while (1) {
		char tmp[100];
		const char _exit[] = "-1\0";
		cout << "Для выхода из программы наберите -1" << endl << endl;
		cout << "Введите пункт, информация о котором вас интересует: ";
		cin >> tmp;
		bool _check = false;
		for (int i = 0; i < n; i++) {
			if (!strcmp(a[i].end, tmp) || !strcmp(a[i].start, tmp)) {
				outputMarsh(a[i]);
				_check = true;
			}
		}
		if (!strcmp(tmp, _exit))
			exit(1);
		if (!_check) {
			cout << "Ничего не найдено" << endl;
		}
	}
}

int dop3() {
	static const char n = 8; //кол-во элементов массива

	marsh marsh_array[n];

	for (int i = 0; i < n; i++)
		inputMarsh(marsh_array[i]);

	sort(marsh_array, n);
	searchInform(marsh_array, n);

	return 0;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	dop3();
}

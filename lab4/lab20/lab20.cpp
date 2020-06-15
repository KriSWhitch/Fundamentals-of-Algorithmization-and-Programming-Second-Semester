#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;



/*Горожанин. Ф.И.О., дата рождения, адрес, пол (м, ж). Выборка по году рождения. Дату рождения организовать с помощью битового поля, пол с помощью перечисления.*/

int x = 0;
enum EGender {
	m = 1, w
} gender;
struct citizen {
	char name[15];
	char last_name[15];
	char location[20];
	int gend;
};
struct datasha {
	unsigned short Day : 5;
	unsigned short month : 4;
	unsigned short year : 11;
};
struct datasha datata[5];
struct citizen list_of_citizen[5];
void input() {
	int z; 
	char ehelp; 
	cout << "\nВведите имя \n"; 
	cin >> list_of_citizen[x].name; 
	cout << "\nВведите фамилию \n"; 
	cin >> list_of_citizen[x].last_name; 
	cout << "\nВведите адрес\n"; 
	cin >> list_of_citizen[x].location; 
	cout << "\nПол:\n"; 
	cin >> ehelp; 
	if (ehelp == 'm') {
		list_of_citizen[x].gend = m; 
	} 
	if (ehelp == 'w') {
		list_of_citizen[x].gend = w; 
	} 
	cout << "\nДата рождения:\n"; 
	cout << "Год рождения: "; 
	cin >> z; 
	datata[x].year = z;
	cout << "\nМесяц: "; 
	cin >> z;
	datata[x].month = z; 
	cout << "\nДень: "; 
	cin >> z;
	datata[x].Day = z; x++; 
} 
void output() {
	cout << setw(15) << left << "Фамилия"; 
	cout << setw(15) << left << "Имя"; 
	cout << setw(20) << left << "Адрес"; 
	cout << setw(4) << right << "Пол "; 
	cout << setw(5) << left << "Год"; 
	cout << setw(6) << left << "Месяц"; 
	cout << setw(6) << left << "День"; 
	for (int k = 0; k < x; k++){
		cout << endl << setw(15) << left << list_of_citizen[k].last_name; 
		cout << setw(15) << left << list_of_citizen[k].name; 
		cout << setw(20) << left << list_of_citizen[k].location; 
		cout << setw(4) << left << list_of_citizen[k].gend; 
		cout << setw(5) << left << datata[k].year; 
		cout << setw(6) << left << datata[k].month;
		cout << setw(6) << left << datata[k].Day;
	}
} void searchgend() { 
	char q; 
	cout << "Пол(m/w): "; 
	cin >> q; 
	if (q == 'm') {
		gender = m; 
	} 
	if (q == 'w') {
		gender = w; 
	} 
	cout << setw(15) << left << "Фамилия"; 
	cout << setw(15) << left << "Имя"; 
	cout << setw(20) << left << "Адрес";
	cout << setw(4) << right << "Пол "; 
	cout << setw(5) << left << "Год"; 
	cout << setw(6) << left << "Месяц"; 
	cout << setw(6) << left << "День"; 
	for (int k = 0; k < x; k++) { 
		if (list_of_citizen[k].gend == gender) {
			cout << endl << setw(15) << left << list_of_citizen[k].last_name; 
			cout << setw(15) << left << list_of_citizen[k].name; 
			cout << setw(20) << left << list_of_citizen[k].location; 
			cout << setw(4) << left << list_of_citizen[k].gend; 
			cout << setw(5) << left << datata[k].year;
			cout << setw(6) << left << datata[k].month; 
			cout << setw(6) << left << datata[k].Day; 
		} 
	} 
} 
void searchdate() {
	int dadaya, counter = 0;
	cout << "\nВведите день: "; 
	cin >> dadaya; 
	for (int o = 0; o < x; o++) {
		if (datata[o].Day == dadaya) {
			cout << "\nВведите месяц: ";
			cin >> dadaya;
			if (datata[o].month == dadaya) {
				cout << "\nВведите год: ";
				cin >> dadaya;
				if (datata[o].year == dadaya) {
					cout << setw(15) << left << "Фамилия";
					cout << setw(15) << left << "Имя";
					cout << setw(20) << left << "Адрес";
					cout << setw(4) << right << "Пол ";
					cout << setw(5) << left << "Год";
					cout << setw(6) << left << "Месяц";
					cout << setw(6) << left << "День";
					cout << endl << setw(15) << left << list_of_citizen[o].last_name;
					cout << setw(15) << left << list_of_citizen[o].name;
					cout << setw(20) << left << list_of_citizen[o].location;
					cout << setw(4) << left << list_of_citizen[o].gend;
					cout << setw(5) << left << datata[o].year;
					cout << setw(6) << left << datata[o].month;
					cout << setw(6) << left << datata[o].Day; 
					counter++;
				}
			}
		}
	} if (counter == 0) { 
		cout << "Совпадений нет";
	}
}

int dop3() {

 int select;
 cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по полу\n" << "4-Поиск по дате\n" << "5-Выход\n\n";
 cin >> select;
 while (select != 5) {
	 switch (select) {
		case 1:input();
		break;
		case 2:output();
		break;
		case 3:searchgend();
		break;
		case 4:searchdate(); 
		break; 
		default:break; 
 } 
 cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по полу\n" << "4-Поиск по дате\n" << "5-Выход\n\n"; 
 cin >> select;
 } system("pause"); 
 return 0; 
}

/*Справочник абитуриента. Наименование вуза, адрес, перечень специальностей, конкурс прошлого года по каждой специальности, размер оплаты при договорном обучении.
Выбор по минимальному конкурсу. Перечень специальностей через перечисления.*/


struct university {
	char universityName[15];
	char address[30];
	int numberOfSpecialities;
	
};

struct speciality {
	char specName[20];
	int passingScore;
	int costOfStudying;
};


int const numberOfUniversities = 1;

struct university list_of_universities[numberOfUniversities];
struct speciality list_of_specialities[5];
int numberOfSpecialities;
int i = 0, j = 0;
void inputUniversities() {
	char ehelp;
	cout << "\nВведите название университета \n";
	cin >> list_of_universities[i].universityName;
	cout << "\nВведите адрес университета \n";
	cin >> list_of_universities[i].address;
	cout << "\nВведите количество специальностей в университете \n";
	cin >> list_of_universities[i].numberOfSpecialities;
	for (int j = 0; j < list_of_universities[i].numberOfSpecialities; j++)
	{
		cout << "\nВведите название специальности\n";
		cin >> list_of_specialities[j].specName;
		cout << "\nВведите проходной балл:\n";
		cin >> list_of_specialities[j].passingScore;
		cout << "\nВведите стоимость обучения:\n";
		cin >> list_of_specialities[j].costOfStudying;
		
	}
	i++;
	
}
void outputUniversities() {
	cout << setw(15) << left << "Название университета";
	cout << setw(20) << left << "Адрес университета";
	cout << setw(4) << right << "Количество специальностей в университете ";

	for (int k = 0; k < i; k++) {
		cout << endl << setw(20) << left << list_of_universities[k].universityName;
		cout << setw(35) << left << list_of_universities[k].address;
		cout << setw(10) << left << list_of_universities[k].numberOfSpecialities;
		for (int g = 0; g < list_of_universities[k].numberOfSpecialities; g++)
		{
			cout << setw(5) << left << "\nНазвание специальности: " ;
			cout << setw(5) << left << list_of_specialities[g].specName;
			cout << setw(6) << left << "\nПроходной балл в прошлом году: " ;
			cout << setw(6) << left << list_of_specialities[g].passingScore;
			cout << setw(6) << left << "\nСтоимость обучения: " ;
			cout << setw(6) << left << list_of_specialities[g].costOfStudying;
		}
	}

}
void searchscore() {

	int q;
	cout << "Поиск по минимальному проходному баллу: " << endl;
	cout << "Введите минимальный балл, от которого будет начинаться поиск:";
	cin >> q;
	for (int k = 0; k < i; k++) {
		for (int g = 0; g < list_of_universities[k].numberOfSpecialities; g++)
			if (list_of_specialities[g].passingScore >= q)
			{
				cout << setw(5) << left << "\nНазвание специальности: " ;
				cout << setw(5) << left << list_of_specialities[g].specName;
				cout << setw(6) << left << "\nПроходной балл в прошлом году: " ;
				cout << setw(6) << left << list_of_specialities[g].passingScore;
				cout << setw(6) << left << "\nСтоимость обучения: " ;
				cout << setw(6) << left << list_of_specialities[g].costOfStudying;
			}
		
	}
}




int first() {
	int select;
	cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по минимальному баллу\n" << "4-Выход\n\n";
	cin >> select;
	while (select != 4) {
		switch (select) {
		case 1:inputUniversities();
			break;
		case 2:outputUniversities();
			break;
		case 3:searchscore();
			break;
		default:break;
		}
		cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по минимальному баллу\n" << "4-Выход\n\n";
		cin >> select;
	} system("pause");
	return 0;
}

/*Справочник абитуриента. Наименование вуза, адрес, перечень специальностей, конкурс прошлого года по каждой специальности, размер оплаты при договорном обучении.
Поиск минимального конкурса по данной специальности.*/

int second() {
	int select;
	cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по минимальному баллу\n" << "4-Выход\n\n";
	cin >> select;
	while (select != 4) {
		switch (select) {
		case 1:inputUniversities();
			break;
		case 2:outputUniversities();
			break;
		case 3:searchscore();
			break;
		default:break;
		}
		cout << "\nМеню\n" << "1-Ввод данных\n" << "2-Вывод данных\n" << "3-Выборка по минимальному баллу\n" << "4-Выход\n\n";
		cin >> select;
	} system("pause");
	return 0;
}

/*Преподаватели. Фамилия преподавателя, название экзамена, дата экзамена. Выбор по дате экзамена. Дату экзамена реализовать с помощью битового поля.*/
# define tch 5

typedef struct teacher {
	char lastName[tch];
	char examName[5];
	char examDate[30 * tch];
}teacher;

struct teacher Teacher[tch];
struct teacher badd;
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
		currentTeacher++;
	}
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
		currentTeacher = currentTeacher - 1;
	}
	if (d == 99)
		for (int i = 0; i < tch; i++)
			Teacher[i] = badd;
	cout << "Что дальше?" << endl;
	cin >> r;
}

void out() {
	int sw, o;
	cout << endl << "Введите: " << endl;
	cout << "1-вывод одной записи" << endl;
	cout << "2-вывод всех записей" << endl;
	cin >> sw; if (sw == 1) {
		cout << "Введите номер записи, которую нужно вывести" << endl;
		cin >> o; cout << endl;
		cout << endl << "Фамилия: ";
		cout << Teacher[o - 1].lastName << endl;
		cout << "Название экзамена: ";
		cout << Teacher[o - 1].examName << endl;
		cout << "Дата экзамена: ";
		cout << Teacher[o - 1].examDate << endl;
	}

	if (sw == 2) {
		for (int i = 0; i < currentTeacher; i++) {
			cout << endl << "Фамилия ";
			cout << Teacher[i].lastName << endl;
			cout << "Название экзамена ";
			cout << Teacher[i].examName << endl;
			cout << "Дата экзамена ";
			cout << Teacher[i].examDate << endl;
		}
	}
	cout << "Что делать дальше?" << endl;
	cin >> r;
}

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
				break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

int dop1() {
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

	do {
		cin >> r;
		switch (r) {
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

		}
	} while (r != 6);
	return 0;
}

/*Авиарейсы. Номер рейса, пункт назначения, время вылета, дата вылета, стоимость билета, количество мест. Выбор по пункту назначения. */



#define str_len 50
#define SIZE 10			//описание констант

using namespace std;

int choice;
int current_size = 0;

struct flights {		//описание структуры
	char number[str_len];
	char destination[str_len];
	char time[str_len];
	char data[SIZE];
	float cost;
	int kol_vo;
};

struct flights list_of_flights[50];		//создание объектов структуры
struct flights bad;


void navigation();		//прототипы структуры
void enter_neww();
void dell();
void show();
void change();
void navigation();
void print();
void fenter();

int dop2() {
	cout << "Данных нет" << endl;
	navigation();		//вызов функции
	cin >> choice;

	do
	{
		switch (choice)
		{
		case 1:	system("cls");  dell();	break;		//выбор функции из меню
		case 2: system("cls");  enter_neww(); break;
		case 3:	system("cls");  change(); break;
		case 4:	system("cls");  show(); break;
		case 5: system("cls");  print(); break;
		case 6: system("cls");  fenter(); break;
		}
	} while (choice != 7);

	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	return 0;
}

void enter_neww()		//ввод данных в структуру и файл
{
	string path = "flights.txt";

	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open()) {
		cout << "error" << endl;
		exit(1);
	}
	else {
		cout << "Ввод информации" << endl;

		if (current_size < SIZE)
		{
			cout << "Строка номер ";
			cout << current_size + 1;

			cout << endl << "Номер рейса " << endl;
			cin >> list_of_flights[current_size].number;
			fs << '\n' << list_of_flights[current_size].number;

			cout << "Пункт назначения " << endl;
			cin >> list_of_flights[current_size].destination;
			fs << '\n' << list_of_flights[current_size].destination;

			cout << "Время вылета " << endl;
			cin >> list_of_flights[current_size].time;
			fs << '\n' << list_of_flights[current_size].time;

			cout << "Дата вылета " << endl;
			cin >> list_of_flights[current_size].data;
			fs << '\n' << list_of_flights[current_size].data;

			cout << "Стоимотсь билета " << endl;
			cin >> list_of_flights[current_size].cost;
			fs << '\n' << list_of_flights[current_size].cost;

			cout << "Количество мест" << endl;
			cin >> list_of_flights[current_size].kol_vo;
			fs << '\n' << list_of_flights[current_size].kol_vo;

			current_size++;
		}
		else
			cout << "Введено максимальное кол-во строк";

		cout << "Что дальше?" << endl;

		navigation();

		cin >> choice;
	}
	fs.close();
}

void fenter() {				//ввод данных в структуру из файла
	string path = "flights.txt";

	fstream fs;
	fs.open(path, fstream::in);
	if (!fs.is_open()) {
		cout << "error" << endl;
	}
	else {

		int i = 1;

		while (true) {
			switch (i) {
			case 1:
				fs >> list_of_flights[current_size].number;
				break;
			case 2:
				fs >> list_of_flights[current_size].destination;
				break;
			case 3:
				fs >> list_of_flights[current_size].time;
				break;
			case 4:
				fs >> list_of_flights[current_size].data;
				break;
			case 5:
				fs >> list_of_flights[current_size].cost;
				break;
			case 6:
				fs >> list_of_flights[current_size].kol_vo;
				current_size++;
				i = 0;
				break;
			}
			i++;
			if (fs.eof()) {
				break;
			}
		}

		cout << "Данные с файла успешно считаны и занесены в базу данных!" << endl;
	}
	fs.close();


	cout << "Что дальше?" << endl;

	navigation();

	cin >> choice;
}

void dell()			//удаление данных структуры
{
	int d;

	if (current_size != 0) {
		cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;

		cin >> d;

		if (d != 99)
		{
			for (int de1 = (d - 1); de1 < current_size; de1++)
				list_of_flights[de1] = list_of_flights[de1 + 1];
			current_size = current_size - 1;
		}

		if (d == 99) {
			for (int i = 0; i < SIZE; i++)
				list_of_flights[i] = bad;
			current_size = 0;
		}

	}
	else {
		cout << "База данных пуста" << endl;
	}
	cout << "Что дальше?" << endl;

	navigation();

	cin >> choice;
}

void show()		//вывод данных структуры
{
	if (current_size != 0) {
		int sw, n;

		cout << "1-вывод одной строки" << endl;
		cout << "2-вывод всех строк" << endl;

		cin >> sw;

		if (sw == 1)
		{
			cout << "Номер выводимой строки " << endl;
			cin >> n; cout << endl;

			cout << "Номер рейса\t\t";
			cout << list_of_flights[n - 1].number << endl;

			cout << "Пункт назначения\t";
			cout << list_of_flights[n - 1].destination << endl;

			cout << "Время вылета\t\t";
			cout << list_of_flights[n - 1].time << endl;

			cout << "Дата вылета\t\t";
			cout << list_of_flights[n - 1].data << endl;

			cout << "Стоимотсь билета\t";
			cout << list_of_flights[n - 1].cost << endl;

			cout << "Количество мест\t\t";
			cout << list_of_flights[n - 1].kol_vo << endl;
		}

		if (sw == 2)
		{
			for (int i = 0; i < current_size; i++)
			{
				cout << "Номер рейса\t\t";
				cout << list_of_flights[i].number << endl;

				cout << "Пункт назначения\t";
				cout << list_of_flights[i].destination << endl;

				cout << "Время вылета\t\t";
				cout << list_of_flights[i].time << endl;

				cout << "Дата вылета\t\t";
				cout << list_of_flights[i].data << endl;

				cout << "Стоимотсь билета\t";
				cout << list_of_flights[i].cost << endl;

				cout << "Количество мест\t\t";
				cout << list_of_flights[i].kol_vo << endl;

				cout << "\t------------------------" << endl;
			}
		}

	}
	else {
		cout << "База данных пуста" << endl;
	}

	cout << "Что дальше?" << endl;

	navigation();

	cin >> choice;
}

void change()	//изменение данных структуры
{
	int n, per;

	if (current_size != 0) {
		cout << "\nВведите номер строки " << endl;
		cin >> n;

		do
		{
			cout << "Введите : " << endl;
			cout << "1 - для изменения номера рейса" << endl;
			cout << "2 - для изменения пункта назначения" << endl;
			cout << "3 - для изменения времени вылета" << endl;
			cout << "4 - для изменения даты вылета" << endl;
			cout << "5 - для изменения стоимости билета" << endl;
			cout << "6 - для изменения количества мест" << endl;
			cout << "7 - для изменения всех данных";
			cout << "8 - конец\n";

			cin >> per;

			switch (per)
			{

			case 1: cout << "новый номер рейса : ";
				cin >> list_of_flights[n - 1].number;
				break;

			case 2: cout << "Новый пункт назначения : ";
				cin >> list_of_flights[n - 1].destination;
				break;

			case 3: cout << "Новое время вылета : ";
				cin >> list_of_flights[n - 1].time;
				break;

			case 4: cout << "новая дата вылета : ";
				cin >> list_of_flights[n - 1].data;
				break;

			case 5:cout << "новая стоимость билета : ";
				cin >> list_of_flights[n - 1].cost;
				break;

			case 6:cout << "новое количество мест : ";
				cin >> list_of_flights[n - 1].kol_vo;
				break;

			case 7:
				cout << "новый номер рейса : ";
				cin >> list_of_flights[n - 1].number;
				cout << "Новый пункт назначения : ";
				cin >> list_of_flights[n - 1].destination;
				cout << "Новое время вылета : ";
				cin >> list_of_flights[n - 1].time;
				cout << "новая дата вылета : ";
				cin >> list_of_flights[n - 1].data;
				cout << "новая стоимость билета : ";
				cin >> list_of_flights[n - 1].cost;
				cout << "новое количество мест : ";
				cin >> list_of_flights[n - 1].kol_vo;
				break;
			}
		} while (per != 8);

	}
	else {
		cout << "База данных пуста" << endl;
	}
	cout << "Что дальше?" << endl;

	navigation();

	cin >> choice;
}

void navigation() {		//меню
	cout << "Введите:" << endl;
	cout << "1-для удаления записи(ей)" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для изменения записи(ей)" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "5-для вывода по дате вылета/пункту назначения" << endl;
	cout << "6-для ввода данных из файла" << endl;
	cout << "7-для выхода" << endl;
}

void print() {		//поиск по пункту назначения и дате вылета

	if (current_size != 0) {
		int  rt, i;
		char p_destination[50], p_data[10];
		cout << "1 - пункт назначения" << endl;
		cout << "2 - дата вылета" << endl;
		cin >> rt;
		if (rt == 1) {
			cout << "введите пункт назначения" << endl;
			cin >> p_destination;
			for (i = 0; i < current_size; i++) {
				if (_stricmp(p_destination, list_of_flights[i].destination) == 0)
				{
					cout << "Номер рейса\t\t";
					cout << list_of_flights[i].number << endl;

					cout << "Пункт назначения\t";
					cout << list_of_flights[i].destination << endl;

					cout << "Время вылета\t\t";
					cout << list_of_flights[i].time << endl;

					cout << "Дата вылета\t\t";
					cout << list_of_flights[i].data << endl;

					cout << "Стоимотсь билета\t";
					cout << list_of_flights[i].cost << endl;

					cout << "Количество мест\t\t";
					cout << list_of_flights[i].kol_vo << endl;

					cout << "\t-------------------" << endl;
				}

			}
		}

		if (rt == 2)
		{
			cout << "Введите дату" << endl;
			cin >> p_data;
			for (i = 0; i < current_size; i++) {
				if (_stricmp(p_data, list_of_flights[i].data) == 0)
				{
					cout << "Номер рейса\t\t";
					cout << list_of_flights[i].number << endl;

					cout << "Пункт назначения\t";
					cout << list_of_flights[i].destination << endl;

					cout << "Время вылета\t\t";
					cout << list_of_flights[i].time << endl;

					cout << "Дата вылета\t\t";
					cout << list_of_flights[i].data << endl;

					cout << "Стоимотсь билета\t";
					cout << list_of_flights[i].cost << endl;

					cout << "Количество мест\t\t";
					cout << list_of_flights[i].kol_vo << endl;

					cout << "\t------------------------" << endl;
				}
			}
		}
	}
	else {
		cout << "База данных пуста" << endl;
	}
	cout << "Что дальше?" << endl;

	navigation();

	cin >> choice;
}


int main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	dop3();
	return 0;
}


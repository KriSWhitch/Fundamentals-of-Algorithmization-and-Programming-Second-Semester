/*Создать список, содержащий элементы целого типа. Найти сумму положительных элементов или выдать сообщение, что положительных элементов нет. */

#include <iostream>
#include <fstream>

struct list
{
	int symbol;
	list* next;
};

//----------------------------- Прототипы функций -----------------------------
void insert(list*& p, int value); //Добавление числа в начало списка
void printList(list* p); //Вывод списка 
void toFile(list*& p); //Запись в файл
void fromFile(list*& p);  //Считывание из файла
void menu(void); //Вывод меню
int SumPositiveElem(int our_number, list* p);
using namespace std;
//------------------- Основная программа -----------------------------
int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr; //Объявляем первый элемент списка
	int choice; int value;
	menu(); // Вывести меню 
	cout << " ? ";
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			//------------------------ Ввод символа -----------------------
		case 1:  	cout << "Введите число: ";
			cin >> value;
			insert(first, value);
			printList(first);
			break;
			//------------------------- Запись в файл -------------------
		case 2:    toFile(first);
			break;
			//-------------------- Считывание из файла --------------
		case 3:    fromFile(first);
			break;
			//-------------------- Сумма положительных элементов списка ---------------
		case 4:		SumPositiveElem(value, first);
			break;
			//----------------------- Защита от дурака -------------------
		default:   cout << "Неправильный выбор!" << endl;
			break;
		}
		cout << "Что дальше?\n";
		menu();
		cin >> choice;
	}
	return 0;
}
//------------------ Добавление символа в начало списка -----------------------
void insert(list*& p, int value)
{
	list* newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}
//------------------- Вывод списка ------------------------
void printList(list* p)
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}
//----------------- Запись в файл --------------------
void toFile(list*& p)// Работаем с нашим списком, поэтому используем ссылку на него 
{
	list* temp = p;// Раабочий указатель
	list buf;// Буфер для записи в файл
	ofstream frm("mList.dat");
	if (frm.fail()) // Если произошла непредвиденная ошибка
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;// Перемещаемся на следующее звено
	}
	frm.close();
	cout << "=== Список записан в файл mList.dat! ===\n";
}
//----------------- Считывание из файла ----------------
void fromFile(list*& p)// Работаем с нашим списком, поэтому используем ссылку на него 
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.symbol);
		cout << "-->" << buf.symbol;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\n=== Список считан из файла mList.dat! ===\n";
}
//--------------------- Вывод меню --------------------------- 
void menu(void)
{
	cout << "Сделайте выбор:" << endl;
	cout << " 1 - Ввод числа(целого)" << endl;
	cout << " 2 - Запись списка в файл" << endl;
	cout << " 3 - Чтение списка из файла" << endl;
	cout << " 4 - Сумма положительных элементов списка" << endl;
	cout << " 5 - Выход" << endl;
}
//------------------------ Нахождение суммы положительных элементов списка -----------------
int SumPositiveElem(int our_number, list* p)
{
	int sum = 0;
	for (p; p != NULL; p = p->next)
	{
		our_number = p->symbol;
		if (our_number > 0)
		{
			cout << "Наше положительное число: " << our_number << endl;
			sum = sum + our_number;
		}
	}
	if (sum == 0)
	{
		cout << "Положительных элементов нет\n";
	}
	cout << "Сумма положительных элементов: " << sum << endl;
	return sum;
}
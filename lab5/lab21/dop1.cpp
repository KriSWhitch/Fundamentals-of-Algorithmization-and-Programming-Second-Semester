///*Создать список, содержащий символы. Найти символ, равный введенному с клавиатуры, вывести его и следующий за ним символ. */
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//
//struct list
//{
//	char symbol;
//	list* next;
//};
//
////----------------------------- Прототипы функций -----------------------------
//
//void insert(list*& p, char value);	//Добавление символа в начало списка
//void printList(list* p);	//Вывод списка 
//void toFile(list*& p);		//Запись в файл
//void fromFile(list*& p);	//Считывание из файла
//void menu(void);			//Вывод меню
//void findSymbolAndShowNext(char our_symbol, list* p);
//
//
////------------------- Основная программа -----------------------------
//int main()
//{
//
//	setlocale(LC_ALL, "Russian");
//	list* first = nullptr;
//	int choice; char value;
//	menu(); // Вывести меню 
//	cout << " ? ";
//	cin >> choice;
//	while (choice != 5)
//	{
//		switch (choice)
//		{
//			//------------------------ Ввод символа -----------------------
//		case 1:  	cout << "Введите символ ";
//			cin >> value;
//			insert(first, value);
//			printList(first);
//			break;
//
//			//------------------------- Запись в файл -------------------
//		case 2:    toFile(first);
//			break;
//
//			//-------------------- Считывание из файла --------------
//		case 3:    fromFile(first);
//			break;
//
//			//-------------------- Найти символ, равный введенному с клавиатуры, вывести его и следующий за ним символ ---------------
//		case 4:		findSymbolAndShowNext(value, first);
//			break;
//
//			//----------------------- Защита от дурака -------------------
//		default:   cout << "Неправильный выбор!" << endl;
//			break;
//		}
//		cout << "Что дальше?\n";
//		menu();
//		cin >> choice;
//	}
//	return 0;
//}
//
//
////------------------ Добавление символа в начало списка -----------------------
//void insert(list*& p, char value)
//{
//	list* newP = new list;
//	if (newP != NULL)     //есть ли место?  
//	{
//		newP->symbol = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "Операция добавления не выполнена" << endl;
//}
//
//
////------------------- Вывод списка ------------------------
//void printList(list* p)
//{
//	if (p == NULL)
//		cout << "Список пуст" << endl;
//	else
//	{
//		cout << "Список:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->symbol;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
//
////----------------- Запись в файл --------------------
//void toFile(list*& p)
//{
//	list* temp = p;
//	list buf;
//	ofstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	while (temp)
//	{
//		buf = *temp;
//		frm.write((char*)&buf, sizeof(list));
//		temp = temp->next;
//	}
//	frm.close();
//	cout << "Список записан в файл mList.dat\n";
//}
//
//
////----------------- Считывание из файла ----------------
//void fromFile(list*& p)
//{
//	list buf, * first = nullptr;
//	ifstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n Ошибка открытия файла";
//		exit(1);
//	}
//	frm.read((char*)&buf, sizeof(list));
//	while (!frm.eof())
//	{
//		insert(first, buf.symbol);
//		cout << "-->" << buf.symbol;
//		frm.read((char*)&buf, sizeof(list));
//	}
//	cout << "-->NULL" << endl;
//	frm.close();
//	p = first;
//	cout << "\nСписок считан из файла mList.dat\n";
//}
//
//
////--------------------- Вывод меню --------------------------- 
//void menu(void)
//{
//	cout << "Сделайте выбор:" << endl;
//	cout << " 1 - Ввод символа" << endl;
//	cout << " 2 - Запись списка в файл" << endl;
//	cout << " 3 - Чтение списка из файла" << endl;
//	cout << " 4 - Поиск символа и вывод следующего за ним символа" << endl;
//	cout << " 5 - Выход" << endl;
//}
//
//
////------------------------ Поиск символа и вывод следующего за ним символа -----------------
//void findSymbolAndShowNext(char our_symbol, list* p)
//{
//	cout << "Введите искомый символ: "; cin >> our_symbol;
//	while (p != NULL)
//	{
//		if (our_symbol == p->symbol)
//		{
//			cout << "Адресс следующего звена: " << p->next << endl;
//			cout << "Символ следующего звена: " << p->next->symbol << endl;
//		}
//		p = p->next;
//	}
//}
//
//

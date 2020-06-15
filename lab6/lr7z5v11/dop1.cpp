////Разработать функцию, которая удаляет из стека первый элемент, значение  которого превышает число 100, если такой элемент есть.
// 
//#include <iostream>
//using namespace std;
//struct Stack
//{
//	int data;             //информационный элемент
//	Stack* head;		 //вершина стека 
//	Stack* next;		 //указатель на следующий элемент
//};
//struct Stack1
//{
//	int data;             //информационный элемент
//	Stack1* head;		 //вершина стека 
//	Stack1* next;		 //указатель на следующий элемент
//};
////-----------------------------------------------------------
//void push(int x, Stack* myStk)   //Добавление элемента х в стек	
//{
//	Stack* e = new Stack;    //выделение памяти для нового элемента
//	e->data = x;             //запись элемента x в поле v 
//	e->next = myStk->head;   //перенос вершины на следующий элемент 
//	myStk->head = e;         //сдвиг вершины на позицию вперед
//}
////-----------------------------------------------------------
//
//
//void show(Stack* myStk)    //Вывод стека
//{
//	Stack* e = myStk->head;    //объявляется указатель на вершину стека
//	int a;
//	if (e == NULL)
//		cout << "Стек пуст!" << endl;
//	else {
//		cout << "Весь стек: " << endl;
//		while (e != NULL)
//		{
//			a = e->data;          //запись значения из поля v в переменную a 
//			cout << a << " ";
//			e = e->next;
//		}
//		cout << endl;
//	}
//}
////-----------------------------------------------------------
//int pop(Stack* myStk)   //Извлечение (удаление) элемента из стека
//{
//	if (myStk->head == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
//		int a = myStk->head->data;   //запись значения из поля v в переменную a 
//		myStk->head = myStk->head->next; //перенос вершины
//		delete e;                        //удаление временной переменной
//		return a;                        //возврат значения удаляемого элемента
//	}
//}
////-----------------------------------------------------------
//void clear(Stack* myStk)
//{
//	myStk->head = NULL;
//	cout << "Стек очищен " << endl;
//}
//int pop(Stack* myStk);
////-----------------------------------------------------------
///*void repush(Stack *myStk, Stack1 *myStk1)
//{
//	Stack *e = myStk->head;
//	int a = myStk->head->data;
//	Stack1 *e1 = myStk1->head;
//	int a1 = myStk1->head->data;
//	do {
//		a = e->data;
//		a1 = a;
//		e = e->next;
//	} while (e != NULL && a < 100);
//}*/
////-----------------------------------------------------------
//int delete100(Stack* myStk)
//{
//	int b = 1;
//	if (myStk->head == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return -1;               //если стек пуст - возврат -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //е - переменная для хранения адреса элемента
//		int a = myStk->head->data;   //запись значения из поля v в переменную a 
//		while (e != NULL) {
//			a = e->data;          //запись значения из поля v в переменную a 
//			if (a > 100 && b == 1) {
//				b++;
//			}
//			else  cout << a << " ";
//			e = e->next;
//		}
//	}
//}
////-----------------------------------------------------------
//
//void main()
//{
//	setlocale(LC_ALL, "Rus");
//	int choice;
//	Stack* myStk = new Stack; //выделение памяти для стека
//	myStk->head = NULL;       //инициализация первого элемента	
//	for (;;)
//	{
//		cout << "\n\nРабота со стеком. Выберите команду:" << endl;
//		cout << "1 - Добавление элемента в стек" << endl;
//		cout << "2 - Извлечение элемента из стека" << endl;
//		cout << "3 - Вывод стека" << endl;
//		cout << "4 - Очистка стека" << endl;
//		cout << "5 - Удаление элемента > 100" << endl;
//		//cout << "6 - Подсчёт кол-ва одинаковых элементов" << endl;
//		cout << "7 - Выход" << endl;
//		cin >> choice;
//		system("cls");
//		switch (choice)
//		{
//		case 1: cout << "Введите элемент для вставки: " << endl;
//			cin >> choice;
//			push(choice, myStk);
//			system("cls");
//			break;
//		case 2: choice = pop(myStk);
//			if (choice != -1)
//				cout << "Извлеченный элемент: " << choice << endl;
//			system("cls");
//			break;
//		case 3: show(myStk);
//			break;
//		case 4: clear(myStk);
//			break;
//		case 5: delete100(myStk);
//			break;
//			//case 6: repush(myStk,myStk1);
//			//	break;
//		case 7: exit(0);
//			break;
//		}
//	}
//}

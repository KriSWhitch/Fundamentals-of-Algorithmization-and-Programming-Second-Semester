#include "MyStack.h"


int pop(stack* &st) // Извлечение элемента
{
	int tmp = st->data;
	stack *pv = st;
	st = st->next;       // вершиной становится предшествующий элемент
	delete pv;           // освобождается память 
	//cout << tmp << endl; //вывод текущего элемента 
	return tmp;
}

void push(stack* &st, int d) // Добавление элемента
{
	stack *pv = new stack;
	pv->data = d;   // значение помещается в стек     
	pv->next = st;
	st = pv;
}

void clear(stack* &st) 
{
	while (st != nullptr) 
	{
		pop(st);
	}
}

void deleteNeKrat3(stack *&st)
{
	stack *newStack = nullptr;

	while (st != nullptr) 
	{
		int tmp = pop(st);
		if (tmp % 3 != 0) 
		{
			push(newStack, tmp);
		}
	}
	st = newStack;
}

void writeStackToFile(string filename, stack*&st) 
{
	ofstream out(filename);
	stack * stackCopy = nullptr;
	while (st != nullptr) 
	{
		int tmp = pop(st);
		out << tmp << endl;
		push(stackCopy, tmp);
	}
	st = stackCopy;
	out.close();
}

void readStackFromFile(string filename, stack*&st) 
{
	ifstream in(filename);
	int tmp;
	while (in >> tmp) 
	{
		push(st, tmp);
	}
}

void switch_word()
{
	char str[20];
	cout << "Напишите слово: " << endl;
	gets_s(str, 100);
	while (strlen(str) % 2 != 0 || strlen(str) == 0)
	{
		str[0] = 0;
		
		gets_s(str, 100);
		cout << endl << endl;
	}

	StackEl *stack_1 = new StackEl;
	StackEl *stack_2 = new StackEl;
	stack_1->head = NULL;
	stack_2->head = NULL;

	for (int i = 0; i < (strlen(str) / 2); i++)
	{
		push_w(str[i], stack_1);
	}

	for (int i = (strlen(str) / 2); i < strlen(str) ; i++)
	{
		push_w(str[i], stack_2);
	}

	char a;
	cout << " Итоговое слово: ";
	StackEl *counter = stack_1->head;
	while (counter != NULL)
	{
		counter = counter->next;
		a = pop_w(stack_1);
		cout << " " << a;
	}

	counter = stack_2->head;
	while (counter != NULL)
	{
		
		counter = counter->next;
		a = pop_w(stack_2);
		cout << " " << a;
	}
	delete stack_1, stack_2, counter;
}

void push_w(char x, StackEl *myStk)   //Добавление элемента х в стек	
{
	StackEl* e = new StackEl;    //выделение памяти для нового элемента
	e->w = x;             //запись элемента x в поле v 
	e->next = myStk->head;   //перенос вершины на следующий элемент 
	myStk->head = e;         //сдвиг вершины на позицию вперед

}

char pop_w(StackEl *myStk)  //Извлечение (удаление) элемента из стека
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат -1 
	}
	else {
		StackEl *e = myStk->head;   //е - переменная для хранения адреса элемента
		char a = myStk->head->w;   //запись значения из поля v в переменную a 
		myStk->head = myStk->head->next; //перенос вершины
		delete e;                        //удаление временной переменной
		return a;                        //возврат значения удаляемого элемента
	}
}

operate create() {
	return *(new operate);
}

void operate::read() {
	cout << "Введите файл: ";
	char str[100];
	gets_s(str, 100);
	while (strlen(str) == 0) {
		str[0] = 0;
		gets_s(str, 100);
	}
	ifstream fin(str);
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!" << endl;
	int length, currentStrings = 0;
	while (!fin.eof()) {
		fin.getline(str, 100);
		currentStrings++;
		length = strlen(str);
		if (head == NULL) {
			head = new lists(NULL, currentStrings, length, NULL);
		}
		else {
			head = (head->prev = new lists(head, currentStrings, length, NULL));
		}
	}
}

void operate::print() {
	if (head == NULL) {
		cout << "Стек пуст" << endl;
		return;
	}
	lists *e = head;
	int min = e->length, minIndex = e->id;
	while (e != NULL) {
		cout << e->id << ") " << e->length << endl;
		if (min > e->length) {
			min = e->length;
			minIndex = e->id;
		}
		e = e->next;
	}
	cout << minIndex << " - последняя меньшая строка содержит " << min << " символов" << endl;
}

#include "MyStack.h"


int pop(stack* &st) // ���������� ��������
{
	int tmp = st->data;
	stack *pv = st;
	st = st->next;       // �������� ���������� �������������� �������
	delete pv;           // ������������� ������ 
	//cout << tmp << endl; //����� �������� �������� 
	return tmp;
}

void push(stack* &st, int d) // ���������� ��������
{
	stack *pv = new stack;
	pv->data = d;   // �������� ���������� � ����     
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
	cout << "�������� �����: " << endl;
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
	cout << " �������� �����: ";
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

void push_w(char x, StackEl *myStk)   //���������� �������� � � ����	
{
	StackEl* e = new StackEl;    //��������� ������ ��� ������ ��������
	e->w = x;             //������ �������� x � ���� v 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������

}

char pop_w(StackEl *myStk)  //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else {
		StackEl *e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		char a = myStk->head->w;   //������ �������� �� ���� v � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}

operate create() {
	return *(new operate);
}

void operate::read() {
	cout << "������� ����: ";
	char str[100];
	gets_s(str, 100);
	while (strlen(str) == 0) {
		str[0] = 0;
		gets_s(str, 100);
	}
	ifstream fin(str);
	if (!fin.is_open()) // ���� ���� �� ������
		cout << "���� �� ����� ���� ������!" << endl;
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
		cout << "���� ����" << endl;
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
	cout << minIndex << " - ��������� ������� ������ �������� " << min << " ��������" << endl;
}

////����������� �������, ������� ������� �� ����� ������ �������, ��������  �������� ��������� ����� 100, ���� ����� ������� ����.
// 
//#include <iostream>
//using namespace std;
//struct Stack
//{
//	int data;             //�������������� �������
//	Stack* head;		 //������� ����� 
//	Stack* next;		 //��������� �� ��������� �������
//};
//struct Stack1
//{
//	int data;             //�������������� �������
//	Stack1* head;		 //������� ����� 
//	Stack1* next;		 //��������� �� ��������� �������
//};
////-----------------------------------------------------------
//void push(int x, Stack* myStk)   //���������� �������� � � ����	
//{
//	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
//	e->data = x;             //������ �������� x � ���� v 
//	e->next = myStk->head;   //������� ������� �� ��������� ������� 
//	myStk->head = e;         //����� ������� �� ������� ������
//}
////-----------------------------------------------------------
//
//
//void show(Stack* myStk)    //����� �����
//{
//	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
//	int a;
//	if (e == NULL)
//		cout << "���� ����!" << endl;
//	else {
//		cout << "���� ����: " << endl;
//		while (e != NULL)
//		{
//			a = e->data;          //������ �������� �� ���� v � ���������� a 
//			cout << a << " ";
//			e = e->next;
//		}
//		cout << endl;
//	}
//}
////-----------------------------------------------------------
//int pop(Stack* myStk)   //���������� (��������) �������� �� �����
//{
//	if (myStk->head == NULL)
//	{
//		cout << "���� ����!" << endl;
//		return -1;               //���� ���� ���� - ������� -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
//		int a = myStk->head->data;   //������ �������� �� ���� v � ���������� a 
//		myStk->head = myStk->head->next; //������� �������
//		delete e;                        //�������� ��������� ����������
//		return a;                        //������� �������� ���������� ��������
//	}
//}
////-----------------------------------------------------------
//void clear(Stack* myStk)
//{
//	myStk->head = NULL;
//	cout << "���� ������ " << endl;
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
//		cout << "���� ����!" << endl;
//		return -1;               //���� ���� ���� - ������� -1 
//	}
//	else
//	{
//		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
//		int a = myStk->head->data;   //������ �������� �� ���� v � ���������� a 
//		while (e != NULL) {
//			a = e->data;          //������ �������� �� ���� v � ���������� a 
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
//	Stack* myStk = new Stack; //��������� ������ ��� �����
//	myStk->head = NULL;       //������������� ������� ��������	
//	for (;;)
//	{
//		cout << "\n\n������ �� ������. �������� �������:" << endl;
//		cout << "1 - ���������� �������� � ����" << endl;
//		cout << "2 - ���������� �������� �� �����" << endl;
//		cout << "3 - ����� �����" << endl;
//		cout << "4 - ������� �����" << endl;
//		cout << "5 - �������� �������� > 100" << endl;
//		//cout << "6 - ������� ���-�� ���������� ���������" << endl;
//		cout << "7 - �����" << endl;
//		cin >> choice;
//		system("cls");
//		switch (choice)
//		{
//		case 1: cout << "������� ������� ��� �������: " << endl;
//			cin >> choice;
//			push(choice, myStk);
//			system("cls");
//			break;
//		case 2: choice = pop(myStk);
//			if (choice != -1)
//				cout << "����������� �������: " << choice << endl;
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

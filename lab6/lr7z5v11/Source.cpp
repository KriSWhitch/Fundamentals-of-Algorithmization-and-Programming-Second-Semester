#include <iostream>
#include <Windows.h>
#include "MyStack.h"

using namespace std;

void menu() {
	cout << "�������� ��������:" << endl;
	cout << "1. ������ ����� ��������." << endl;//��������� ������� push (����� �������� � ����������)
	cout << "2. ��������� ���������� ��������." << endl;//��������� ������� pop (��������� ����� ������� �� �����)
	cout << "3. ������� ��� ������� �� ����� ������� 3-�." << endl;
	cout << "4. ��������� ���� �� ����� (��� ����� ������ ���� ������� � ����������)." << endl;
	cout << "5. �������� ���� � ���� (��� ����� ������ ���� ������� � ����������)." << endl;
	cout << "6. ����� ��������." << endl; //�������������� ������� �2 
	cout << "7. ����� �������� �����" << endl; //�������������� ������� �3
	cout << "8. �������� ����." << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	stack *p = nullptr;
	StackEl *myStk = new StackEl; //��������� ������ ��� �����
	myStk->head = NULL;       //������������� ������� ��������	
	int buff[20];
	int choice;
	while (true) 
	{
//		system("cls");

		menu();
		
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "������� �������� ��� ��������� � ����:" << endl;
			int val;
			cin >> val;
			push(p, val);
			break;
		}
		case 2: 
		{
			cout << "��������� ��������� ��������: " << pop(p)<<endl;
			break;
		}
		case 3:
		{
			deleteNeKrat3(p);
			break;
		}
		case 4:
		{
			cout << "������� ��� �����, �� �������� �� ������ ��������� ����:" << endl;
			string filename;
			cin >> filename;
			readStackFromFile(filename, p);
			break;
		}
		case 5: 
		{
			cout << "������� ��� ����� � ������� �� ������ �������� ����:" << endl;
			string filename;
			cin >> filename;
			writeStackToFile(filename, p);
			break;
		}
		case 6:
		{
			switch_word();
			break;
		}
		case 7:
		{
			operate stek = create();
			stek.read();
			stek.print();
		}
		case 8: 
		{
			clear(p);
			break;
		}
		default: 
		{
			cout << "�������� �����!" << endl;
		}
		}

		//Sleep(2500);
	}

	return 0;
}

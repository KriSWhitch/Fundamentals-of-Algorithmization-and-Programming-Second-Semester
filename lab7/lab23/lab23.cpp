//������� ������� ��� �������� � ������� ��� �����, ������ � ����������� ������� �������.��� - ��� ������� � ������ � �������.� ������ ���������� ��������� ������� � ��������� ��������� ��� - ���� ������� ������ ��� ��������.

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
using namespace std;

void mainMenu() {
	cout << "\t\t��������, ��� �� ������ �������:\n";
	cout << "1 - �������� �������\n";
	cout << "2 - ����� �������\n";
	cout << "3 - ���� ������ �������� � �������\n";
	cout << "4 - ������ �������\n";
	cout << "0 - ����� �� ���������\n";
}

//--------------------------- �������� ��������� ---------------------


int main()
{
	setlocale(LC_ALL, "Russian");

	Queue* begin = NULL, * end, * t; // ������������ ������� ������
	t = new Queue;

	int menu; // ��� ��������� � ����
	int size; // size - ������������ ������ �������
	char p; // �������� ������

	do
	{
		mainMenu();
		cin >> menu;

		//------------- ���� ��������� -------------
		switch (menu)
		{
		case 1: 	cout << "������� ������������ ������ �������: "; cin >> size;
			cout << "\n������� ������(����! ���������!): "; cin >> p;
			// ������ �������
			t->info = p;
			t->next = NULL;
			begin = end = t;
			for (int i = 1; i < size; i++) // �������� �������
			{
				cout << "������� ������: "; cin >> p;
				createQueue(&begin, &end, p);
			}
			break;
		case 2: 	cout << "\n\t�������� �������: \n";
			viewQueue(begin);
			break;
		case 3:
			cout << "������� ������ ��� ������ ����� �������: "; cin >> p;
			insertInQueue(&begin, &end, p, size);
			cout << "����� �������\n";
			viewQueue(begin);
			break;
		case 4: cout << "� ������� " << QueueSize(begin) << " ���������/��\n";
			break;
		case 0: exit(0); break;
		default: cout << "�������� ����, ���������� ��� ���!\n";
			break;
		}
	} while (menu != 0);
}
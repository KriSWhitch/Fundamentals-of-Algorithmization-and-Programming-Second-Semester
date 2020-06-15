//��������� ���-�������, ���������� ����� � ���������� �� ��������� �� ��������� ������. 
//������� ������� �� �����. ����������� ����� ��������� ����� � ���-�������.

#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Twin_Chain.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

// ��������� "��������� �����"
struct Letter
{
	// �����
	char character;
	// ���������� ���������
	int number;

	// ����������� �����
	Letter(char c, int i)
	{
		character = c;
		number = i;
	}

	// ����������� ��� ����������
	Letter()
	{
		number = 0;
	}
};

// ���-�������
int hf(void* key)
{
	return (int)((Letter*)key)->character;
}



// ��������� ������
void readString(hashTC::Object& H)
{
	char str[256];
	cout << "������� ������: ";
	cin >> str;

	// ���� �� �������� ������
	for (size_t i = 0; i < strlen(str); i++)
	{
		Letter* l = new Letter;
		Letter* l1 = new Letter;
		l->character = str[i];
		l1->character = str[i];
		// ���� ������ �� ������
		if (H.search(l) == NULL)
		{
			// ����� ��� ������ ���������
			l1->number = 1;
			// ��������� � �������
			H.insert(l1);
		}
		else
		{
			// ����� ����������� �� 1 ����� ���������
			l1->number = ((Letter*)(H.search(l)->data))->number + 1;
			H.setValue(l, l1);
		}
	}
}

// ����� �� �����
void Letter_print(listx::Element* e)
{
	std::cout << ((Letter*)e->data)->character << '-' << ((Letter*)e->data)->number << " / ";
}

// �������� ���������
int main()
{
	setlocale(LC_ALL, "rus");

	int current_size = 7;
	// �������� �������
	cout << "������� ������ ���-�������: ";
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	char c;
	// ����������� ����
	for (;;)
	{

		cout <<endl<< "1 - ����� ���-�������" << endl;
		cout << "2 - ���� ������" << endl;
		cout << "3 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		
		cout << "�������� �����: ";
		cin >> choice;
	
		cout << endl;
		switch (choice)
		{
			// 0 - �����
		case 0:
			exit(0);
			// 1 - ����� �������
		case 1:
			H.Scan();
			break;
			// 2 - ���������� ��������
		case 2:
		{
			readString(H);
			break;
		}
		break;
		// 3 - ����� ��������
		case 3:
		{
			Letter* l = new Letter;
			cout << "������� �����: ";
			cin >> c;
			l->character = c;
			// ���� ����� �� ��������� �������
			if (H.search(l) == NULL)
				// ����� ���������
				cout << "����� �� �������!" << endl;
			else
			{
				// ����� ����� ���������� ������� ��������
				cout << "����� � ������ ������: ";
				Letter_print(H.search(l));
			}
			cout << endl;
		}
		break;
		}
	}
	return 0;
}

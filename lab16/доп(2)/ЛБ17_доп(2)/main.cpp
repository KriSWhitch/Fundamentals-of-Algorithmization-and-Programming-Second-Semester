/*��������� ���-������� �� ���� ������������� ���������� �����, ����� �� ����������� � ������. ������� ����������� ������� ���� �� �����. ����������� ����� ���������� �����. 
��������� ��������� ��� ��������� ������������ ���-���� � �������� ���������� ���������. ������� ��� �����, ������������ �� ��������� �����, �������� �������.*/

#define _CRT_SECURE_NO_WARNINGS
#include "Hash_Twin_Chain.h"
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
int choice;
// ��������� "������ �� �����"
struct StrFile
{
	// ������ ����� ������
	char character;
	// ������
	string str;

	// ����������� ������ �� �����
	StrFile(char c, string s)
	{
		character = c;
		str = s;
	}

	// ����������� ��� ����������
	StrFile()
	{
	}
};

// ���-�������
int hf(void* key)
{
	return (int)((StrFile*)key)->character;
}

// ������ �����
void readFile(hashTC::Object& H)
{
	ifstream file("2.txt");
	if (file.is_open())
	{
		// ���� ���� �� ����������
		string line;
		while (getline(file, line))
		{
			StrFile* sf = new StrFile;
			// ������ �� ������
			sf->character = line[0];
			sf->str = line;
			H.insert(sf);
		}
		file.close();
	}
}

// ����� �� �����
void StrFile_print(listx::Element* e)
{
	std::cout << ((StrFile*)e->data)->character << '-' << ((StrFile*)e->data)->str << " / ";
}

void menu() {
	cout << endl;
	cout << "1 - ����� ���-�������" << endl;
	cout << "2 - ������ �� �����" << endl;
	cout << "3 - ����� ��������" << endl;
	cout << "4 - �������� ��������" << endl;
	cout << "5 - ������ ���������� ���������" << endl;
	cout << "0 - �����" << endl;

	cout << "�������� �����: ";
	cin >> choice;
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
	char c;
	// ����������� ����
	for (;;)
	{
	

		menu();
		
		switch (choice)
		{
			// 0 - �����
		case 0:
			exit(0);
			// 1 - ����� �������
		case 1:
			cout << endl;
			H.Scan();
			break;
			// 2 - ���������� ��������
		case 2:
		{
			readFile(H);
			break;
		}
		break;
		// 3 - ����� ��������
		case 3:
		{
			cout << endl;
			StrFile* l = new StrFile;
			cout << "������� �����: ";
			char str[256];
			cin >> str;
			l->character = str[0];
			l->str = str;
			// ���� ����� �� ��������� �������
			int index;
			if (H.search(l, index) == NULL)
				// ����� ���������
				cout << "����� �� ������!" << endl;
			else
			{
				cout << "����� �����: ";
				cout << "������: " << index << ". �����:  ";
				StrFile_print(H.search(l, index));
			}
			cout << endl;
		}
		break;
		// �������� �� �����
		case 4:
		{
			cout << endl;
			StrFile* l = new StrFile;
			cout << "������� �����: ";
			cin >> c;
			l->character = c;
			int index, cmp;
			// ���� ���� ������, ������������ �� ��� �����, �������
			while (H.search(l, index, cmp) != NULL)
				H.deleteByData(l);
			H.Scan();
		}
		break;
		// ���������
		case 5:
		{
			cout << endl;
			int cmp, index;
			hashTC::Object H1 = hashTC::create(3, hf);
			readFile(H1);
			StrFile* l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "������: 3. ���������� ���������: " << cmp << endl;

			H1 = hashTC::create(5, hf);
			readFile(H1);
			l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "������: 5. ���������� ���������: " << cmp << endl;

			H1 = hashTC::create(20, hf);
			readFile(H1);
			l1 = new StrFile;
			l1->character = 'd';
			H1.search(l1, index, cmp);

			cout << "������: 20. ���������� ���������: " << cmp << endl;
		}
		}
	}
	return 0;
}

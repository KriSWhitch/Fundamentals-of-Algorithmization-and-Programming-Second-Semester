///*������� ������, ���������� �������� ������ ����. ����� ����� ������������� ���������, ������� 5, ��� ������ ���������, ��� ����� ��������� ���. */
//
//#include <iostream>
//#include <fstream>
//
//struct list
//{
//	int symbol;
//	list* next;
//};
//
////----------------------------- ��������� ������� -----------------------------
//
//void insert(list*& p, int value); //���������� ����� � ������ ������
//void printList(list* p); //����� ������ 
//void toFile(list*& p); //������ � ����
//void fromFile(list*& p);  //���������� �� �����
//void menu(void); //����� ����
//int SumIntMod5Positive(int our_number, list* p);
//using namespace std;
//
////------------------- �������� ��������� -----------------------------
//int main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	list* first = nullptr;
//	int choice; int value;
//	menu(); // ������� ���� 
//	cout << " ? ";
//	cin >> choice;
//	while (choice != 5)
//	{
//		switch (choice)
//		{
//			//------------------------ ���� ������� -----------------------
//		case 1:  	cout << "������� �����: ";
//			cin >> value;
//			insert(first, value);
//			printList(first);
//			break;
//
//			//------------------------- ������ � ���� -------------------
//		case 2:    toFile(first);
//			break;
//
//			//-------------------- ���������� �� ����� --------------
//		case 3:    fromFile(first);
//			break;
//
//			//-------------------- ����� ������������� ��������� ������ ---------------
//		case 4:		SumIntMod5Positive(value, first);
//			break;
//
//			//----------------------- ������ �� ������ -------------------
//		default:   cout << "������������ �����!" << endl;
//			break;
//		}
//		cout << "��� ������?\n";
//		menu();
//		cin >> choice;
//	}
//	return 0;
//}
//
////------------------ ���������� ������� � ������ ������ -----------------------
//void insert(list*& p, int value)
//{
//	list* newP = new list;
//	if (newP != NULL)     //���� �� �����?  
//	{
//		newP->symbol = value;
//		newP->next = p;
//		p = newP;
//	}
//	else
//		cout << "�������� ���������� �� ���������" << endl;
//}
//
////------------------- ����� ������ ------------------------
//void printList(list* p)
//{
//	if (p == NULL)
//		cout << "������ ����" << endl;
//	else
//	{
//		cout << "������:" << endl;
//		while (p != NULL)
//		{
//			cout << "-->" << p->symbol;
//			p = p->next;
//		}
//		cout << "-->NULL" << endl;
//	}
//}
//
////----------------- ������ � ���� --------------------
//void toFile(list*& p)// �������� � ����� �������, ������� ���������� ������ �� ���� 
//{
//	list* temp = p;// �������� ���������
//	list buf;// ����� ��� ������ � ����
//	ofstream frm("mList.dat");
//	if (frm.fail()) // ���� ��������� �������������� ������
//	{
//		cout << "\n ������ �������� �����";
//		exit(1);
//	}
//	while (temp)
//	{
//		buf = *temp;
//		frm.write((char*)&buf, sizeof(list));
//		temp = temp->next;// ������������ �� ��������� �����
//	}
//	frm.close();
//	cout << "=== ������ ������� � ���� mList.dat! ===\n";
//}
//
////----------------- ���������� �� ����� ----------------
//void fromFile(list*& p)// �������� � ����� �������, ������� ���������� ������ �� ���� 
//{
//	list buf, * first = nullptr;
//	ifstream frm("mList.dat");
//	if (frm.fail())
//	{
//		cout << "\n ������ �������� �����";
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
//	cout << "\n=== ������ ������ �� ����� mList.dat! ===\n";
//}
//
////--------------------- ����� ���� --------------------------- 
//void menu(void)
//{
//	cout << "�������� �����:" << endl;
//	cout << " 1 - ���� �����(������)" << endl;
//	cout << " 2 - ������ ������ � ����" << endl;
//	cout << " 3 - ������ ������ �� �����" << endl;
//	cout << " 4 - ����� ������������� ���������, ������� 5-��" << endl;
//	cout << " 5 - �����" << endl;
//}
//
////------------------------ ���������� ����� ������������� ���������, ������� 5-�� -----------------
//int SumIntMod5Positive(int our_number, list* p)
//{
//	int sum = 0;
//	for (p; p != NULL; p = p->next)
//	{
//		our_number = p->symbol;
//		if ((our_number > 0) && (our_number % 5 == 0))
//		{
//			cout << "���� ������������� �����, ������� 5-��: " << our_number << endl;
//			sum = sum + our_number;
//		}
//	}
//	if (sum == 0)
//	{
//		cout << "������������� ��������� ��� ��� �� ��� ���������, ������� 5-��\n";
//	}
//	cout << "����� ������������� ���������, ������� 5-��: " << sum << endl;
//	return sum;
//}
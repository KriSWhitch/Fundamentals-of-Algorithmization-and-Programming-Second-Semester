//������� ������� � ������������� �������, � ��������� �� � ����������.��������� ����������� ����� ��������� � �������
//���, ����� � �� ������ ��� ���������� ���������� �������.
#include <iostream> 
#include "MyQueue.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	Number *begin = NULL, *end=NULL, *t=NULL;
	
	int size;
	float p;
	
	cout << "������� ������ �������:" << endl;
	cin >> size;
	
	for (int i = 0; i < size; i++) //�������� �������
	{
		cout << "������� �������:" << endl;
		
		cin >> p;
		
		create(&begin, &end, p);
	}

	cout << "�������� �������:" << endl;
	
	
	view(begin);

	t = maxElem(begin);    //����������� �������������
	cout << "����������� �������: " << t->info << endl;

	CyclycShift(&begin, &end, t);

	cout << "����� ��������� �������:" << endl;
	view(begin);

	cout << "DONE!" << endl;
	system("pause");
	return 0;
}
//������� ��������� ������ �������� ����, ������ � ��� ��������� �� ��������. �������� ����-���, ������� ������������ ����� ������ �� ����� �� ��������� ������� � �������� ������, � ��-����� ��. 

//------------------------------- ������� -------------------------------
#include "stdafx.h"
#include "Tree.h"
#include <iostream>
using namespace std;
int c = 0;  // ���������� ����
//----------------- �������� ������ ----------------- 
Tree* makeTree(Tree *Root)  
{
	int key; char s[5];
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL)	// ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s); // ��������� ��������� �� ������
	}
	while (1) // ���������� ���������, ���� �� ����� �����. �����
	{
		cout << "\n������� ����: ";  cin >> key;
		if (key < 0) break;       //������� ������ (���� < 0)   
		cout << "������� �����: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}
//-------------------- �������� ������ �������� -------------------- 
Tree* list(int i, char *s)     
{
	Tree *t = new Tree[sizeof(Tree)]; // ������ ��������� �� ������ �����
	t->key = i; // � ���� key ������ �������� ����
	for (i = 0; i < 5; i++) // ���� ����������� ��� ����� ������ �� �����������, � �������
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL; // ��������� � ������ �������� ��������� � �������
	return t;
}
//---------------------- ���������� ������ �������� ----------------------
Tree* insertElem(Tree *t, int key, char *s)  
{
	Tree *Prev = new Tree[sizeof(Tree)]; // Prev - ������� ����� �������
	int find = 0;  // ������� ������
	while (t && !find)
	{
		Prev = t; 
		if (key == t->key)
			find = 1; // ����� ������ ���� ���������!
		else
			if (key < t->key) t = t->Left; // ���� ���� ������, ��� �������, �� ����������� �� ����� �����, �.� ��� ������
			else t = t->Right; // ����� ����������� �� ������ �����
	}
	if (!find) // ������� ����� � ������� Prev � ��� ���� ����� �� �������
	{
		t = list(key, s);   // ��������� ����� ���� 
		if (key < Prev->key)  // � ��������������, � ������ 
			Prev->Left = t;    // ���� ������� �� ����� �����,
		else
			Prev->Right = t;   // ���� �� ������ 
	}
	return t;
}
//---------------- �������� �������� �� ����� ----------------
Tree* delet(Tree *Root, int key)  
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
	// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
	Tree *Del, *Prev_Del, *R, *Prev_R;
	Del = Root; // �� ������� ������� ������ ������
	Prev_Del = NULL; // � ���������� �����, ���� ���, ���
	while (Del != NULL && Del->key != key)// ����� �������� � ��� �������� 
	{
		Prev_Del = Del; // ���������� ��������� � ��������
		if (Del->key > key) // ���� ���� �������� ������
			Del = Del->Left; // �� ��� �����
		else
			Del = Del->Right; // ����� ������
	}
	if (Del == NULL)  // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	// ����� �������� R ��� ������
	if (Del->Right == NULL) // ���� � ��������� ��� ��������� �� ������ �����
		R = Del->Left; // �� ������� ��� ������ ��������� �� ����� �����
	else
		// ���� ��������, �� �� ������
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; // ����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	// �������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� ����� 
		else
			Prev_Del->Right = R;	// �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}
//--------------------- ����� �������� �� ����� --------------------- 
Tree* search(Tree* n, int key)  
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key >(key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}
//----------------------- ������� ���������� ���� -----------------------
int count(Tree *t, char letter) 
{
	if (t) // ���� ��� ��������� �� NULL
	{
		count(t->Right, letter); // ������� � ������ ������ � �����������
		if (*(t->text) == letter) // ���� �������� ����� ��������� � ���������
			c++; // �� ����������� �������
		count(t->Left, letter); // ������� � ����� ������ � �����������
	}
	return c; 
}
//----------------------- ����� ������ (�����)----------------------- 
void view(Tree *t, int level) 
{
	if (t)
	{
		view(t->Right, level + 1);	// ����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	// ����� ������ ���������
	}
}
//--------------- ������� ������ ---------------
void delAll(Tree *t) 
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

//--------- �������� ������� ---------
//�������� ������� ������ ���������� ������� ������� ������. 
int LeafCount(Tree *t) // ������� ���������� �������
{
	if (t == NULL) // ���� ��������� � �������
		return 0; // ���������� ����
	else
	{
		if ((t->Left == 0) && (t->Right == 0)) // ���� ��� ���������� �� ����� � ������ �����
			return 1; // ���������� 1
		else // ���� ���-�� ����
			return LeafCount(t->Left) + LeafCount(t->Right); // ���������� ���������� ��������� �������
	}
}

//------------------- ��� ������� 2 -------------------
// �������� ������� ����������� ���������� ����� � ������� �������.
int ChetnieYzli(Tree *t)
{
	int amount = 0;
	if (t == NULL)
		return 0;
	else
	{
		if (t->key % 2 == 0)
		{
			amount++;
		}
		return amount + ChetnieYzli(t->Left) + ChetnieYzli(t->Right);
	}
}
//---------------- ��� ������� 3 ----------------
//�������� ������� ����������� ���������� ����� ������ ����� ������.
int amount_right_side(Tree *t)
{
	//Tree *t = Root;
	int amount = 0;
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if ((t->Right != NULL))
		{
			amount++;
		}
		return amount + amount_right_side(t->Right);
	}
}

//---------------------- ��� ������� 1 ----------------------
//---------------------- ����� ����� ������ � ����� ������ �� ����� �� ��������� ������� �� ��������� ����� ----------------------
int ClosestVetvi(Tree* Root, int find_key)
{
	int vetvi = 0; // ����� ������
	int level = 0; // ����� ������� (���������� ��� ������)
	Tree* closest = Root; // ��������� �� ��� ������
	if (closest != NULL) // ���� ��������� �� �� �������
	{
		cout << "\t�����\n";
		if (find_key < (find_key, Root->key))
		{
			closest = search(Root->Left, find_key);
			view(Root->Left, level + 1); // ����� ������ ���������
			vetvi = vetvi + Vetvi(Root->Left);
			for (int i = 0; i < level; i++)
			{
				cout << "   ";
			}
		}
		else
		{
			if (find_key > (find_key, Root->key))
			{
				closest = search(Root->Right, find_key);
				view(Root->Right, level + 1);	// ����� ������� ���������
				vetvi = vetvi + Vetvi(Root->Right);
			}
		}
	}
	else
		cout << "��� ������ ��������\n";
	return vetvi;
}

// ���������� ������
int Vetvi(Tree* t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + Vetvi(t->Left) + Vetvi(t->Right);
}


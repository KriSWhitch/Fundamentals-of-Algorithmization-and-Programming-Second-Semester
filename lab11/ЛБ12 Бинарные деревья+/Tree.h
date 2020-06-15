#pragma once
//---------------- ��������� ������� ----------------
#include <iostream>
namespace btree // ������ ������������ ��� ������������ ��� ����, ����� �������� ����������
{
	enum CMP // ������������ ��� ���������
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	// Node ��������� ��� ���� �������� ��������� � ���������, 
	//������� ����� ������� ����� demoTree.Root->��������_�������(���������)

	//---------------- ��������� ������� ������ ������ ----------------

	struct Node 
	{
		Node* parent;  // ��������� �� ��������  
		Node* left;    // ��������� �� ����� �����
		Node* right;   // ��������� �� ������ �����
		void* data;    // ��������� �� ������ 

		//-------------- ����������� --------------

		Node(Node* p, Node* l, Node* r, void* d) 
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}

		Node* next();  // ��������� �� �����
		//Node* prev(); // ���������� �� �����
		Node* min(); // ������� � ���������
		Node* max();  // �������� � ���������  

		//-------- ����� ������� --------
		void scanDown(void(*f)(void* n)); // ����� ��������� ������ ���� (����������)
		void scanUp(void(*f)(void* n)); // ����� ������ ����� ����� (����������)
		void scanMix(void(*f)(void* n)); // ��������� �����
		bool isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)); // �������� ������������������ ������
		int testDepth(int(*f)(int a, int b)); // �������� �������
		int amount_vetvi(Node *p); // ���������� ������ �� ������� � ������� ������

		//void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int); // ����� �� ������
		int getLevel(); // �������� �������� ������
		void scanByLevel(void(*f)(void* n));
	};

	//------------------------ ��������� ��������� ������ ------------------------

	struct Object 
		// � ����� ������ ��������� Object ��������� ��� ����� ������� demoTree
		//��� ������ ���������� ���: demoTree.��������_������(���������)
	{
		Node* Root;  // ��������� �� ������ 
		CMP(*compare)(void*, void*);  // ������� ���������, ��� *compare - ��������� �� ������� � ����������� (void*, void*)
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL; // ��������� �� ������(��� �������� �� ���������)
			compare = f; // ! ��������� �� ������� � ����� ������ CMP !
		};

		//-------- ����� ������� --------
		int show_vetvi(void* d, Node* n); //����� ����� ������ � ���������� ������ �� ������� � ������
		int amount_vetvi2(Node *p); // ���������� ������ �� ������� � ������� ������
		void view_vetvi(Node *n); // ��� ������ ������

		// ������ ������� ���������� ��� ���������� ��������� ���� ��������� ������ ������
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS; // ������
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT; // ������
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL; // �����
		};
		bool insert(void* data); // �������� �������
		Node* search(void* d, Node* n); // ����� �������
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);  // ������� �� ������ �������� 
		bool deleteByData(void* data) // ������� �� �����
		{
			return deleteByNode(search(data));
		};

		bool isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)) // �������� ������������������
		{
			Root->isBalanced(f1, f2);
		}

		int testDepth(int(*f)(int a, int b)) // �������� �������
		{
			Root->testDepth(f);
		}
	};

	Object create(CMP(*f)(void*, void*)); // ������� �������� ������    
};

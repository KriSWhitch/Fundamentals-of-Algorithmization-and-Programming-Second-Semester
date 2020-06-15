//------------- �������� ������� -------------
#include "stdafx.h"
#include "Tree.h"
#include "Math.h"
#include <iostream>
namespace btree // �������� ������, �� ����������� ������������ ������
// � ���������� ������� ����������� ��� ������������ ���
// ����� ��� � std::cout , ������ btree:: ...
{
	Object create(CMP(*f)(void*, void*))
	{
		return *(new Object(f));
	}

	Node* Node::min() // ����� ������������ ��������
	{
		Node* rc = this; // �������� ��������� �� �������, �.� �������� �������� �������� (��� ����� ������)
		if (rc->left != NULL) // ���� ���������� �������� � ����� ���������
			rc = rc->left->min(); // �� ��������� ��������� ����� �� �����, ��� ��� ��� � ����� ���������� ����� ����� ������� ������
		return rc;
	}

	Node* Node::max() // ����� ������������� ��������
		// ������������ ������� ����� ����� ����� ���� ������
	{
		Node *rc = this;
		if (rc->right != NULL)
			rc = rc->right->max();
		return rc;
	}

	Node* Node::next() // ����������� ���������� �������� ������
	{
		Node* rc = this, *x = this; // ���� ��� ��� ��������� ��������� �� ���� ������� ������
		if (rc->right != NULL) // ���� ���������� ������ ���������
			rc = rc->right->min(); // ��� �� ����� ����� ������
		else
		{
			rc = this->parent; // ����� ��������� ��������� �� ��������
			while (rc != NULL && x == rc->right) // ���� ��������� �� �������� ���������� � ������� ��������� ����� ��������� �� ������ ���������
			{
				x = rc;
				rc = rc->parent;
			}
		}  return rc;
	}



	//------------------- ����� ������� -------------------



	//--------------- ������� ���������� ������ �� ����� �� ������� � �������� ������ ---------------
	int Object::show_vetvi(void* d, Node* n)
	{
		int vetvi = 0; // ����� ������
		Node* rc = n;
		if (rc != NULL)
		{
			std::cout << "�����\n";
			if (isLess(d, n->data)) // ���� ��� ������� ���� ������, ��� ���� �����
			{
				rc = search(d, n->left); // ���� ������� � ����� ����� ������
				view_vetvi(n->left);
				vetvi = vetvi + amount_vetvi2(n->left);
			}
			else
				// ���� ������� ���� ������, ��� ���� �����
				if (isGreat(d, n->data))
				{
					rc = search(d, n->right); // ���� ��� � ������ ����� ������
					view_vetvi(n->right);
					vetvi = vetvi + amount_vetvi2(n->right);
				}
		}
		else
		{
			std::cout << "������ �������� ���!" << std::endl;
		}
		return vetvi;
	}

	//-------------- ���������� ������(��� ����, � ���������� �������������� �� �����) -------------- 
	int Node::amount_vetvi(Node *p)
	{
		if (p == NULL)
			return 0;
		else
			return 1 + amount_vetvi(p->left) + amount_vetvi(p->right);
	}

	//---------- ���������� ������ 2(��� ����� ��������������) ----------
	int Object::amount_vetvi2(Node *p)
	{
		if (p == NULL)
			return 0;
		else
			return 1 + amount_vetvi2(p->left) + amount_vetvi2(p->right);
	}

	//-------- ������� ��� ������ ������ -------- 
	void Object::view_vetvi(Node *n)
	{
		Node *rc = n;
		if (rc != NULL)
		{
			view_vetvi(rc->right);
			int *key = (int*)rc->data; // ��������� �����, ��� ��� data ����� ��� void*, � ��� ������ �� ����� �������� ����� �����, � �� ��� ��������
			std::cout << *key << " -> " << std::endl;
			view_vetvi(rc->left);
		}
	}

	//----------- ���������� ����� -----------
	void Node::scanDown(void(*f)(void* n)) 
	//���� ������:
	//1) ������� ������ (������� ������� ������)
	//2) ������� ����� ��������� �� ����� (������� �������� ������)
	//3) ������� ������ ��������� �� ����� (������� �������� ������)
	// �����: ������� �� �������� �������� ������ � �������� (�� ������� � �����)
	{
		f(this->data); // ������� � ������� f ���������� ���� (��� ����� ������)
		std::cout << std::endl; // ������� ������
		if (this->left != NULL) // ���� ���������� ��������� �� ����� ���������
			this->left->scanDown(f); // ���������� �������� �������
		if (this->right != NULL) // ���� ���������� ��������� �� ������ ���������
			this->right->scanDown(f); // ���� �������
		// � ����� �� ����� �������� ������ �� ����� � �������
	}

	//-------------- ���������� ����� --------------
	void Node::scanUp(void(*f)(void* n)) 
	// ���� ������:
	//1) ������� ����� ���������, ������� � ��� ����� (� ������ ������ ��������)
	//2) ������� ������ ���������, ������� � ��� ����� (� ������ ������ ��������)
	//3) ������� ������
	// �����: ������� �� ������ ������ ����� ������ �� ������ ����� (�� ����� � �����)
	{
		// �� ������� ������� �� ������ ������ �����
		if (this->left != NULL)
		this->left->scanUp(f);
		if (this->right != NULL)
		this->right->scanUp(f);
		f(this->data); // �������� ��� ����
		std::cout << std::endl; // � �� ����� ������� ������ �� ������� � �����
	}

	//------------ ��������� ����� ------------
	void Node::scanMix(void(*f)(void* n)) 
	{
		// ������� ������� �� ����� ������ ���������
		if (this->left != NULL)
		this->left->scanMix(f);
		f(this->data); 
		std::cout << std::endl; // ����� ��� �������
		// � ��� ���������� ������� ������ ���������
		if (this->right != NULL)
		this->right->scanMix(f);
		// �� ����� ���������, ��� ������� ��������� ��������� ����� ���������, ����� ������, � ����� ������
	}

	//------------ �������� ������� ------------
	int Node::testDepth(int(*f)(int a, int b)) 
	{
		if (!this) 
		{
			return 0;
		}
		else
		{
			return (1 + f(this->left->testDepth(f), this->right->testDepth(f)));
		}
	}

	//----------- �������� ������������������ -----------

	// ������ ��������������� �����, ����� ������� ����� ������������ ���� �� ��������� 1-�� � ��� ���� �� �������� ����������� ���� �� �����
	bool Node::isBalanced(int(*f1)(int a1, int b1), int(*f2)(int a2, int b2)) 
	{
		if (abs((this->testDepth(f1) - this->testDepth(f2))) <= 1)
			return abs((this->testDepth(f1) - this->testDepth(f2)));
	}

	//-------- ����� �������� --------
	Node* Object::search(void* d, Node* n)
	{
		Node* rc = n;
		if (rc != NULL)
		{
			if (isLess(d, n->data))
				rc = search(d, n->left);
			else
				if (isGreat(d, n->data))
					rc = search(d, n->right);
		} return rc;
	}

	//-------- ������� �������� -------- 
	bool Object::insert(void* d)
	{
		Node* x = this->Root, *n = NULL;
		bool rc = true;
		while (rc == true && x != NULL)
		{
			n = x;
			if (isLess(d, x->data))
				x = x->left;          //����� ���� ���� - ����� ��� ������
			else
				if (isGreat(d, x->data))
					x = x->right;
				else
					rc = false;
		}
		if (rc == true && n == NULL)
			this->Root = new  Node(NULL, NULL, NULL, d);
		else
			if (rc == true && isLess(d, n->data))
				n->left = new  Node(n, NULL, NULL, d);
			else
				if (rc == true && isGreat(d, n->data))
					n->right = new  Node(n, NULL, NULL, d);
		return rc;
	};

	//------------- �������� �������� -------------
	bool  Object::deleteByNode(Node* n)
	{
		bool rc = true;
		if (rc = (n != NULL))
		{
			if (n->left == NULL && n->right == NULL)  //���� �������� ���
			{
				if (n->parent == NULL)
					this->Root = NULL;   //��������� �����
				else
					if (n->parent->left == n)
						n->parent->left = NULL;
					else
						n->parent->right = NULL;
				delete n;
			}
			else
				if (n->left == NULL && n->right != NULL) //������ ������ �������
				{
					if (n->parent == NULL)
						this->Root = n->right;
					else
						if (n->parent->left == n)
							n->parent->left = n->right;
						else
							n->parent->right = n->right;
					n->right->parent = n->parent;
					delete n;
				}
				else
					if (n->left != NULL && n->right == NULL) //������ ����� �������
					{
						if (n->parent == NULL)
							this->Root = n->left;
						else
							if (n->parent->right == n)
								n->parent->left = n->left;
							else
								n->parent->right = n->left;
						n->left->parent = n->parent;
						delete n;
					}
					else                                  //���� ���� ��� �������
						if (n->left != NULL && n->right != NULL) {
							Node* x = n->next();
							n->data = x->data;
							rc = deleteByNode(x);
						}
		} return  rc;
	}

	//-------------------------------
	void Node::scanLevel(void(*f)(void* n), int i)  //������� ������� ������
	{
		if (this->left != NULL)
			this->left->scanLevel(f, i);
		if (this->getLevel() == i)
			f(this->data);
		if (this->right != NULL)
			this->right->scanLevel(f, i);
	}

	//-------------------------------
	int Node::getLevel()
	{
		Node *rc = this;
		int q = 0;
		while (rc->parent != NULL)
		{
			rc = rc->parent;
			q++;
		}
		return q;
	}

	//-------------------------------
	void Node::scanByLevel(void(*f)(void* n)) // ����� ������ �� ����� �� �������
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << '\t';
			this->scanLevel(f, i);
			std::cout << '\n';
		}
	}
}

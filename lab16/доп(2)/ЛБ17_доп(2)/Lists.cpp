#include "Lists.h"
#include <iostream>

// ��������� "������ �� �����"
struct StrFile
{
	// ������ ����� ������
	char character;
	// ������
	std::string str;
};

namespace listx
{
	// ���������� �������� (���������� �������� "�������"-"�� �������")
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		// ���� ������ �����
		if (head == NIL)
			// ������� ������
			head = new Element(NULL, data, NULL);
		else
			// ����� ���������
			head = (head->prev = new Element(NULL, data, head));
		return head;
	}

	// ����� ��������
	Element* Object::search(void* data)
	{
		// �������� � ������
		Element* rc = head;
		// ���� �� ����� �������� ��� ������ �� ����������
		while ((rc != NIL) && (((((StrFile*)rc->data)->character) != ((StrFile*)data)->character)
			|| ((((StrFile*)rc->data)->str) != ((StrFile*)data)->str)))
			rc = rc->next;
		return rc;
	}

	// ����� ��������
	Element* Object::search(void* data, int& cmp)
	{
		cmp = 0;
		// �������� � ������
		Element* rc = head;
		// ���� �� ����� �������� ��� ������ �� ����������
		while ((rc != NIL) && ((((StrFile*)rc->data)->character) != ((StrFile*)data)->character))
		{
			rc = rc->next;
			cmp++;
		}
		return rc;
	}

	// �������� �� ��������
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		// ���� �� �����
		if (rc = (e != NIL))
		{
			// �������� ��������� �������
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			// ������������ ������
			delete e;
		}
		// ����� ���������
		std::cout << "������� ������!" << std::endl;
		return rc;
	}

	// �������� �� ������
	bool Object::deleteByData(void* data)
	{
		int cmp;
		// ���� ������� � ������� �� ����
		return deleteByElement(search(data, cmp));
	}

	// ��������� �����
	Element* Object::getLast()
	{
		// �������� ������
		listx::Element* e = this->getFirst(),
			* rc = this->getFirst();
		// ��������, ���� ��������, � �����
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}

	// �������� �������
	Object create()
	{
		// ����� ������������
		return *(new Object());
	};

	// ����� �� �����
	void Object::scan()
	{

		// �������� "������"
		listx::Element* e = this->getFirst();

		if (e == NULL)
			std::cout << "NULL-NULL";
		// ���� ���� �����������
		while (e != NULL)
		{
			// ����� ��������
			std::cout << ((StrFile*)e->data)->character << '-' << ((StrFile*)e->data)->str << " / ";
			e = e->getNext();
		};
	}
}


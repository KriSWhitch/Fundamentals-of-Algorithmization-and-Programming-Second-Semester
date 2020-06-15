#include "Lists.h"
#include <iostream>

// ��������� "��������� �����"
struct Letter
{
	// �����
	char character;
	// ���������� ���������
	int number;
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
		while ((rc != NIL) && ((((Letter*)rc->data)->character) != ((Letter*)data)->character))
			rc = rc->next;
		int k = -1;
		if (rc != NULL)
			k = ((Letter*)rc->data)->number;
		return rc;
	}

	// ��������� ��������
	void Object::setValue(void* data, void* newData)
	{
		// �������� � ������
		Element* rc = head;
		// ���� �� ����� �������� ��� ������ �� ����������
		while ((rc != NIL) && ((((Letter*)rc->data)->character) != ((Letter*)data)->character))
			rc = rc->next;
		((Letter*)rc->data)->number = ((Letter*)newData)->number;
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
		// ���� ������� � ������� �� ����
		return deleteByElement(search(data));
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
			std::cout << ((Letter*)e->data)->character << '-' << ((Letter*)e->data)->number << " / ";
			e = e->getNext();
		};
	}
}


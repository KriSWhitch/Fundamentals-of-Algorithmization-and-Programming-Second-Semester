#include "Hash_Twin_Chain.h"
#include "Lists.h"
#include <iostream>
#include <string>

namespace hashTC
{
	// �������� �������
	Object create(int size, int(*f)(void*))
	{
		// ����� ������������
		return *(new Object(size, f));
	}

	// ���-�������
	int Object::hashFunction(void* data)
	{
		// ��������� ������
		return (FunKey(data) % size);
	}

	// ���������� (���������� �������� "���������"-"�� ���������")
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	}

	// �������� �� ������
	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	}

	// �����
	listx::Element* Object::search(void* data, int& index)
	{
		index = hashFunction(data);
		return Hash[index].search(data);
	}

	// �����
	listx::Element* Object::search(void* data, int& index, int& cmp)
	{
		return Hash[hashFunction(data)].search(data, cmp);
	}

	// ����� ������� �� �����
	void Object::Scan()
	{
		// ���� �� ���� ��������� �������
		for (int i = 0; i < size; i++)
		{
			std::cout << "[������ " << i << "]     ";
			// ����� �������
			Hash[i].scan();
			// ������� �� ����� ������
			std::cout << '\n';
		}
	}

}


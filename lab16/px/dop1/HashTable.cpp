#include "stdafx.h"
#include "HashTwinChain.h"
#include "Lists.h"
#include <iostream>


namespace hashTC
{
	//------- �������� ���-������� ------- 
	Object create(int size, int(*f)(void*)) 
	{
		return *(new Object(size, f)); // �������� ������
	}

	//-------- ������������� ���-������� --------
	int Object::hashFunction(void* data) // data -������������ ����
	{
		int key = FunKey(data);
		int p = 10000;
		int a = 9995;
		int b = 9992;
		int hash_key = (int)(((a * key + b) % p) % size);
		return hash_key;
	};

	//--------- ������� �������� ---------
	bool Object::insert(void* data) 
	{
		return (Hash[hashFunction(data)].insert(data));
		// ������������ �������� ����������� �������� ���-�������
	};

	//--------- �������� �������� ---------
	bool Object::deleteByData(void* data) 
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};

	//-------- ����� �������� --------
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};

	//--------- ����� ��������� ���-������� ---------
	void Object::Scan() 
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			std::cout << '\n';
		}
	};
}


#include "stdafx.h"
#include "Hash.h"
#include "List.h"
#include <iostream>
#include "stdio.h"
#include <sstream>
namespace hashTC
{
	Object create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	}
	int Object::hashFunction(void* data)
	{
		unsigned char Rand8[256];
		for (int i = 0; i < 256; i++)
			Rand8[i] = rand() % 256;
		int q = FunKey(data);
		char* str = new char[20];
		//sprintf(str, "%d", q);
		unsigned char h = 0;
		while (*str)
			h = Rand8[h ^ *(str)++];
		return h;
	};
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			//std::cout << std::endl;
		}
		std::cout << std::endl;
	};
}

#pragma once
#include "List.h"
namespace hashTC
{
	struct Object
	{
		int size;
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object(int sz, int(*f)(void*))
		{
			size = sz;
			FunKey = f;
			Hash = new listx::Object[size];
		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
	};
	Object create(int size, int(*f)(void*));
}

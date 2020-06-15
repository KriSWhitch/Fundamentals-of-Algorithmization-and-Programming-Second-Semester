#include "stdafx.h"
#include "HashTwinChain.h"
#include "Lists.h"
#include <iostream>


namespace hashTC
{
	//------- Создание хеш-таблицы ------- 
	Object create(int size, int(*f)(void*)) 
	{
		return *(new Object(size, f)); // Выделяем память
	}

	//-------- Универсальная хеш-функция --------
	int Object::hashFunction(void* data) // data -передаваемый ключ
	{
		int key = FunKey(data);
		int p = 10000;
		int a = 9995;
		int b = 9992;
		int hash_key = (int)(((a * key + b) % p) % size);
		return hash_key;
	};

	//--------- Вставка элемента ---------
	bool Object::insert(void* data) 
	{
		return (Hash[hashFunction(data)].insert(data));
		// Вставляемому элементу присваиваем значение хеш-функции
	};

	//--------- Удаление элемента ---------
	bool Object::deleteByData(void* data) 
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};

	//-------- Поиск элемента --------
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};

	//--------- Вывод элементов хеш-таблицы ---------
	void Object::Scan() 
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			std::cout << '\n';
		}
	};
}

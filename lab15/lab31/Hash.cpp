#include "Hash.h"
#include <iostream>


////--------- Хеш-функция (по умолчанию) ---------
//int HashFunction(int key, int size, int p)    
//{
//	double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
//	return (p + key) % size;
//}


//-------- Новые функции --------


//-------- Модульное хеширование --------
//int HashFunction(int key, int size, int p)
//{
//	return (key % size);
//}

////------- Универсальное хеширование -------
int HashFunction(int key, int size, int p)
{
	p = 8888899;
	int a = 8888893;
	int b = 8888890;
	return (int)(((a * key + b) % p) % size);
}

//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}

//---------- Выделение памяти для хеш-таблицы ----------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}

//------------ Конструктор ------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size; // Текущий размер таблицы
	this->getKey = getkey; // Ключ
	this->data = new void* [size]; // Хранимая строка
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}

//------ Вставака пары ключ - строковое значение ------
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); // j - индекс элемента в хеш-таблице
			i != size && !b;  j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL) // Если у нас в массиве есть пустое место:
				// это место содержит либо NULL(Пусто), либо метку DEL(Удалён)
			{
				data[j] = d; // В данном случае индексом будет выступать значение хеш-функции
				// В элементе с этим индексом будет храниться пара ключ-значение
				N++;
				b = true;
			}
	return b;
}

//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}

//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}

//--------- Удаление по ключу ---------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}

//------ Удалить по значению ------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}

//------------ Вывод массива ------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент [" << i << "]";
		if ((this->data)[i] == NULL)
			std::cout << "  Пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  Удален" << std::endl;
			else
				f((this->data)[i]);
	}
}


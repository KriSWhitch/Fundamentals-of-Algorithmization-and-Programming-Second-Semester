#pragma once
#include "Lists.h"
namespace hashTC
{
	// ���-�������
	struct Object
	{
		// ������ �������
		int size;
		int(*FunKey)(void*);
		// ���
		listx::Object* Hash;
		// �����������
		Object(int size, int(*f)(void*))
		{
			this->size = size;
			FunKey = f;
			Hash = new listx::Object[size];
		};

		// ���-�������
		int hashFunction(void* data);
		// ���������� (���������� �������� "���������"-"�� ���������")
		bool insert(void* data);
		// �����
		listx::Element* search(void* data, int& index);
		// �����
		listx::Element* search(void* data, int& index, int& cmp);
		// �������� �� ������
		bool deleteByData(void* data);
		// ����� ������� �� �����
		void Scan();
	};
	// �������� �������
	Object create(int size, int(*f)(void*));
}
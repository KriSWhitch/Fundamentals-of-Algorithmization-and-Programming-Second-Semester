#pragma once
//--------------- �������� ��������� � ��������� �������
#include "stdafx.h"
struct Queue
{
	char info; // �����-�� ������
	Queue* next; // ��������� �� ��������� ������� �������
};
void createQueue(Queue** begin, Queue** end, char p); // ������������ ��������� �������
void viewQueue(Queue* begin); // ����� ��������� ������� 
void insertInQueue(Queue** begin, Queue** end, char p, int max_size); // ���� ������ �������� � ����� �������
int QueueSize(Queue* begin); // ������ �������


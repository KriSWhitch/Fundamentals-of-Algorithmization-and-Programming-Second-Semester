#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Number
{
	float info;
	Number *next;
};

void create(Number **begin, Number **end, float p); //������������ ��������� �������

void view(Number *begin); //������� ������ ��������� ������� 

Number * maxElem(Number *begin); //������� ����������� ������������ �������� 
 
void CyclycShift(Number ** begin, Number ** end, Number * newBeginOfQueue);
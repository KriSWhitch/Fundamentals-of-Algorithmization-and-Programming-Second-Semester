#pragma once

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
struct StackEl
{
	char w;               // символьный элемент 
	int data;             //информационный элемент
	StackEl *head;		 //вершина стека 
	StackEl *next;		 //указатель на следующий элемент
};
struct stack
{
	int data;
	stack *next;
};

int pop(stack* &st); // Извлечение элемента

void push(stack* &st, int d); // Добавление элемента

void clear(stack* &st);

void deleteNeKrat3(stack *&st);

void writeStackToFile(string filename, stack*&st);

void readStackFromFile(string filename, stack*&st);

void switch_word();

void push_w(char x, StackEl *myStk);

char pop_w(StackEl *myStk);

struct lists {
	lists *next;
	int id;
	int length;
	lists *prev;
	lists(lists *n, int num, int l, lists *p) {
		next = n;
		id = num;
		length = l;
		prev = p;
	}
};

struct operate {
	lists *head;
	operate() {
		head = NULL;
	}
	void read();
	void print();
};

operate create();
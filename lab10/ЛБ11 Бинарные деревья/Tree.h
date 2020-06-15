#pragma once
//-------------- ������ ------------
struct Tree          
{
	int key;  //����
	char text[5]; //����� - �� ����� 4 ����
	Tree *Left, *Right; // ��������� �� ����� � ������ �����
};

Tree* makeTree(Tree *Root);       //�������� ������
Tree* list(int i, char *s);       //�������� ������ ��������
Tree* insertElem(Tree *Root, int key, char *s);  //���������� ������ ��������
Tree* search(Tree* n, int key);   //����� �������� �� ����� 
Tree* delet(Tree *Root, int key); //�������� �������� �� �����
void view(Tree *t, int level);    //����� ������ 
int count(Tree *t, char letter);  //������� ���������� ����
void delAll(Tree *t);             //������� ������
int ClosestVetvi(Tree *t, int find_key); // ����� ����� ������ � ����� ������ �� ����� �� ��������� �������
int Vetvi(Tree *t); // ����� ������
// ��� ������� 1
int LeafCount(Tree *t); // ���������� ������� �� ������
// ��� ������� 2
int ChetnieYzli(Tree *t); // ����������� ����� � ������� �������
// ��� ������� 3
int amount_right_side(Tree *t); // ���������� ����� ������ �����


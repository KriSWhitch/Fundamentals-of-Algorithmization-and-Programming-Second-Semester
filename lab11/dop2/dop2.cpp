#include <iostream>
#include<fstream>
#include <math.h>
using namespace std;

/*Дано N чисел, N > 0. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а
правая дочерняя вершина является внутренней. Для каждой внутренней вершины вначале создавать левую дочернюю вершину, а
затем правую (если она существует); каждой создаваемой вершине присваивать очередное значение из исходного набора.*/

struct tree
{
	int key;
	int data;
	tree* left, * right;
};
int choice; int index = 0;
tree* p1 = NULL;
void maketree(tree** t, int arr[])
{

	if (*t == NULL)
	{
		*t = new tree;
		(*t)->data = arr[index];
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (arr[index] > (*t)->data)
		maketree(&(*t)->right, arr);
	else
		maketree(&(*t)->left, arr);

}
void print(tree* t, int u)
{
	if (t == NULL) return;
	else
	{
		print(t->left, ++u);
		for (int i = 0; i < u; i++)
		{
			cout << "  ";
		}
		cout << t->data << endl;

	}
	print(t->right, ++u);
}




int main()
{
	int N = 8;
	int arr[] = { 5,4,6,2,11,1,3,7 };
	for (int i = 0; i < N; i++)
	{
		maketree(&p1, arr);
		index++;
	}

	print(p1, 0);
}
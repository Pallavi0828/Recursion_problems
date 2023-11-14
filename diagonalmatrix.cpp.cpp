#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};
void create(int A[], int n,Node *first)
{
	Node* last;
	first->data = A[0];
	first->next = NULL;
	last = first;
	for (int i = 0; i < n; i++)
	{
		Node* temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}

}

void display(Node* first)
{
	while (first)
	{
		cout << first->data << " ";
		first = first->next;
	}
}

Node* Lsearch(Node* first, int key)
{
	while (first)
	{
		if (first->data == key)
			return first;
		first = first->next;
	}
}
int main()
{
	Node* first;
	int key;
	int A[7] = { 1,2,3,4,5,6,7};
	first = new Node;
	create(A, 6,first);
	display(first);
	cout << "enter the key element to search" << endl;
	cin >> key;
	Node* temp;
	temp = Lsearch(first, key);
	if (temp)
		cout << "key is found" << temp << endl;
	else
		cout << "key is not found" << endl;
	return 0;
}

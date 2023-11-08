#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Diagonal
{
private:
	int n;
	int* A;
public:
	Diagonal()
	{
		n=2;
      A=new int[2];
	}
	Diagonal(int num)
	{
		n=num;
		A=new int[n];
	}
	~Diagonal(){
		delete []A;
	}
	void set(int i, int j,int x);
	int get(int i, int j);
	void display();
	
};
void Diagonal::set(int i, int j, int x)
{
	if (i == j)
		A[i - 1] = x;

}
int Diagonal::get(int i, int j)
{
	if (i == j)
		return A[i - 1];
	return 0;
}
void Diagonal::display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				cout << A[i] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}
int main()
{
	Diagonal d(5);
    d.set(1,1,3);
	d.set(2,2,6);
	d.set(3,3,9);
	d.set(4,4,1);
	d.set(5,5,7);
	
	d.display();
	return 0;
}

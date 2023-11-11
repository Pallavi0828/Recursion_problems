#include <iostream>
using namespace std;
int merge(int a[],int b[],int m,int n)
{
    
    int *c;
    c=new int[m+n];
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    for(;i<m;i++)
    {
        c[k]=a[i];
    }
    for(;j<n;j++)
    {
        c[k]=b[j];
    }
  for(int h=0;h<m+n;h++)
  {
      cout<<c[h];
  }
  return 0;
}

int main()
{
    cout<<"enter no.of element of array 1 &2"<<endl;
    int m,n;
    cin>>m>>n;
    
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    merge(a,b,5,5);
    return 0;
}
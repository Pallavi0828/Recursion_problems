#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
  /*  int *b;
    b=new int[n];
    for(int i=0,j=n-1;i<n;i++,j--)   // time is o(n) ..two loops are one after other so n+n
    {
       b[i]=a[j];
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;*/
    for(int i=0,j=n-1;i<n;i++,j--)   //another method to reverse array without auxillary array
    {
        int temp;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        cout<<a[i]<<" ";
    }
    return 0;
}
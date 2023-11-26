// printing subsequence whose sum is k

//Method 2: (slight difference from method one)
#include <iostream>
#include <vector>
using namespace std;


void subseqSumK(int index,vector<int> vect,int curr_sum,int sum,int arr[],int n){
   
if(index==n){
    if(curr_sum==sum){
        for(auto it:vect)  cout<<it<<" ";
        cout<<endl;
    }
    return;
}
//take
vect.push_back(arr[index]);
curr_sum+=arr[index];
subseqSumK(index+1,vect,curr_sum,sum,arr,n);

//not take
vect.pop_back();
curr_sum-=arr[index];
subseqSumK(index+1,vect,curr_sum,sum,arr,n);

}

int main(){
    int arr[]={1,2,1};
    int sum=2,index=0,curr_sum=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect;
    subseqSumK(index,vect,curr_sum,sum,arr,n);
    return 0;
}


/*
////////method 1:///////////
void subseq(int arr[], int n, int index, vector<int> v, int k)
{
    if (index >= n)
    {
        int sum = 0;
        for (auto ele : v)
        {
            sum += ele;
        }
        if (sum == k)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        return;
    }
    v.push_back(arr[index]);
    subseq(arr, n, index + 1, v, k);
    v.pop_back();
    subseq(arr, n, index + 1, v, k);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int k = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subseq(arr, n, 0, v, k);

    return 0;
}
*/


// Count the subsequences with the sum K

#include <iostream>
#include <vector>
using namespace std;

int subseqSumOne(int index,int curr_sum,int sum,int arr[],int n){


//condtion not satisfied
// strictly done if array contains positives only.
  if(curr_sum>sum) return 0; //this is the extra base case to reduce time slightly(optional)
if(index==n){
    //condition satisfied
    if(curr_sum==sum)  return 1;

    // Condition not satisfied
    else return 0;    
}

//take

curr_sum+=arr[index];
int l=subseqSumOne(index+1,curr_sum,sum,arr,n);

//not take

curr_sum-=arr[index];
int r=subseqSumOne(index+1,curr_sum,sum,arr,n);

return l+r;
}


int main(){
    int arr[]={1,2,1};
    int sum=2,index=0,curr_sum=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<subseqSumOne(index,curr_sum,sum,arr,n);
    return 0;
}


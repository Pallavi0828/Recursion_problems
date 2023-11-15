// Printing any ONE subsequences whose sum is K

#include <iostream>
#include <vector>
using namespace std;

bool subseqSumOne(int index,vector<int> vect,int curr_sum,int sum,int arr[],int n){
   
if(index==n){
    //condition satisfied
    if(curr_sum==sum){
        for(auto it:vect)  cout<<it<<" ";
        cout<<endl;
        return true;
    }
    // Condition not satisfied
    else{
    return false;
    }
    
}


//take
vect.push_back(arr[index]);
curr_sum+=arr[index];
if(subseqSumOne(index+1,vect,curr_sum,sum,arr,n)==true)
return true;

//not take
vect.pop_back();
curr_sum-=arr[index];
if(subseqSumOne(index+1,vect,curr_sum,sum,arr,n)==true)
return true;

return false;

}

int main(){
    int arr[]={1,2,1};
    int sum=2,index=0,curr_sum=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect;
    subseqSumOne(index,vect,curr_sum,sum,arr,n);
    return 0;
}


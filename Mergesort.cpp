#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vect,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high ){
       if(vect[left]<=vect[right]){
       temp.push_back(vect[left]);
       left++;
       }
       else {
        temp.push_back(vect[right]);
        right++;
       }
    }

    while(left<=mid){
        temp.push_back(vect[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(vect[right]);
        right++;
    }  
  int dummy=temp[low];
   for(int i=low;i<=high;i++){
    vect[i]=temp[i-low];        //If you stuck again here...debug and clear question
   }

}

void mergesort(vector<int> &vect,int low,int high){
    if(low>=high){
       return;
    }
    int mid=(low+high)/2;
        mergesort(vect,low,mid);
        mergesort(vect,mid+1,high);
        merge(vect,low,mid,high);
    
}


int main(){
    vector<int> vect={3,4,2,1,8,6,3,2,0};
    int n=vect.size();
    mergesort(vect,0,n-1);
    for(auto it: vect){
        cout<<it<<" ";
    }
    return 0;
}
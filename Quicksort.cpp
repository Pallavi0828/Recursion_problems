
// Quick Sort algorithm

#include <iostream>
#include <vector>
using namespace std;

//////  Taking 1st element as a pivot.//////////
/*
int partfunction(vector<int> &vect, int low,int high){
  int pivot=vect[low];
  int i=low;
  int j=high;
  while(i<j){
    while(vect[i]<=pivot && i<=high-1){
        i++;
    }

    while(vect[j]>pivot && j>=low+1){
        j--;
    }
    if(i<j){
        swap(vect[i],vect[j]);
    }
  }
  swap(vect[low],vect[j]);
  return j;
}
*/


//////// Taking last element as a pivot ////////////
int partfunction(vector<int> &vect, int low,int high){
    int pivot=vect[high];
    int insertion_pt=low;

    for(int i=low;i<=high;i++){
        if(vect[i]<pivot){
           swap(vect[i],vect[insertion_pt]);  
           insertion_pt++;
        }  
    }
    swap(vect[high],vect[insertion_pt]);
    return insertion_pt;
}


void quicksort(vector<int> &vect,int low,int high){

    if(low<high){
   int partition=partfunction(vect,low,high);
   quicksort(vect,low,partition-1);
   quicksort(vect,partition+1,high);
    }
}

int main(){
    vector<int> vect={4,6,2,5,7,9,5,6};
     int n=vect.size();
     quicksort(vect,0,n-1);

     for(auto it:vect){
        cout<<it<<" ";
     }
     return 0;
}


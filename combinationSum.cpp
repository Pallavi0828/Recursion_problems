/*
Cobination Sum 
problem statement- Given an array of distinct integers 'canditates' and target integer 'target' return a list of all unique combinations of candidates where the choosen numbers sum to target. You may return in any order.
** same number may be choosen from candidates an unlimited of times.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void combinationsum(int index, int target, vector<int> &temp, vector<int> &arr, vector<vector<int>> &ans){
  if(index==arr.size()){
    if(target==0){
      ans.push_back(temp);
    }
    return;
  }
  
  if(arr[index]<=target){
    temp.push_back(arr[index]);
    combinationsum(index, target-arr[index], temp, arr, ans);
    temp.pop_back();
  }

  combinationsum(index+1, target, temp, arr, ans);
}

int main(){
  vector<int> arr={2,3,5},temp;
  int target=8;
  vector<vector<int>> ans;
  combinationsum(0,target,temp,arr,ans);
  for(auto it: ans){
    for(auto i: it){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
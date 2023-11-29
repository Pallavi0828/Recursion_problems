/*
Combination Sum
problem statement- Given collection of candidate numbers 'candidates' and target integer 'target'. Find all unique combinations of candidates where the choosen numbers sum to target.
Each number in candidates may only be used once in combination.
Note: Solution must not contain duplicate combinations

Input: candidates=[1,1,1,2,2] target=4
output:[[1,1,2] [2,2]]
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void Combination_SumII(int index, int target, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break; // array is already sorted, so definitely all the element next in the array will be greater and not makes upto target
        ds.push_back(arr[i]);
        Combination_SumII(i + 1, target - arr[i], ds, arr, ans);
        ds.pop_back();
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1}, ds;
    int target = 4;
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    Combination_SumII(0, target, ds, arr, ans);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
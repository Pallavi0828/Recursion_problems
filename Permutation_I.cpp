// Permutations

// Given an array (arr) of distinct integers, return all the possible permutations
// you can return the answer in any order

// ex: arr=[1,2,3]
//  O/P: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

#include <bits/stdc++.h>
using namespace std;

void permutations(vector<int> &arr, vector<int> &ds, int freq[], vector<vector<int>> &ans)
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!freq[i])
        {
            ds.push_back(arr[i]);
            freq[i] = 1;
            permutations(arr, ds, freq, ans);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()] = {0};
    permutations(arr, ds, freq, ans);
    for (auto it : ans)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
// Another efficient method to find all permutations in the given list of elements
// Using swapping and recursion without extra space

#include <bits/stdc++.h>
using namespace std;

void permutations(int index, vector<int> &arr, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        permutations(index + 1, arr, ans);
        swap(arr[index], arr[i]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;

    permutations(0, arr, ans);
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
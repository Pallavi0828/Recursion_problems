// SUBSET SUM I

// Given list(arr) of N integers, print sums of all subsets in it
// output should be printed in increasing order of sums.

#include <bits/stdc++.h>
using namespace std;

void subsetsum(int index, int sum, vector<int> &arr, vector<int> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(sum);
        return;
    }

    // Pick the element
    subsetsum(index + 1, sum + arr[index], arr, ans);

    // Not pick the element
    subsetsum(index + 1, sum, arr, ans);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ans;
    subsetsum(0, 0, arr, ans);
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
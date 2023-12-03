// SUBSET II

// Given integer array(nums) that may contain duplicates.return all posiible subsets(powerset)
// The solution set must not contain duplicate subsets. return solution in any order.

#include <bits/stdc++.h>
using namespace std;

void findSubsets(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (int i = index; i <= nums.size() - 1; i++)
    {
        if (i != index && nums[i] == nums[i - 1])
        {
            continue;
        }
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 3};
    sort(nums.begin(), nums.end()); // always first sort given array
    vector<int> ds;
    vector<vector<int>> ans;
    findSubsets(0, nums, ds, ans);
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
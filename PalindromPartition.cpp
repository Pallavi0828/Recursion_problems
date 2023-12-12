
/*
Given a string s, partition s, such that every substring of the partition is a palindrome. return all possible palindrome partitioning of s. A palindrome string is a string that reads the same backward as forward.

example: Input: s= "aa"
output: [["a","a","b"],["aa","b"]]


*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int start, int end, string s)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void palindromPartition(string s, int index, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); ++i)
    {
        if (isPalindrome(index, i, s))
        {
            path.push_back(s.substr(index, (i - index + 1)));
            palindromPartition(s, i + 1, path, res);
            path.pop_back();
        }
    }
}

int main()
{
    string s = "aabb";
    vector<vector<string>> res;
    vector<string> path;

    palindromPartition(s, 0, path, res);
    for (auto it : res)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

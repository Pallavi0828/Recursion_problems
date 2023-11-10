#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getydiff(vector<int> &a, vector<int> &b)
{
    // return a[0] - b[0];
    return a[1];
}
int getxdiff(vector<int> &a, vector<int> &b)
{
    return a[1] - b[1];
}
bool checkStraightLine(vector<vector<int>> &coordinates)
{

    int deltaX = getydiff(coordinates[1], coordinates[0]);
    cout << deltaX;
    // int deltay = getydiff(coordinates[1], coordinates[1]);

    for (int i = 2; i < coordinates.size(); i++)
    {
    }
}

int main()
{

    vector<vector<int>> vect = {
        {1, 2}, {2, 3}, {3, 4}, {4, 5}};

    if (checkStraightLine(vect))
    {
        // cout << "true" << endl;
    }
    else
        // cout << "false" << endl;
        return 0;
}
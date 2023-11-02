// printing subsequences of the given array using recursion.

#include <iostream>
#include <vector>
using namespace std;

void subseq(int arr[], int n, int index, vector<int> v)
{
    if (index >= n)
    {
        for (auto ele : v)
        {
            cout << ele << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[index]);
    subseq(arr, n, index + 1, v);
    v.pop_back();
    subseq(arr, n, index + 1, v);
}

int main()
{
    int arr[] = {3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    subseq(arr, n, 0, v);

    return 0;
}
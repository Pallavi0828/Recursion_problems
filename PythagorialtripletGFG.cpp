//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        
        // METHOD 1........................................................

        //  unordered_map<int,int> mp;

        //     for(int i=0;i<n;i++){

        //         mp[arr[i]*arr[i]]++;
        //     }

        //     for(int i=0;i<n;i++){

        //         mp[arr[i]*arr[i]]--;

        //         for(int j=i+1;j<n;j++){

        //             mp[arr[j]*arr[j]]--;

        //             int a=arr[i]*arr[i],b=arr[j]*arr[j];

        //             if(mp[a+b] > 0)return true;

        //             mp[arr[j]*arr[j]]++;
        //         }

        //         mp[arr[i]*arr[i]]++;
        //     }

        //     return false;
        // This code exceeds time limit....

        // METHOD 2...........................................................
        //  set<int> s;
        // for(int i=0;i<n;i++){
        //     arr[i]=(arr[i])*(arr[i]);
        //     s.insert(arr[i]);
        // }

        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(s.find(arr[i]+arr[j])!=s.end()){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        
        // METHOD 3................................................................

        // Efficient solution:

        int maximum = 0;

        // Find the maximum element
        for (int i = 0; i < n; i++)
        {
            maximum = max(maximum, arr[i]);
        }

        // Hashing array
        vector<int> hash(maximum + 1, 0);

        // Increase the count of array elements
        // in hash table
        for (int i = 0; i < n; i++)
            hash[arr[i]]++;

        // Iterate for all possible a
        for (int i = 1; i < maximum + 1; i++)
        {

            // If a is not there
            if (hash[i] == 0)
                continue;

            // Iterate for all possible b
            for (int j = 1; j < maximum + 1; j++)
            {

                // If a and b are same and there is only one a
                // or if there is no b in original array
                if ((i == j && hash[i] == 1) || hash[j] == 0)
                    continue;

                // Find c
                int val = sqrt(i * i + j * j);

                // If c^2 is not a perfect square
                if ((val * val) != (i * i + j * j))
                    continue;

                // If c exceeds the maximum value
                if (val > maximum)
                    continue;

                // If there exists c in the original array,
                // we have the triplet
                if (hash[val])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}

// } Driver Code Ends

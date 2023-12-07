// Efficient approach(Hashing)
/*
The N queen is the problem placing n queens on an NxN chessboard such that no two queens attack each other.
Given an integer N, return all distinct solutions to the N queen puzzle
Ex: n=4
 output: [[ ".Q.." , "...Q" , "Q..." , "..Q." ] , [ "..Q." , "Q..." , "...Q" , ".Q.." ]]

 RULES TO PLACE A QUEEN
 1) Every row should have 1 queen
 2) Every column should have 1 Queen
 3) None of the queen should attack each other(Queen can attack in all directions(8))
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && upperDiagonal[row + col] == 0 && lowerDiagonal[(n - 1) + (col - row)] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[(n - 1) + (col - row)] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[(n - 1) + (col - row)] = 0;
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n); // declaring n number of string arrays
    string s(n, '.');
    for (int i = 0; i < n; i++)
    { // filling each string array with empty '.'
        board[i] = s;
    }

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1);

    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << endl;
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

// Space Complexity: O(N)
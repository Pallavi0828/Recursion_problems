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

bool isSafe(int row, int col, vector<string> &board, int n)
{

    int duprow = row;
    int dupcol = col;

    // checking upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;
    // checking left row
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;

    // checking lower diagonal

    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {

            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
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
    solve(0, board, ans, n);

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

// Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O

// (N! * N) nearly.

// Space Complexity: O(N^2)
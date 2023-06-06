#include <bits/stdc++.h>
using namespace std;

// Brute Force -> We can first make the rows can col having 0 = -1, and then 0.
void markRow(int i, vector<vector<int>> &matrix) {
    for (int j = 0 ; j < matrix[i].size() ; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void markCol(int j, vector<vector<int>> &matrix) {
    for (int i = 0 ; i < matrix.size() ; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void setZeros(vector<vector<int>> &matrix)
{
    for (int i = 0 ; i < matrix.size() ; i++) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            if (matrix[i][j] == 0) {
                markRow(i, matrix);
                markCol(j, matrix);
            }
        }
    }
    for (int i = 0 ; i < matrix.size() ; i++) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}
// Time Complexity -> O(n*m)*O(n+m) + O(n*m) = O(n^3)

// Better Sol: 
void setZeros(vector<vector<int>> &matrix)
{
	int row[matrix.size()] = {0};
    int col[matrix[0].size()] = {0};
    for (int i = 0 ; i < matrix.size() ; i++) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            if (matrix[i][j] == 0) {
                row[i] = -1;
                col[j] = -1;
            }
        }
    }
    for (int i = 0 ; i < matrix.size() ; i++) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            if (row[i] == -1 || col[j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}
// Time -> O(2*n*m)
// Space -> O(n) + O(m)

// Optimal Solution
void setZeros(vector<vector<int>> &matrix)
{
	int col0 = 1;
    for (int i = 0 ; i < matrix.size() ; i++) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            if (matrix[i][j] == 0) {
                // mark the ith row -> 0
                matrix[i][0] = 0;
                // mark the ith col -> 0
                if (j != 0) 
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1 ; i < matrix.size() ; i++) {
        for (int j = 1 ; j < matrix[0].size() ; j++) {
            if (matrix[i][j] != 0) {
                // Check for cols and rows
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    // when will 1st row be 0
    if (matrix[0][0] == 0) {
        for (int j = 0 ; j < matrix[0].size() ; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0 ; i < matrix.size() ; i++) {
            matrix[i][0] = 0;
        }
    }
}
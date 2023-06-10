#include <bits/stdc++.h>
using namespace std;

// Leetcode
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        // 1. Transpose the Matrix
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. Reverse Every Row of the Matrix
        for (int i = 0 ; i < row ; i++) {
            for (int j = 0 ; j < col/2 ; j++) {
                swap(matrix[i][j], matrix[i][col - j - 1]);
            }
        }
    }
};

// Conding Ninjas:
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
}
// Brute Approach -> For each element check the number of elements greater than it on the right side -> O(N^2)
// Better Approach -> Check the Row in which the element can be present, Binary Search in that row -> O(NlogM)
// Optimal Approach -> Start from the top right corner, if target is greater than the current element, move down, else move left -> O(N+M)

#include <bits/stdc++.h>
using namespace std;

// Better Leetcode & Coding Ninjas:
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int index = -1;
    for (int i = 0 ; i < n ; i++) {
        if (target == mat[i][0]) {
            return true;
        }
        if (target > mat[i][0] && i == n-1) {
            index = i;
            break;
        }
        if (target > mat[i][0] && target < mat[i+1][0]) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // Binary Search
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (mat[index][mid] == target) {
                return true;
            }
            else if (mat[index][mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return false;   // index == -1 || target not found
}

// Optimal GFG:
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m - 1;  // top right corner
    while (i < n && j >= 0) {
        if (mat[i][j] == target) {
            return true;
        }
        else if (target < mat[i][j]) {
            j--;
        }
        else {      // target > mat[i][j]
            i++;
        }
    }
    return false;       // element not found in the matrix
}

// Optimal Leetcode & Coding Ninjas:
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = n * m - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == target) {
            return true;
        }
        else if (target < mat[row][col]) {
            high = mid - 1;
        }
        else {  // target > mat[row][col]
            low = mid + 1;
        }
    }
    return false;   // element not found in the matrix
}
// Time Complexity -> O(log (N * M))
// Space Complexity -> O(1)

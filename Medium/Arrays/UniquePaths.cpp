// Grid Unique Paths: GOOGLE Interview Question
// Brute Force -> Recursion: Time -> O(2^(m+n)) Space -> O(m+n)

#include <bits/stdc++.h> 
using namespace std;

// Brute Force -> Recursion: Time -> O(2^(m+n)) Space -> O(m+n)
void countWays(int m, int n, int i, int j, int &count) {
    if (i == m-1 && j == n-1) {
        count++;
        return;
    }
    if (i >= m  || j >= n) {
        return;
    }
    // Move Right:
    countWays(m, n, i+1, j, count);
    // Move Down:
    countWays(m, n, i, j+1, count);
}
int uniquePaths(int m, int n) {
	int count = 0;
    countWays(m, n, 0, 0, count);
    return count;
}

// Better -> Recursion + Memoization: Time -> O(m*n) Space -> O(m*n)  =>  DP
int countPaths(int m, int n, int i, int j, vector<vector<int>> &dp) {
    if (i == m-1 && j == n-1) {
        return 1;
    }
    if (i >= m  || j >= n) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    return dp[i][j] = countPaths(m, n, i+1, j, dp) + countPaths(m, n, i, j+1, dp);      // Move Down + Move Right
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp;
    return countPaths(m, n, 0, 0, dp);
}

// Optimal -> PnC -> (m+n-2)C(m-1) or (m+n-2)C(n-1) : Time -> O(m+n) Space -> O(1)
int uniquePaths(int m, int n) {
    int N = m+n-2;  // Total Steps
    int r = m-1;    // Steps Down or Right
    double res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (N-r+i)/i;
    }
    return (int) res;
}
// Time -> O(m+n)
// Space -> O(1)
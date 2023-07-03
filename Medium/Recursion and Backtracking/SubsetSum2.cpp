#include <bits/stdc++.h> 
using namespace std;

// Brute Force:
void FindSubsets(int n, int i, vector<int> &arr, vector<int> subset, set<vector<int>> &St) {
    if (i == n) {
        sort(subset.begin(), subset.end());
        St.insert(subset);
        return;
    }
    // include:
    subset.push_back(arr[i]);
    FindSubsets(n, i+1, arr, subset, St);

    // Do not include:
    subset.pop_back();
    FindSubsets(n, i+1, arr, subset, St);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> St;
    vector<int> subset;
    FindSubsets(n, 0, arr, subset, St);
    vector<vector<int>> ans;
    for (auto it: St) {
        ans.push_back(it);
    }
    return ans;
}

// Optimal:
void FindSubsets( int ind, vector<int> &arr, vector<int> subset, vector<vector<int>> &ans) {
    ans.push_back(subset);      // O(N)
    for (int i = ind ; i < arr.size() ; i++) {
        if (i != ind && arr[i] == arr[i-1]) {
            continue;
        }
        // include:
        subset.push_back(arr[i]);
        FindSubsets(i+1, arr, subset, ans);
        // Do not include:
        subset.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> subset;
    sort(arr.begin(), arr.end());
    FindSubsets(0, arr, subset, ans);
    return ans;
}
// Time Complexity: O(2^n * n)
// Space Complexity: O(2^n)
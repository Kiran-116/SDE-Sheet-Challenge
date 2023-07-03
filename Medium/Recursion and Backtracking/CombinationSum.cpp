#include <bits/stdc++.h>
using namespace std;

void FindSubsetSum(int i, int n, vector<int> arr, vector<int> &subset, vector<vector<int>> &ans, int sum, int K) {
    if (i == n && sum == K) {
        ans.push_back(subset);
        return;
    }
    else if (i == n) {
        return;
    }
    // Include:
    subset.push_back(arr[i]);
    FindSubsetSum(i+1, n, arr, subset, ans, sum + arr[i], K);
    // Do not Include:
    subset.pop_back();
    FindSubsetSum(i+1, n, arr, subset, ans, sum, K);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> subset;
    sort(ans.begin(), ans.end());
    FindSubsetSum(0, n, arr, subset, ans, sum, k);
    return ans;
}
// Time -> O(2^N * K)
// Space -> O(K * X)


// Leetcode:
class Solution {
    void findCombination (int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            // drop the element
            ds.pop_back();
        }

        findCombination(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;         // Data Structure
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
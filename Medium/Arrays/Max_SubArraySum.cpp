#include <bits/stdc++.h>
using namespace std;

// Coding Ninjas
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN;
    long long sum = 0;
    for (int i = 0 ; i < n ; i++) {
        if (sum + arr[i] > 0) {
            sum += arr[i];
        }
        else {
            sum = 0;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

// Leetcode
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maximumSum = INT_MIN, currSumSubarray = 0;
        for (int i = 0; i < n; i++) {
            currSumSubarray += nums[i]; 
            maximumSum = max(maximumSum, currSumSubarray);
            
            currSumSubarray = max(currSumSubarray, 0);
        } 
        return maximumSum;
    }
};

// Time -> O(N)
// Space -> O(1)
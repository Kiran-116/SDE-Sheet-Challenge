// Longest Subarray with Sum K
// Brute -> Check for each subarray, if its sum is equal to k or not Time -> O(N^3), Space -> O(1)
// Brute -> Generate all subarrays -> O(N^2)

// Better -> Hashing
// If there exists a subarray with sum k, as (.) as the last element

// Optimal: 2 Pointer and Greedy Approach

#include <bits/stdc++.h>
using namespace std;

// Better: This is only true for Positive Numbers:
// Optimal: for +ve and -ve numbers.
int LongestSubsetWithZeroSum(vector < int > arr) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    int k = 0;              // Required Sum
    for (int i = 0 ; i < arr.size() ; i++) {
        sum += arr[i];
        if (sum == k) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {    // 0 or negative numbers case solved
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
// If we have 0 as elements then we would not get thr longest subarray with sum 0
// Time -> O(N log N)
// Space -> O(N)

// Optimal: 2 Pointer and Greedy Approach
int LongestSubsetWithZeroSum(vector < int > arr) {
    int left = 0, right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int k = 0;
    int n = arr.size();
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;    // first move to next & then add
        if (right < n) {
            sum += arr[right];
        }
    }
    return maxLen;
}
// Time -> O(2N)
// Space -> O(1)
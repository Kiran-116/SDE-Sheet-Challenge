// Majority Element - I -> freq(element) > n/2
// Brute Force -> O(n^2) -> 2 loops => find count of each element and check if it is greater than n/2
// Better -> O(nlogn) -> Hashing using Map.
// Best -> O(n)

#include <bits/stdc++.h>
using namespace std;

// Better Approach:
int findMajorityElement(int arr[], int n) {
    map<int, int> mpp;
    for (int i = 0 ; i < n ; i++) {
        mpp[arr[i]]++;
    }
    for (auto it: mpp) {
        if (it.second > n/2) {
            return it.first;
        }
    }
    return -1;
}
// Time Complexity -> O(nlogn)
// Space Complexity -> O(n)

// Optimal Approach -> Moore's Voting Algorithm
// 1. Apply Moore's Voting Algorithm to find the candidate for majority element.
// 2. Check if the candidate is actually a majority element -> Verify.
// 3. Return the candidate.
int findMajorityElement(int arr[], int n) {
    int count = 0;
    int element;
    // Moore's Voting Algorithm:
    for (int i = 0 ; i < n ; i++) {
        if (count == 0) {
            element = arr[i];
            count = 1;
        }
        else if (element == arr[i]) {
            count++;
        }
        else {      // element != arr[i]
            count--;
        }
    }
    // Verifying:
    int verifyCount = 0;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == element) {
            verifyCount++;
        }
    }
    if (verifyCount > n/2) {
        return element;
    }
    return -1;
}
// Time -> O(n)
// Space -> O(1)
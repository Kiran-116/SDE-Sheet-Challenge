#include <bits/stdc++.h> 
using namespace std;

// Brute -> using 2 loops: for each element, find the max element on its left and right and take the min of them. Subtract the height of the current element from the min of the max elements on its left and right. Add this to the total water trapped.
// Time -> O(n^2), Space -> O(1)
// Better -> using prefixMax anf SuffixMax Array: Time -> O(n), Space -> O(2n)
// Optimal -> using 2 Pointers: Time -> O(n), Space -> O(1)

// Better:
long getTrappedWater(long *arr, int n){
    vector<long> prefixMax(n, 0);
    vector<long> suffixMax(n, 0);
    for (int i = 0 ; i < n ; i++) {
        if (i == 0) {
            prefixMax[i] = arr[i];
        }
        else {
            prefixMax[i] = max(prefixMax[i-1], arr[i]);
        }
    }
    for (int i = n - 1 ; i >= 0 ; i--) {
        if (i == n - 1) {
            suffixMax[i] = arr[i];
        }
        else {
            suffixMax[i] = max(suffixMax[i+1], arr[i]);
        }
    }
    long ans = 0;
    for (int i = 0 ; i < n ; i++) {
        ans += min(prefixMax[i], suffixMax[i]) - arr[i];
    }
    return ans;
}
// Time -> O(n), Space -> O(2n)

// Optimal:
long getTrappedWater(long *arr, int n){
    int left = 0;
    int right = n - 1;
    int totalWater = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= maxLeft) {
                maxLeft = arr[left];
            }
            else {
                totalWater += maxLeft - arr[left];
            }
            left++;
        }
        else {
            if (arr[right] >= maxRight) {
                maxRight = arr[right];
            }
            else {
                totalWater += maxRight - arr[right];
            }
            right--;
        }
    }
    return totalWater;
}
// Time -> O(n), Space -> O(1)
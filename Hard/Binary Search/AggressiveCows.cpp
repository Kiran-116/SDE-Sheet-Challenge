// Aggressive Cows: (Minimum distance between cows) is Maximum:
// Sort the array and then apply binary search on the answer
// Range of Answer: (1, a[n-1] - a[0])

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ) {
        if(stalls[i]-lastPos >= mid) {
            cowCount++;
            lastPos = stalls[i];
        }
        if(cowCount==k) {
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int n = stalls.size();
    int high=stalls[n-1];
    int ans = -1;
    
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(isPossible(stalls, k, mid, n)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;     // ans will be high
}

// Time -> O(NlogN) + O(logN * N)
// Space -> O(1)
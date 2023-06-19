// Count Subarrays with Given XOR k
// Brute: Generate all subarrays and check for XOR -> Time = O(N^3), Space = O(1)
// Better: Make it to 2 loops only -> Time = O(N^2), Space = O(1)

#include <bits/stdc++.h>
using namespace std;

// Optimal: Hash Map
int subarraysXor(vector<int> &arr, int k)
{
    int xr = 0;
    map<int, int> mp;
    mp[xr]++;
    int count = 0;
    for (int i = 0 ; i < arr.size() ; i++) {
        xr = xr ^ arr[i];
        // we are looking for k
        int x = xr ^ k;         // any prev occurance of x
        count += mp[x];
        mp[xr]++;
    }
    return count;
}
// Time -> O(N) or O(N logN)
// Space -> O(N)
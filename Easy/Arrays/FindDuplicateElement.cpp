// Brute Force -> Sort the array and then check for the adjacent elements -> O(NlogN)
// Better -> Hashing -> Freq array -> Space -> O(N), Time -> O(N)
// Optimal -> Linked List Cycle Method -> Tortise METHOD
// 1. Create a slow and fast pointer
// 2. Move slow by 1 step and fast by 2 steps
// 3. When they meet, move slow to the start and fast remains at the meeting point
// 4. Move slow and fast by 1 step each
// 5. When they meet, that is the duplicate element
// Time -> O(N), Space -> O(1)

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0];
	int fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    fast = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

// Time -> O(N)
// Space -> O(1)
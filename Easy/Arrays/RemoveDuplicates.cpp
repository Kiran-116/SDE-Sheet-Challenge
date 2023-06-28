// Remove Duplicate from Sorted Array
#include <bits/stdc++.h>
using namespace std;

// Brute -> using Set-> nlog n for insertion into set : Time -> O(nlogn), Space -> O(n)
// Optimal -> using 2 Pointers: Time -> O(n), Space -> O(1)

int removeDuplicates(vector<int> &arr, int n) {
	int i = 0, j = i+1;
    while (j < n) {
        if (arr[j] == arr[j-1]) {
            j++;
        }
        else {
            arr[i+1] = arr[j];
            i++;
            j++;
        }
    }
    return i+1;     // length of the new array
}
// Time -> O(n)
// Space -> O(1)

// Leetcode: a different but similar approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        while (j <= n-1) {
            if (nums[i] == nums[j]) {
                j++;
            }
            else if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
                j++;
            }
        }
        
        return i+1;
    }
};
// Time -> O(N)
// Space -> O(1)
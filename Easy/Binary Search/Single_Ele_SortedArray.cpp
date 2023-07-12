// Find the Single Element in a Sorted Array
#include <bits/stdc++.h>
using namespace std;

// Pattern -1: Medium
int search(int *arr, int n, int key) {
    int start = 0, end = n - 1, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[start] <= arr[mid]) {
            if (key >= arr[start] && key < arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        else {
            if (key > arr[mid] && key <= arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

// Time -> O(log N)
// Space -> O(1)


// Pattern -2: Easy
int BS_SingleElement(int low, int high, vector<int> &arr, int n) {
	if (low > high) {
		return -1;
	}
	int mid = low + (high-low)/2;
	if (arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
		return arr[mid];
	}
	else if (arr[mid]==arr[mid-1] && mid%2 != 0 || arr[mid]==arr[mid+1] && mid%2 == 0) { 		// odd index
		BS_SingleElement(mid + 1, high, arr, n);
	}
	else {		// even index:
		BS_SingleElement(low, mid-1, arr, n);
	}
}

int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	return BS_SingleElement(0, n-1, arr, n);
}

// Time: O(log n)
// Space: O(1) 	


// Leetcode:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        int st=1,end=n-2;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];

            if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1]) ){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};
// Time: O(log n)
// Space: O(1)
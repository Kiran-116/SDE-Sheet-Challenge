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
	// if (arr[mid] != arr[mid-1] && mid == n-1) {
	// 	return arr[mid];
	// }
	// if (arr[mid] != arr[mid+1] && mid == 0) {
	// 	return arr[mid];
	// }
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
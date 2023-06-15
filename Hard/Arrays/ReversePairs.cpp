// Similar to Count Invresions in an array
// Brute -> Pick up an element and check if it is a majority element or not.    Time -> O(n^2) Space -> O(1)

// Optimal -> 
#include <bits/stdc++.h> 
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;       // temp array
    int left = low;         // starting index of left array
    int right = mid + 1;    // starting index of right array

    // storing elements in the temperory array in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller than left -> inversion
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements are left in the left array
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    // if elements are left in the right array
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // copying the elements from temp array to the original array
    for (int i = low ; i <= high ; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int count = 0;
    int right  = mid + 1;
    for (int i = low ; i <= mid ; i++) {
        while(right <= high && arr[i] > 2 * arr[right]) {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int count = 0;
    if (low >= high) {
        return count;
    }
    int mid = low + (high - low)/2;
    count += mergeSort(arr, low, mid);               // left half
    count += mergeSort(arr, mid + 1, high);          // right half
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);     // merging the two sorted halves
    return count;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr, 0, n - 1);
}

// Time -> O((N + N)* log N) = O(2N logN)
// Space -> O(N)

// And we are distorting the array to optimize space complexity


// Test case on Leetcode:
// [2147483647,2147483647,2147483647,2147483647,2147483647,2147483647]

// Leetcode:
/*

    Time Complexity : O(NlogN), Each recursive call to performs two recursive calls on subslices of size N/2 and
    One linear scans of length <= N. Therefore, the time complexity of the divide & conquer approach can be
    represented by the following recurrence relation: T(N)=2T(N/2)+N. Where N is the size of the Array(nums).

    Space Complexity : O(N), Recursion Stack Space O(logN) + Array(temp) space O(N). 

    Solved using Array + Divide and Conquer + Merge Sort. Optimized Approach.

*/


/***************************************** Approach 2 *****************************************/

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};
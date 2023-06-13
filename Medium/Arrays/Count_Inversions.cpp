// i < j && arr[i] > arr[j] -> Inversion
// Brute Approach -> For each element check the number of elements greater than it on the right side -> O(N^2)
// Optimal Approach -> Merge Sort -> O(NlogN)

#include <bits/stdc++.h> 
using namespace std;

int merge(long long int arr[], int low, int mid, int high) {
    vector<int> temp;       // temp array
    int left = low;         // starting index of left array
    int right = mid + 1;    // starting index of right array

    int count = 0;          // count of inversions

    // storing elements in the temperory array in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller than left -> inversion
        else {
            temp.push_back(arr[right]);
            count += mid - left + 1;
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

    return count;
}

int mergeSort(long long int arr[], int low, int high) {
    int count = 0;
    if (low >= high) {
        return 0;
    }
    int mid = low + (high - low)/2;
    count += mergeSort(arr, low, mid);               // left half
    count += mergeSort(arr, mid + 1, high);          // right half
    count += merge(arr, low, mid, high);     // merging the two sorted halves
    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}
// Time Complexity -> O(NlogN)
// Space Complexity -> O(N)


// We can also create a copy of the array so that we don't modify the original array
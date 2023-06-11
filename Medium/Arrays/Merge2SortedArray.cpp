#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans;
    int left = 0;
    int right = 0;
    while (left < m && right < n) {
        if (arr1[left] <= arr2[right]) {
            ans.push_back(arr1[left]);
            left++;
        }
        else {
            ans.push_back(arr2[right]);
            right++;
        }
    }
    while (left < m) {
        ans.push_back(arr1[left]);
        left++;
    }
    while (right < n) {
        ans.push_back(arr2[right]);
        right++;
    }

    for (int i = 0 ; i < m + n ; i++) {
        arr1[i] = ans[i];
    }
}

// Optimal Approch: without using extra space
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int left = 0;
    int right = 0;
    while (left < m + n) {
        if (arr1[left] <= arr2[right] && arr1[left] != 0) {
            left++;
        }
        else if (arr2[right] == 0) {
            right++;
        }
        else {
            swap(arr1[left], arr2[right]);
            left++;
        }
    }
	sort (arr1.begin(), arr1.end());
    return arr1;
}
// 4 Sum Problem
// Brute -> O(n^4) 

#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    set<vector<int>> st;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            set<long long> hashset;
            for (int k = j + 1 ; k < n ; k++) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {    // Element is present in the Hashset
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(fourth);
                    temp.push_back(arr[k]);
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                    return "Yes";
                }
                hashset.insert(arr[k]);
            }
        }
    }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;
    return "No";
}
// Time -> O(N^3 log N)
// Space -> O(N) + O(quads)*2

// Optimal -> O(N^2)
// 1. Sort the array
// 2. Fix the first element and then use 3 Sum Problem
string fourSum(vector<int> arr, int target, int n) {
    string ans;
    sort(arr.begin(), arr.end());
    for (int i = 0 ; i < n ; i++) {
        if (i > 0 && arr[i] == arr[i-1]) 
            continue;
        for (int j = i + 1 ; j < n ; j++) {
            if (j != i+1 && arr[j] == arr[j-1])     // to skip duplicate element 
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    // ans.push_back(temp);
                    ans = "Yes";
                    while (k < l && arr[k] == arr[k-1]) 
                        k++;
                    while (k < l && arr[l] == arr[l+1]) 
                        l--;
                }
                else if (sum < target) {
                    k++;
                }
                else {
                    l--;
                }
            }
        }
    }
    if (ans == "Yes") {
        return "Yes";
    }
    else {
        return "No";
    }
}

// Leetcode:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        output.push_back({nums[i], nums[j], nums[low], nums[high]});
                        int tempIndex1 = low, tempIndex2 = high;
                        while(low < high && nums[low] == nums[tempIndex1]) low++;
                        while(low < high && nums[high] == nums[tempIndex2]) high--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};
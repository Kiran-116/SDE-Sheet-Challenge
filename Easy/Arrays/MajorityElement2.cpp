// Majority Element - 2: 
// Brute -> Pick up an element and check if it is a majority element or not.
// Better -> Hashing -> Time -> O(nlogn) Space -> O(n) => map
#include <bits/stdc++.h>
using namespace std;

// Coding Ninjas
vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && ele2 != arr[i]) {
            ele1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && ele1 != arr[i]) {
            ele2 = arr[i];
            cnt2 = 1;
        }
        else if (arr[i] == ele1) {
            cnt1++;
        }
        else if (arr[i] == ele2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    // Verfication
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0 ; i < n ; i++) {
        if (ele1 == arr[i]) {
            cnt1++;
        }
        if (ele2 == arr[i]) {
            cnt2++;
        }
    }
    int mini = (int) (n/3);
    if (cnt1 > mini) {
        ls.push_back(ele1);
    }
    if (cnt2 > mini) {
        ls.push_back(ele2);
    }
    sort(ls.begin(), ls.end());
    return ls;
}
// Time -> O(n)
// Space -> O(1)


// Leetcode:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && ele2 != nums[i]) {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && ele1 != nums[i]) {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == ele1) {
                cnt1++;
            }
            else if (nums[i] == ele2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        // Verfication
        vector<int> ls;
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0 ; i < n ; i++) {
            if (ele1 == nums[i]) {
                cnt1++;
            }
            if (ele2 == nums[i]) {
                cnt2++;
            }
        }
        int mini = (int) (n/3);
        if (cnt1 > mini) {
            ls.push_back(ele1);
        }
        if (cnt2 > mini) {
            ls.push_back(ele2);
        }
        sort(ls.begin(), ls.end());
        return ls;
    }
};
// Time -> O(n)
// Space -> O(1)
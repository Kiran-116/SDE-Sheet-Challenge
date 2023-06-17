// Longest Consecutive Sequence
// Brute -> Chck for each element, its next element is present or not and increase count Time -> O(N^2), Space -> O(1)
// Better -> Sort the array and then check for each element, its next element is present or not and increase count Time -> O(N log N), Space -> O(1)
// Optimal -> Use Hashset to store all the elements and then check for each element, its next element is present or not and increase count Time -> O(N), Space -> O(N)

#include <bits/stdc++.h>
using namespace std;

// Brute
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int count = 1;
        int curr = arr[i];
        while (find(arr.begin(), arr.end(), curr+1) != arr.end()) {
            count++;
            curr++;
        }
        ans = max(ans, count);
    }
    return ans;
}
// Time -> O(N^2)
// Space -> O(1)

// Better:
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    int longest = 1;
    int countCurr = 0;
    int lastSmallest = INT_MIN;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] - 1 == lastSmallest) {
            countCurr++;
            lastSmallest = arr[i];
        } 
        else if (arr[i] == lastSmallest) {
            continue;
        }
        else {                                  // (arr[i] - 1 != lastSmallest)
            countCurr = 1;
            lastSmallest = arr[i];
        }
        longest = max(longest, countCurr);
    }
    return longest;
}
// Distorted Array
// Time -> O(N log N)
// Space -> O(1)

// Optimal: Using unordered_set, we can check if the element is present or not in.
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    if (n==0) {
        return 0;
    }
    unordered_set<int> st;
    for (int i = 0 ; i < n ; i++) {
        st.insert(arr[i]);
    }
    int longest = 0;
    for (auto it: st) {                             // O(2N)
        if (st.find(it - 1) == st.end())  {         // Previous Element not found
            int count = 1;
            int x = it;     // current
            while (st.find(x+1) != st.end()) {  // O(1)
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}
// Time -> O(N)
// Space -> O(N)
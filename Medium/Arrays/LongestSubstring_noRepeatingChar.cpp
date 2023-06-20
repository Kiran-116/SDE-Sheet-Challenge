// Longest Substring Without Repeating Characters
// Brute: Generate all substrings and check for repeating characters -> Time = O(N^3), Space = O(1)
// Better: Make it to 2 loops only -> Time = O(N^2), Space = O(1)
// Optimal: Hash Map

#include <bits/stdc++.h>
using namespace std;

// Optimal: Hash Map & 2 Pointer
int uniqueSubstrings(string input)
{
    int l = 0, r = 0;
    int n = input.size();
    int count = 0;
    map<char, int> mp;
    while (r < n) {
        mp[input[r]]++;
        while (mp[input[r]] > 1) {
            mp[input[l]]--;
            l++;
        }
        count = max(count, r - l + 1);
        r++;
    }
    return count;
}
// Time -> O(2N)
// Space -> O(N)

// Most Optimal: Hashing & 2 Pointer & Store index of last occurance
int uniqueSubstrings(string input)
{
    int left = 0, right = 0;
    int n = input.size();
    int length = 0;
    vector<int> mpp(256, -1);
    while (right < n) {
        if (mpp[input[right]] != -1) {
            left = max(mpp[input[right]] + 1, left);
        }
        mpp[input[right]] = right;
        length = max(length, right - left + 1);
        right++;
    }
    return length;
}
// Time -> O(N)
// Space -> O(1) or O(N)
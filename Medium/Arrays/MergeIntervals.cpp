#include <bits/stdc++.h> 
using namespace std;

/*
    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval
*/

// Brute Force Approach
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    // Sort the intervals based on start point
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0 ; i < n ; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1]) {      // already lies in the previous interval
            continue;
        }
        for (int j = i + 1 ; j < n ; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
// Time -> O(2*N + NlogN)
// Space -> O(N)

// Optimal Approach:
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    // Sort the intervals based on start point
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0 ; i < n ; i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);        // New Interval 
        }
        else {                  // Overlapping Interval -> lies in the previous interval or extends the previous interval
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
// Time -> O(NlogN) + O(N)
// Space -> O(N)
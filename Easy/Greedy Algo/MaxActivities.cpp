#include <bits/stdc++.h>
using namespace std;

// Sort according to finish time in ascending order.
// If the start time of the next activity is greater than or equal to the finish time of the previous activity, then we can perform both the activities.
// Else, we can perform only one of them.

// Coding Ninjas:
bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int, int>> v;
    int n = start.size();
    for (int i = 0 ; i < n ; i++) {
        v.push_back({start[i], finish[i]});
    }
    // Sort according to finish time in ascending order.
    sort (v.begin(), v.end(), comparator);
    int count = 1;
    int prevFinish = v[0].second;
    for (int i = 1 ; i < n ; i++) {
        // If the start time of the next activity is greater than or equal to the finish time of the previous activity, then we can perform both the activities.
        if (v[i].first >= prevFinish) {
            count++;
            prevFinish = v[i].second;
        }
    }
    return count;
}
// Time -> O(N logN)
// Space -> O(N)

// GFG:
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({end[i], start[i]});
        }
        sort(v.begin(), v.end());
        int cnt=0;
        int last=-1;
        for(auto it: v){
            if(it.second>last){
                cnt++;
                last=it.first;
            }
        }
        return cnt;
    }
};
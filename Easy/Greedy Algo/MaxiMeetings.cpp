#include <bits/stdc++.h> 
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting m1, meeting m2) {
    if (m1.end < m2.end) {
        return true;
    }
    else if (m1.end > m2.end) {
        return false;
    }
    else if (m1.pos < m2.pos) {
        return true;
    }
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct meeting meet[n];
    // store start, end, and pos of each meeting
    for (int i = 0 ; i < n ; i++) {
        // meet[i] = {start[i], end[i], i};
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    // Sort according to the meet.end
    sort(meet, meet+n, comparator);
    
    vector<int> ans;

    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for (int i = 0 ; i < n ; i++) {
        if (meet[i].start > limit) {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}
// Time -> O(nlogn)
// Space -> O(n)

// GFG:
class Solution
{

    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
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
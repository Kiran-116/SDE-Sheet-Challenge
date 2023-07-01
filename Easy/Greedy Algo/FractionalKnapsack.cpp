#include <bits/stdc++.h> 
using namespace std;

// Take them in decreasing order of profit or value/weight ratio.

bool comp(pair<int, int> a, pair<int, int> b) {
    int x = (double)a.second/(double)a.first;
    int y = (double)b.second/(double)b.first;
    return (a.second > b.second);
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    // Sort in decreasing order of value/weight ratio.
    sort(items.begin(), items.end(), comp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0 ; i < n ; i++) {
        
    }
}
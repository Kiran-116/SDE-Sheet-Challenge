// Maximize the Profit
// If you are selling on ith day, you buy on the minimum price from 0 to i-1

#include <bits/stdc++.h>
using namespace std;

// Leetcode:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0 ; i < n ; i++) {
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        return maxProfit;
    }
};

// Coding Ninjas
int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 0 ; i < n ; i++) {
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

// Time -> O(n)
// Space -> O(1)
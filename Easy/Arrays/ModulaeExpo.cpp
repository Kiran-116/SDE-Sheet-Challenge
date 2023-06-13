#include <bits/stdc++.h> 
using namespace std;

// Coding Ninjas
int modularExponentiation(int x, int n, int m) {
    int res = 1;

    while(n > 0)
    {
        if (n&1)    // odd
        {
            res = (1LL * (res) * (x)%m)%m;
        }
        x = (1LL *(x)%m * (x)%m)%m;
        n = n >> 1;     // bits are less expensive -> div by 2
    }
    return res;
}

// Leetcode:
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if (nn < 0) {
            nn = -1 * nn;
        }
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            }
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) {
            ans = (double)(1.0) / double(ans);
        }
        return ans;
    }
};
// Time Complexity -> O(logN)
// Space Complexity -> O(1)
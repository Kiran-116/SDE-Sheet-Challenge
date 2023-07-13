#include <bits/stdc++.h>
using namespace std;

bool pos(long long m, vector<int> &v, long long &mx) {
    long long i = 0, tot = 0;
    while (m and i < v.size()) {
        if (v[i] > mx) {
            return false;
        }
        else {
            if (tot + v[i] <= mx){
                tot += v[i];
            }
            else {
                m--;
                tot = v[i];
            }
        }
        i++;
    }

    if (m < 1 or i < v.size()) {
        return false;
    }

    return true;
}

long long ayushGivesNinjatest(int n, int mm, vector<int> &time){
    long long t = 0;
    for (int i = 0; i < time.size(); i++) {
        t += time[i];
    }

    long long s = 0, ans = 0;

    while (s <= t) {
        long long m = (t + s) / 2;
        if (pos(n, time, m)) {
            ans = m;
            t = m - 1;
        }
        else {
            s = m + 1;
        }
    }

    return ans;
}

// Time -> O(logN * N)
// Space -> O(1)
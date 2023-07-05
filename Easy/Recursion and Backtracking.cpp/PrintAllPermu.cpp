#include <bits/stdc++.h> 
using namespace std;

void solve(int ind, string &s, vector<string> &ans) {
    if (ind == s.length()) {
        ans.push_back(s);
        return;
    }
    for (int i = ind ; i < s.length() ; i++) {
        swap(s[i], s[ind]);
        solve(ind+1, s, ans);
        swap(s[i], s[ind]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    solve(0, s, ans);
    return ans;
}

// Time -> O(n! * n)
// Space -> O(n! * n)
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, -1);
    stack<int> St;
    for (int i = n-1 ; i >= 0 ; i--) {
        while (!St.empty()) {
            if (St.top() < arr[i]) {
                ans[i] = St.top();
                break;
            }
            St.pop();
        }
        St.push(arr[i]);
    }
    return ans;
}
// Time -> O(2n + 2n)
// Space -> O(n)
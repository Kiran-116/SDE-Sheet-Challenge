#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> ans;

    vector<long long int> prev;

    prev.push_back(1);

    ans.push_back(prev);

    for(int i=2;i<=n;i++){
        vector<long long int> temp(i,1);
        for (int j = 1; j < i-1; j++) {
            temp[j] = prev[j] + prev[j - 1];
        }
        ans.push_back(temp);
        prev=temp;
    }

    return ans;
}

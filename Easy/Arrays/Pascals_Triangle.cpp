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


// 1st Type -> find nth row and cth column
int nCr(int n, int r) {
    long long int res = 1;
    for (int i = 0 ; i < r ; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}


// Optimal Code Studio
// Type - 2
vector<long long int> generateRow(int row) {
    long long ans = 1;
    vector<long long int> ansRow;
    ansRow.push_back(1);
    for (int col = 1 ; col < row ; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

// Type - 3
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> ans;
    for (int i = 1 ; i <= n ; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
}

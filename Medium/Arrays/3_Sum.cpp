#include <bits/stdc++.h> 
using namespace std;

// Brute -> using 3 Pointers:
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    set<vector<int>> st;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            for (int k = j + 1 ; j < n ; j++) {
                if (arr[i] + arr[j] + arr[k] == K) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
	vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Time -> O(n^3)
// Space -> O(n)

// Better -> using 2 Pointers:
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    set<vector<int>> st;
    for (int i = 0 ; i < n ; i++) {
        set<int> hashset;
        for (int j = i + 1 ; j < n ; j++) {
            int third = K - (arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Time -> O(n^2 logm)
// Space -> O(n)

// Optimal -> sorting + 2 Pointers:
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> ans;
    sort (arr.begin(), arr.end());
    for(int i = 0 ; i < n ; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int j  = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < K) {
                j++;
            }
            else if (sum > K) {
                k--;
            }
            else {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1]) {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans;
}
// Time -> O(n^2)
// Space -> O(no. of unique triplets)
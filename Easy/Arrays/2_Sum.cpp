// 2 Sum Problem
// Brute -> Pick up an element and check if there is another element in the array such that their sum is equal to the target. Time -> O(n^2) Space -> O(1)
// Better -> Sort the array and then use two pointers to find the sum. Time -> O(nlogn) Space -> O(1)
// Optimal -> Use a hashmap to store the elements and then check if there is another element in the array such that their sum is equal to the target. Time -> O(n) Space -> O(n)

#include <bits/stdc++.h>
using namespace std;

// Better: Hashing or 2 pointer -> Sort & 2 pointer
vector<vector<int>> pairSum(vector<int> &arr, int target){
    map<int, int> mpp;
    for (int i = 0 ; i < arr.size() ; i++) {
        int a = arr[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end()) {
            return {{a, more}};
        }
        else {
            mpp[a] = i;
        }
    }
    return {};
}
// T(N) = O(N logN)
// S(N) = O(N)
// 2 Pointer Approch
vector<vector<int>> pairSum(vector<int> &arr, int target){
    int left = 0,  right = arr.size() - 1;
    vector<vector<int>> Ans;
    sort(arr.begin(), arr.end());
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == target) {
            Ans.push_back({arr[left], arr[right]});
            // return {{arr[left], arr[right]}};
        }
        else if (currentSum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return Ans;
}

// Optimal:
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
    sort(arr.begin(), arr.end());
    vector<vector<int>> pairs;
    int j = 0;
    for(int i = 1; i < arr.size(); i++) {
        int sum = arr[j] + arr[i];
        if(sum == s) {
            vector<int> temp;
            temp.push_back(arr[j]);
            temp.push_back(arr[i]);
            pairs.push_back(temp);
        }
        if((sum > s) || ((i == arr.size() - 1) && (j<arr.size()))) {
            j++;
            i = j;
        }
    }
    return pairs;
}
// T(N) = O(N logN)
// S(N) = O(1)
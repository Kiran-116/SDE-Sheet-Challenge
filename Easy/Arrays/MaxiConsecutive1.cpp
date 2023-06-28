#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    int count = 0;
    int maxi = 0;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] == 1) {
            count++;
            maxi = max(maxi, count);
        }
        else {
            count = 0;
        }
    }
    return maxi;
}
// Time -> O(n)
// Space -> O(1)

// Very imp
int longestSubSeg(vector<int> &arr , int n, int k){
    int i = 0, j = 0;
    int maxi = 0;
    int flip = 0;

    while(j < n){
        if(arr[j] == 0) {
            flip++;
        }

        while(flip > k){
            if(arr[i] == 0) {
                flip--;
            }
            i++;
        }
        maxi = max(maxi, j - i + 1);
        j++;
    }
    return maxi;
}
// Time -> O(n)
// Space -> O(1)
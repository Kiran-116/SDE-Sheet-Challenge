// Brute Force => Sort the Array    -> O(N logN)

// Better => Take count0, count1 and count2 variables
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] == 0) {
                count0++;
            }
            else if (a[i] == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }
        int k = 0;
        while (count0--) {
            a[k++] = 0;
        }
        while (count1--) {
            a[k++] = 1;
        }
        while (count2--) {
            a[k++] = 2;
        }
    }
};



// MOST Optimal Approach -> Dutch National Flag Algorithm:
// using 3 Pointers -> low, mid, high
// [0, ..., low-1] -> extreme left
// [low, ..., mid-1] -> middle
// [mid+1, ..., n-1] -> extreme right
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n-1;
        while (mid <= high) {
            if (a[mid] == 0) {
                swap(a[mid], a[low]);
                mid++;
                low++;
            }
            else if (a[mid] == 1) {
                mid++;
            }
            else {          // 
                swap(a[mid], a[high]);
                high--;
            }
        }
    }
};

// Time -> O(N)
// Space -> O(1)

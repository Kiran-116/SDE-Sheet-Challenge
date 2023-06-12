// Brute Force -> For Each element check the number of occurance -> O(N^2)
// Better -> Hashing -> Time & Space ->O(N)
#include <bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int rep;
	int miss;
	int hash[n+1] = {0};
	for (int i = 0; i < n ; i++) {
		hash[arr[i]]++;
	}
	for (int i = 0 ; i <= n ; i++) {
		if (hash[i] == 0) {
			miss = i;
		}
		else if (hash[i] > 1) {
			rep = i;
		}
	}
	pair<int, int> P;
	P.first = miss;
	P.second = rep;
	return P;
}

// Optimal Approach -> Using Maths
// x = Repeating Number
// y = Missing Number
// 1. Find the sum of n natural numbers = Sn
// 2. Find the sum of the array = S
// 3. Sn - S = x - y
// 4. Find the sum of squares of n natural numbers = Sn2
// 5. Find the sum of squares of the array = S2
// 6. Sn2 - S2 = x2 - y2
// 2 variables and 2 equations -> Solve them to get x and y
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// S - Sn
    // S2 - S2N
    long long int Sn = (n * (n+1))/2;
    long long int S2N = (n * (n+1) * (2*n+1))/6;
    long long S = 0, S2 = 0;
    for (int i = 0 ; i < n ; i++) {
        S += arr[i];
        S2 += (long long int)arr[i] * (long long int)arr[i];
    }
    long long int val1 = S - Sn;          // x - y
    long long int val2 = S2 - S2N;        // x2 - y2
    val2 = val2/val1;           // x + y
    long long int x = (val1 + val2)/2;
    long long int y = val2 - x;
    
    return {(int)x, (int)y};
}
// Time Complexity -> O(N)
// Space Complexity -> O(1)
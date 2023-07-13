#include <bits/stdc++.h>
using namespace std;
// Brute Force -> Merge Sort -> O(nlogn)
// Better Force -> using Counter -> O(n + m)

// Optimal Approach:
double median(vector<int>& num1, vector<int>& num2) {
	if (num2.size() < num1.size()) {
		return median(num2, num1);
	}
	int n1 = num1.size();
	int n2 = num2.size();
	int low = 0, high = n1;

	while(low <= high) {
		int cut1 = (low + high)/2;
		int cut2 = (n1 + n2 + 1)/2 - cut1;

		int left1 = cut1 == 0 ? INT_MIN : num1[cut1 - 1];
		int left2 = cut2 == 0 ? INT_MIN : num2[cut2 - 1];

		int right1 = cut1 == n1 ? INT_MAX : num1[cut1];
		int right2 = cut2 == n2 ? INT_MAX : num2[cut2];

		if (left1 <= right2 && left2 <= right1) {	// check validity
			if ((n1 + n2) % 2 == 0) {
				return (max(left1, left2) + min(right1, right2))/2.0;
			}
			else {
				return max(left1, left2);
			}
		}
		else if (left1 > right2) {		// left BS
			high = cut1 - 1;
		}
		else {							// right BS
			low = cut1 + 1;
		}
	}
	return 0.0;
}

// Time -> O(log(min(n1, n2))
// Space -> O(1)
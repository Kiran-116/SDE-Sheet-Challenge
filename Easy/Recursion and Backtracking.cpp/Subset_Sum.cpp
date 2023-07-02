#include <bits/stdc++.h>
using namespace std;

// Brute -> Find all Subsets -> O(2^N * N)
// Optimal -> Recursion
void RecursiveSubsetSum(vector<int> &num, int i, int sum, vector<int> &subset) {
    if (i == num.size()) {
        subset.push_back(sum);
		return;
    }
	// including
	RecursiveSubsetSum(num, i+1, sum + num[i], subset);

	// do not include:
	RecursiveSubsetSum(num, i+1, sum, subset);
}

vector<int> subsetSum(vector<int> &num){
	int sum = 0;
	int i = 0;
	vector<int> subset;
	RecursiveSubsetSum(num, i, sum, subset);
	sort(subset.begin(), subset.end());
	return subset;
}
// Time -> O(2^N)
// Space -> O(N)
// Kth Permutation Sequence

#include <bits/stdc++.h>
using namespace std;
// Brute: Generate all permutations, sort them and return the kth one -> O(N! * NlogN)
// Optimized: Generate only the kth permutation -> O(N^2)

string kthPermutation(int n, int k) {
    int fact = 1;
    vector<int> numbers;
    for (int i = 1 ; i < n ; i++) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k/fact);
        if (numbers.size() == 0) {
            break;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
// Time -> O(N^2)
// Space -> O(N)
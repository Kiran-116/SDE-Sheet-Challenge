// Brute Force -> Find all Permutations, Sort, Next Index Permutation  T(N) = O(N! * N)
// Better -> STL -> next_permutation(A.begin(), B.begin())  T(N) = O(N!)
// Optimal -> 
// 1. Longer Prefix Match -> find out the particular index
// 2. Find someone greater than me from the right but the smallest one, swap with him, 
// 3. sort the right part  T(N) = O(N)

#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind = -1;
    for (int i = n - 2 ; i >= 0 ; i--) {
        if (permutation[i] < permutation[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for (int i = n - 1 ; i > ind ; i--) {
        if (permutation[i] > permutation[ind]) {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }
    reverse(permutation.begin() + ind + 1, permutation.end());
    return permutation;
}

// Time -> O(3N)
// Space -> O(1)

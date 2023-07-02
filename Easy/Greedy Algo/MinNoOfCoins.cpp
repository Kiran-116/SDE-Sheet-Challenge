#include <bits/stdc++.h> 
using namespace std;

// [1, 2, 5, 10, 20, 50, 100, 500, 1000]
int findMinimumCoins(int amount) 
{
    int count = 0;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins)/sizeof(coins[0]);     // 9
    for (int i = n - 1 ; i >= 0 ; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return count;
}
// Time -> O(N)
// Space -> O(1)

// Why the Greedy Algorithm fail?
// Consider the denominations {1, 5, 6, 9} and the amount 11.
// The greedy algorithm would choose {9, 1, 1} while the optimal solution is {5, 6}.
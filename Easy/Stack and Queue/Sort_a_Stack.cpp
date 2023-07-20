#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    // base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }

    // if top is > num, keep it aside.
    int n = stack.top();
    stack.pop();

    // recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
	// base case
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);
}

// Time -> O(N^2)
// Space -> O(N)
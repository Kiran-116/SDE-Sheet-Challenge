// IMP !!! -> Microsoft, Amazon, Adobe, Flipcart

#include <bits/stdc++.h>
using namespace std;

bool matches(char top, char ch) {
    if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) {
        return true;
    }
    else {
        return false;
    }
}

bool isValidParenthesis(string expression)
{
    stack<char> S;
    int n = expression.length();

    for (int i = 0 ; i < n ; i++) {
        char ch = expression[i];
        if (ch == '[' || ch == '{' || ch == '(') {
            S.push(ch);     // Push opening brackets
        }
        else {
            if (! S.empty()) {
                char top = S.top();
                if (matches(top, ch)) {
                    S.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    if(S.empty()) {
        return true;
    }
    else {
        return false;
    }
}

// Time -> O(n)
// Space -> O(n)

// Optimal -> Leetcode:
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

// Time -> O(N)
// Space -> O(N)
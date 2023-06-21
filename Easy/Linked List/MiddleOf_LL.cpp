// Brute -> Count the no. of nodes and then traverse again to the middle node -> O(N) + O(N/2)
// Optimal -> Use 2 pointers (slow & fast) -> T = O(N/2), S = O(1) (Slow & Fast Tourtise)
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Coding Ninjas:
Node *findMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // moves 1 step
        fast = fast->next->next;    // moves 2 steps
    }
    return slow;
}
// Time -> O(N/2)
// Space -> O(1)

// LeetCode:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps
        }
        return slow;
    }
};
// Time -> O(N/2)
// Space -> O(1)
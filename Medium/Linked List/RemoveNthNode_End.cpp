// Remove Nth node from the end of the Linked List:
// Brute -> Find the length of the linked list, then traverse to the (length - n)th node and delete it -> O(N) time, O(1) space
// Optimal -> Use 2 pointers, first pointer moves n steps ahead of the second pointer, then move both the pointers until the first pointer reaches the end of the linked list, then delete the node pointed by the second pointer -> O(N) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

// Coding Ninjas:
class Node
{
    public:
        int data;
        Node *next;
        Node() {
            this->data = 0;
            next = NULL;
        }
        Node(int data) {
            this->data = data; 
            this->next = NULL;
        }
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

Node* removeKthNode(Node* head, int K)
{
    Node *start = new Node();
    start->next = head;
    Node *fast = start;
    Node *slow = start;
    // Move fast pointer K steps ahead of the slow pointer
    for (int i = 1 ; i <= K ; i++) {
        fast = fast->next;
    }
    // Move both the pointers until the fast pointer reaches the end of the linked list
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; // Delete the node pointed by the slow pointer
    return start->next;
}

// Leetcode:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;
        // Move fast pointer n steps ahead of the slow pointer
        for (int i = 1 ; i <= n ; i++) {
            fast = fast->next;
        }
        // Move both the pointers until the fast pointer reaches the end of the linked list
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; // Delete the node pointed by the slow pointer
        return start->next;
    }
};
// Time = O(N)
// Space = O(1)
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

// Brute -> Hashing -> O(n) space and time
// Optimal: Floyd's Cycle Detection Algorithm -> O(1) space and O(n) time
// 1. Find Collision Point (slow and fast)
// 2. Take an iterator from head and collision point and move them one step at a time (Entry and slow)
// 3. The point where they meet is the starting point of the cycle (entry and slow)

Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    // Finding the collision point
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    // If there is no cycle
    if (slow != fast) {
        return NULL;
    }
    // Finding the entry point
    Node *entry = head;
    while (entry != slow) {
        entry = entry->next;
        slow = slow->next;
    }
    return entry;
}
// Time -> O(N)
// Space -> O(1)
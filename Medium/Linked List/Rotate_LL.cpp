#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Brute -> Pick up the last element and put it in the front -> O(n*k) time and O(1) space
// Optimal -> Find the kth node from the end and make it the new head -> O(n) time and O(1) space

Node *rotate(Node *head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    Node *curr = head;
    int len = 1;
    while (curr->next != NULL) {
        curr = curr->next;
        len++;
    }
    // go till that last node
    curr->next = head;
    k = k % len;            // if (k > len) then k = k % len
    for (int i = 1 ; i <= len - k ; i++) {
        curr = curr->next;
    }
    // make the node head and break connection
    head = curr->next;
    curr->next = NULL;
    return head;
}
// Time -> O(N)
// Space -> O(1)
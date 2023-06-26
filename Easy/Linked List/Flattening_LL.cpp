#include <bits/stdc++.h>
using namespace std;

// Definition for linked list.
class Node {
 public:
    int data;
    Node *next;
    Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Brute -> Using a stack -> O(n) space and time
// Optimal -> Using recursion -> O(1) space and O(n) time

Node* merge2Lists(Node *a, Node *b) {
    Node *temp = new Node(0);
    Node *res = temp;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
    }
    if (a != NULL) {
        temp->child = a;
    }
    else {
        temp->child = b;
    }
    return res->child;
}
Node* flattenLinkedList(Node* head) {
	if (head == NULL || head->next == NULL) {
        return head;
    }
    // Recur for the list on right
    Node *L2 = flattenLinkedList(head->next);
	head->next = NULL;
    // now merge
    Node *nhead = merge2Lists(head, L2);

    // return the root
    // it will be in turn merged with its left
    return nhead;
}
// Time -> O(N)
// Space -> O(1)
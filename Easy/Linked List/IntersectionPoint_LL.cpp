#include <bits/stdc++.h>
using namespace std;

// Intersection Point of 2 Linked List:
// Brute -> For every node in LL1, traverse LL2 and check if any node matches. O(N*M)
// Better -> Hashing -> Store all the nodes of LL1 in a hash table and then traverse LL2 and check if any node matches. O(N+M)

// Optimal - 1 -> Find the length of both the LLs and then traverse the longer LL by (length1 - length2) nodes. Then traverse both the LLs simultaneously and check if any node matches. O(N+M)
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

Node* findIntersection(Node *firstHead, Node *secondHead) {
    Node *dummy1 = firstHead;
    Node *dummy2 = secondHead;
    int length1 = 0, length2 = 0;
    while (dummy1 != NULL) {
        length1++;
        dummy1 = dummy1->next;
    }
    while (dummy2 != NULL) {
        length2++;
        dummy2 = dummy2->next;
    }
    dummy1 = firstHead;
    dummy2 = secondHead;
    if (length1 > length2) {
        int diff = length1 - length2;
        while (diff--) {
            dummy1 = dummy1->next;
        }
    }
    else {
        int diff = length2 - length1;
        while (diff--) {
            dummy2 = dummy2->next;
        }
    }
    while (dummy1 != NULL && dummy2 != NULL) {
        if (dummy1 == dummy2) {
            return dummy1;
        }
        dummy1 = dummy1->next;
        dummy2 = dummy2->next;
    }
    return NULL;
}

// Optimal - 2 -> Traverse both the LLs simultaneously and check if any node matches. If any of the LL reaches NULL, then start traversing the other LL from the head. O(N+M)
Node* findIntersection(Node *firstHead, Node *secondHead) {
    if (firstHead == NULL || secondHead == NULL) {
        return NULL;
    }
    Node *dummy1 = firstHead;
    Node *dummy2 = secondHead;
    // if any of the LL reaches NULL, then start traversing the other LL from the head
    // if dummy1 & dummy2 have different len, then we will stop the loop after 2nd iteration
    while (dummy1 != dummy2) {
        // for the end of first iteration, we just reset the pointer to the head of another linkedlist
        dummy1 = dummy1 == NULL ? secondHead : dummy1->next;
        dummy2 = dummy2 == NULL ? firstHead : dummy2->next;
    }
    return dummy1; // if dummy1 == NULL, then dummy2 == NULL
}
// Time Complexity -> O(N+M)
// Space Complexity -> O(1)
#include <bits/stdc++.h>
using namespace std;

// Following is the linked list node structure.
template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Brute: Merge 2 sorted linked lists into a new linked list (External Space) -> O(N+M) time, O(N+M) space
// Optimal: Merge 2 sorted linked lists into a new linked list (Internal Space) -> O(N+M) time, O(1) space
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int> *dummy = new Node<int>(-1);
    Node<int> *H = dummy;
    while (first != NULL && second != NULL) {
        if (first->data <= second->data) {
            Node<int> *temp = new Node<int> (first->data);
            H->next = temp;
            first = first->next;
        }
        else {
            Node<int> *temp = new Node<int> (second->data);
            H->next = temp;
            second = second->next;
        }
        H = H-> next;
    }
    if (first == NULL) {
        H->next = second;
    }
    if (second == NULL) {
        H->next = first;
    }
    return dummy->next;
}
// Time -> O(N+M)
// Space -> O(1)

// Optimal -> Merge 2 sorted linked lists into a new linked list (Internal Space) -> O(N+M) time, O(1) space
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }
    if (first->data > second->data) {
        swap(first, second);
    }
    Node<int> *head = first;
    while (first != NULL && second != NULL) {
        Node<int> *temp = NULL;
        while (first != NULL && first->data <= second->data) {
            temp = first;           // track the last node of first list
            first = first->next;
        }
        temp->next = second;        // connect the last node of first list to the first node of second list
        swap(first, second);        // swap the lists
    }
    return head;
}
// Time -> O(N+M)
// Space -> O(1)
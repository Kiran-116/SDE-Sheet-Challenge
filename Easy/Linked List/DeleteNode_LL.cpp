#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the LinkedListNode class:
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Approach 1: Copy the data of next node to the current node and delete the next node.
void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}
// Time -> O(1)
// Space -> O(1)

// Leetcode: if not to delete the node
class Solution {
public:
    void deleteNode(LinkedListNode<int> *node) {
        node->data = node->next->data;
        node->next = node->next->next;
    }
};
// Time = O(1)
// Space = O(1)
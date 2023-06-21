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
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


// Coding Ninjas:
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *newHead = NULL;    // dummy node or prev node
    while (head != NULL) {
        LinkedListNode<int> *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}
// Time -> O(N)
// Space -> O(1)

// LeetCode:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;    // dummy node or prev node
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};
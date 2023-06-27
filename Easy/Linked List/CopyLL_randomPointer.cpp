#include <bits/stdc++.h>
using namespace std;

// Following is the LinkedListNode class structure

template <typename T>   
class LinkedListNode
{
    public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Brute -> Using a map -> O(n) space and time
// Optimal -> O(1) space and O(n) time -> creaty each dummy node to the next of the original node

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Step - 1: Create a copy of each node and insert it to the next of original node
    LinkedListNode<int> *iter = head;
    LinkedListNode<int> *front = head;
    while (iter != NULL) {
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }
    // Step - 2: Link the random pointers of the new nodes created
    iter = head;
    while (iter != NULL) {
        if (iter->random != NULL) {
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }
    // Step - 3: Unweave the linked list to get back the original and the cloned list
    iter = head;
    LinkedListNode<int> *pseudoHead = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = pseudoHead;
    while (iter != NULL) {
        front = iter->next->next;
        copy->next = iter->next;
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return pseudoHead->next;
}
// Time -> O(N)
// Space -> O(1)


LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int>*curr = head;
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*>mp;
    // creating copy of each node & storing in the map
    while(curr!=NULL){
        LinkedListNode<int>*temp = new LinkedListNode<int>(curr->data);
        mp[curr]=temp;
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL){
        LinkedListNode<int>*temp = mp[curr];
        temp->next = mp[curr->next];
        temp->random = mp[curr->random];
        curr=curr->next;
    }
    return mp[head];
}
// Time -> O(N)
// Space -> O(1)
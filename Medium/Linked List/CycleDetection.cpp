#include <bits/stdc++.h>
using namespace std;


// Following is the class structure of the Node class:
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

// Brute -> HASHING => Traverse the LL and store the address of each node in a hash table. If any node is already present in the hash table, then there is a cycle. O(N) time and O(N) space.
// Optimal -> Floyd's Cycle Detection Algorithm => Take 2 pointers, slow and fast. Move slow by 1 node and fast by 2 nodes. If they meet at any point, then there is a cycle. O(N) time and O(1) space.
bool detectCycle(Node *head)
{
	//	use slow and fast pointer:
    if (head == NULL || head->next == NULL) {   // Null or single element linked list
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        //	if slow and fast meet at any point, then there is a cycle:
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
// Time -> O(N)
// Space -> O(1)
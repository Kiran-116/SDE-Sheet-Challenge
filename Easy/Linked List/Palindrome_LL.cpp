#include <bits/stdc++.h> 
using namespace std;

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

// Brute -> Coping the linked list in a vector/array and then checking for palindrome -> O(n) space and time
// Optimal -> Reversing the second half of the linked list and then comparing the first half with the second half -> O(1) space and O(n) time
// 1. Find the middle of the linked list
// 2. Reverse the second half of the linked list
// 3. Compare the first half with the second half
// 4. Reverse the second half again to get the original linked list
LinkedListNode<int> * reverseList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next; 
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    // Finding the middle of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;

    while (slow != NULL) {
        if (head->data != slow->data) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}
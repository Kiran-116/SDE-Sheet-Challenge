// Implement Stack using Array
#include <bits/stdc++.h>
using namespace std;

// Stack class.
class Stack {
    int topIndex;
    int *arr;
    int size;
public:
    
    Stack(int capacity) {
        this->topIndex = -1;
        this->size = capacity;
        arr = new int[capacity];
    }

    void push(int num) {
        if (!isFull()) {
            topIndex++;
            arr[topIndex] = num;
        }
        return;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        topIndex--;
        return arr[topIndex + 1];
    }
    
    int top() {
        if (!isEmpty()) {
            return arr[topIndex];
        }
        else {
            return -1;
        }
    }
    
    int isEmpty() {
        if (topIndex <= -1) {
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        if(topIndex + 1 >= size) {
            return 1;
        }
        return 0;
    }
    
};

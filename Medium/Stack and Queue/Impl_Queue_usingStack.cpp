// Approach 1 : 
// Enqueue : T.C : O(N)
// Dequeue : T.C : O(1)

#include<bits/stdc++.h>
using namespace std;

class Queue {
    // Make 2 stacks ans size
    stack<int>s1;
    stack<int>s2;
    int size;
    
    public:
    Queue() {
        // Initialize your size structure here.
        size = 0;
    }

    void enQueue(int val) {
        // Enque or push operation

        // Step 1 : Put all the elements from s1 to  s2
        while(!s1.empty()) {
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }

        // Step 2 : Put the lement is s1
        s1.push(val);

        // Step 3 : Put all the elements from s2 to  s1
        while(!s2.empty()) {
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }
        size++;
    }

    int deQueue() {
        // Dequeue or pop opeation
        if(s1.empty()) {
            return -1;
        }
        else {
            int val = s1.top();
            s1.pop();
            size--;
            return val;
        }
    }

    int peek() {
        // Check size
        if(s1.empty()) {
            return -1;
        }
        else {
            int val = s1.top();
            return val;
        }
    }

    bool isEmpty() {
        if(s1.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
 

// Approach 2 :  
// Enqueue : T.C : O(1)
// Dequeue : T.C : O(N)

class Queue {
    // Make 2 stacks ans size
    stack<int>s1;
    stack<int>s2;
    int size;
    
    public:
    Queue() {
        // Initialize your size structure here.
        size = 0;
    }

    void enQueue(int val) {
        // Enque or push operation

        // Push into stack 1 
        s1.push(val);

        // Update the size
        size++;
    }

    int deQueue() {
        // Dequeue or pop opeation
        
        int ans;
        // Step 1 : Chcek if s2 is empty or not
        if(!s2.empty()) {
            ans = s2.top();
            s2.pop();
        }
        else {
            // If s2 is e,pty put all the elements from s1 to s2
            while(!s1.empty()) {
                int val = s1.top();
                s1.pop();
                s2.push(val);   
            }
            
            // Again check if s2 is empty or not
            // if s1 was empty the s2 will also be empty
            if(!s2.empty()) {
                ans = s2.top();
                s2.pop();
            }
            // If both are empty (s1, s2)
            else {
                return -1;
            }
        }
        size--;
        return ans;
    }

    int peek() {
        // if s2 is not empty then s2.top() is answer
        if(!s2.empty()) {
            return s2.top();
        }
        else {
            // if both s1 and s2 is empty
            if(s1.empty()) {
                return -1;
            }
            else {
                // if only s2 is empty
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                return s2.top();
            }
        }
    }


    bool isEmpty() {
        if(size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
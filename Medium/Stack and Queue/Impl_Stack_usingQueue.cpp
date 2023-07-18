// Implement Stack using Queue:
#include <bits/stdc++.h>
using namespace std;

// Using 2 queues:
class Stack {
	// Define the data members.
    private:
        queue<int> q1;
        queue<int> q2;
        int length;

    public:
        // Implement the Constructor.
        Stack() {
            length = 0;
        }

        int getSize() {
            return length;
        }

        bool isEmpty() {
            return length == 0;
        }

        void push(int element) {
            q2.push(element);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1, q2);
            length++;
        }

        int pop() {
            if(!q1.empty()){
                int value = q1.front();
                q1.pop();
                length--;
                return value;
            }
            return -1;
        }

        int top() {
            if(!q1.empty()){
                return q1.front();
            }
            return -1;
        }
};
// Time -> push: O(n), pop: O(1), top: O(1)
// Space -> O(n)

// Using 1 queue:
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz=q.size();
        q.push(x);
        while(sz--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int result=top();
        q.pop();
        return result;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
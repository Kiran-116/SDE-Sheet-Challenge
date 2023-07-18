// Queue Implementation using Array:

#include <bits/stdc++.h>
using namespace std;

class Queue {

	int front, rear;
	vector<int> arr;
	int count;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
		count = 0;
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		arr[rear % arr.size()] = e;
		rear++;
		count++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if (count == 0) {
            return -1;
        }
        int ans = arr[front % arr.size()];
		arr[front % arr.size()] = -1;
        front++;
		count--;
		return  ans;
	}
};

// Coding Ninjas:
class Queue {
    int *arr;
    int qfront;
    int qrear;
    int size;
public:
    Queue() {
        size = 100001;
        qfront = 0;
        qrear = 0;
        arr = new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if (qfront == qrear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if (qrear == size) {
            cout << "Queue is Full" << endl;
        }
        else {
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == qrear) {
            qfront = 0;
            qrear = 0;
        }
        return ans;
    }

    int front() {
        if (qfront == qrear) {
            return -1;
        }
        return arr[qfront];
    }
};
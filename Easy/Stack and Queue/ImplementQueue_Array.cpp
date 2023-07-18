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
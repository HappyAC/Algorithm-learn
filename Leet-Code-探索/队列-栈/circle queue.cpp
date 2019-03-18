#include <iostream>
#include <vector>
#include <new>

using namespace std;

class MyCircularQueue {
public:
    int head;
    int tail;
    int length;
    int max;
    vector<int> data;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        int head = -1;
        tail = -1;
        length = 0;
        max = k;
        data.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (this->isFull()) return false;
        if (head == tail && head == -1) {
            head++;
            tail++;
        } else {
            tail++;
        }
        head %= max;
        tail %= max;
        
        data[tail] = value;
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (this->isEmpty()) return false;
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head++;
            head %= max;
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (this->isEmpty()) return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (this->isEmpty()) return -1;
        return data[tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % max == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main () {
	MyCircularQueue circularQueue = MyCircularQueue(7); // 设置长度为 7

	cout << circularQueue.enQueue(0) << endl;  // 1
	
	cout << circularQueue.Front() << endl;    // 0
	
	cout << circularQueue.enQueue(4) << endl;  // 1
	
	cout << circularQueue.Rear() << endl;  // 4
	
	cout << circularQueue.enQueue(6) << endl;  // 1
	
	cout << circularQueue.enQueue(3) << endl;  // 1
	
	cout << circularQueue.Rear() << endl;  // 3
	
	cout << circularQueue.deQueue() << endl;  // 1
	
	cout << circularQueue.Front() << endl;  // 4
	
	cout << circularQueue.deQueue() << endl;  // 1
	
	cout << circularQueue.Front() << endl;  // 6
	
	
	
	return 0;
} 

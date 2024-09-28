class MyCircularDeque {
public:
    // Declare variables for deque, size, front, rear, and current count of elements
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currCount;

    // Constructor to initialize the deque with given size
    MyCircularDeque(int k) {
        K = k; // Set the size of the deque
        deq = vector<int>(K, 0); // Initialize deque with size K and default values as 0
        front = 0; // Initialize front pointer
        rear = K - 1; // Initialize rear pointer
        currCount = 0; // Initialize the count of elements in deque as 0
    }
    
    // Insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false; // If deque is full, return false

        front = (front - 1 + K) % K; // Update front pointer in circular fashion
        deq[front] = value; // Insert the value at the front
        currCount++; // Increment the count of elements
        return true; // Return true to indicate successful insertion
    }
    
    // Insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false; // If deque is full, return false

        rear = (rear + 1) % K; // Update rear pointer in circular fashion
        deq[rear] = value; // Insert the value at the rear
        currCount++; // Increment the count of elements
        return true; // Return true to indicate successful insertion
    }
    
    // Delete an element from the front of the deque
    bool deleteFront() {
        if (isEmpty()) return false; // If deque is empty, return false

        front = (front + 1) % K; // Update front pointer in circular fashion
        currCount--; // Decrement the count of elements
        return true; // Return true to indicate successful deletion
    }
    
    // Delete an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) return false; // If deque is empty, return false

        rear = (rear - 1 + K) % K; // Update rear pointer in circular fashion
        currCount--; // Decrement the count of elements
        return true; // Return true to indicate successful deletion
    }
    
    // Get the front element of the deque
    int getFront() {
        if (isEmpty()) {
            return -1; // If deque is empty, return -1
        }
        return deq[front]; // Return the front element
    }
    
    // Get the rear element of the deque
    int getRear() {
        if (isEmpty()) {
            return -1; // If deque is empty, return -1
        }
        return deq[rear]; // Return the rear element
    }
    
    // Check if the deque is empty
    bool isEmpty() {
        return currCount == 0; // Return true if there are no elements
    }
    
    // Check if the deque is full
    bool isFull() {
        return currCount == K; // Return true if the deque is full
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

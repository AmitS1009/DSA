class CustomStack {
public:
    vector<int> st;  // Stack to store the elements
    vector<int> inc; // Vector to store increment values for each element in the stack
    int n;           // Maximum size of the stack

    // Constructor to initialize the stack with a given max size
    CustomStack(int maxSize) {
        n = maxSize;
    }

    // Pushes an element onto the stack if there is room
    void push(int x) {
        if(st.size() < n) {           // Check if the stack size is less than the maximum size
            st.push_back(x);           // Push the element onto the stack
            inc.push_back(0);          // Add a corresponding 0 in the increment vector
        }
    }

    // Pops the top element from the stack and returns it with any increment applied
    int pop() {
        if(st.empty()) return -1;      // If the stack is empty, return -1

        int idx = st.size() - 1;       // Get the index of the top element
        if(idx > 0) {
            // Transfer the increment value from the top element to the one below it
            inc[idx - 1] += inc[idx];
        }
        // Add the increment value to the top element and store it in 'top_val'
        int top_val = st[idx] + inc[idx];
        st.pop_back();                 // Remove the top element from the stack
        inc.pop_back();                // Remove the corresponding increment value

        return top_val;                // Return the popped value with increment applied
    }

    // Increments the bottom k elements of the stack by a given value
    void increment(int k, int val) {
        // Find the smaller of k or the current size of the stack and adjust for 0-based index
        int idx = min(k, (int)st.size()) - 1;
        if(idx >= 0) {
            // Add the increment value to the last of the first k elements
            inc[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

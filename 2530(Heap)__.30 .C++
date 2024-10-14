// Giving TLE : 

class Solution {
public:
    long long solve(vector<int>& arr, int k) {
        // Sort the array in descending order
        sort(arr.begin(), arr.end(), greater<int>());
        
        long long sum = 0;

        // Perform the operation k times
        for (int i = 0; i < k; i++) {
            // Add the largest element to the sum
            sum += arr[0];

            // Replace the largest element with ceil(largest / 3)
            arr[0] = ceil(arr[0] / 3.0);

            // Re-sort the array to maintain order
            sort(arr.begin(), arr.end(), greater<int>());
        }
        return sum;
    }
    
    long long maxKelements(vector<int>& nums, int k) {
        return solve(nums, k);
    }
};


// Using heap to Time complexity  

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Create a max heap using a priority queue
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long sum = 0;

        // Perform the operation k times
        while (k--) {
            // Get the largest element from the heap
            int largest = maxHeap.top();
            maxHeap.pop();

            // Add the largest element to the sum
            sum += largest;

            // Update the largest element by dividing it by 3 and using ceil
            int updated = ceil(largest / 3.0);

            // Push the updated element back into the heap
            maxHeap.push(updated);
        }

        return sum;
    }
};

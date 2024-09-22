class Solution {
public:

    // Function to count the number of elements between 'curr' and 'next' in the lexicographical order
    int Count(long curr, long next, long n){
        int countNum = 0;  // Variable to keep track of the count of numbers between curr and next

        // Loop to keep counting as long as curr is within the range of n
        while(curr <= n){
            // Add the difference between 'next' and 'curr' to the count (this gives the number of elements in this range)
            countNum += (next - curr);

            // Move to the next level in the lexicographical tree by multiplying both curr and next by 10
            curr *= 10;
            next *= 10;

            // Ensure that 'next' doesn't exceed the value of n+1
            next = min(next, n+1);
        }
        return countNum;  // Return the total count of numbers between curr and next
    }

    // Function to find the k-th smallest number in lexicographical order within the range [1, n]
    int findKthNumber(int n, int k) {
        int curr = 1;  // Start with the smallest number, 1
        k -= 1;  // Since we are starting from 1, decrement k by 1

        // Loop until we find the k-th number
        while(k > 0){
            // Count the numbers between 'curr' and 'curr + 1' in lexicographical order
            int count = Count(curr, curr + 1, n);

            // If the count is less than or equal to k, move to the next sibling in lexicographical order
            if(count <= k){
                curr++;  // Move to the next sibling
                k -= count;  // Subtract the count from k
            } 
            // If the count is greater than k, move deeper into the current subtree
            else {
                curr *= 10;  // Move to the next level (i.e., first child of the current number)
                k -= 1;  // Decrement k since we are moving to the next level
            }
        }
        return curr;  // Return the k-th smallest number
    }
};

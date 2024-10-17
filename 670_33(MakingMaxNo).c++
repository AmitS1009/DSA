class Solution {
public:

    // Function to store digits of the number into a vector
    vector<int> storeDigits(long num) {
        vector<int> digits;

        // Extract digits from the number and store in reverse order
        while (num > 0) {
            int digit = num % 10; 
            digits.push_back(digit);  
            num /= 10; 
        }

        // Reverse the vector to store digits in the correct order
        reverse(digits.begin(), digits.end());  
        return digits;
    }

    int maximumSwap(int num) {
        // Step 1: Convert the number to a vector of digits
        vector<int> res = storeDigits(num);
        int n = res.size();

        // Step 2: Create a maxIdx array to store the index of the largest digit on the right side for each digit
        vector<int> maxIdx(n);

        int maxPos = n - 1;  // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            // Update maxPos if a larger digit is found
            if (res[i] > res[maxPos]) {
                maxPos = i;
            }
            // Store the position of the largest digit on the right
            maxIdx[i] = maxPos;
        }

        // Step 3: Find the first smaller digit compared to the largest digit on its right, then swap
        for (int i = 0; i < n; i++) {
            if (res[i] != res[maxIdx[i]]) {
                // Swap the current digit with the largest digit on its right
                swap(res[i], res[maxIdx[i]]);
                break;  // Only one swap is allowed, so break after the swap
            }
        }

        // Step 4: Rebuild the number from the modified digits
        int maxNumber = 0;
        for (int i = 0; i < n; i++) {
            maxNumber = maxNumber * 10 + res[i];  // Combine the digits to form the final number
        }

        return maxNumber;  // Return the maximum possible number after the swap
    }
};

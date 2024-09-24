class Solution {
public:
    // Function to find the length of the longest common prefix between numbers in two arrays
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;  // Create a set to store the prefixes of numbers in arr1

        // Step 1: Process the first array (arr1)
        for (int val : arr1) {  // Loop through each number in arr1
            while (!st.count(val) && val > 0) {  // While the value isn't already in the set and it's positive
                st.insert(val);  // Insert the number into the set

                val = val / 10;  // Reduce the number by removing the last digit (prefix reduction)
            }
        }

        // Step 2: Process the second array (arr2) to find the longest common prefix
        int result = 0;  // Variable to store the length of the longest common prefix
        for (int num : arr2) {  // Loop through each number in arr2
            while (!st.count(num) && num > 0) {  // While the number isn't in the set and it's positive
                num /= 10;  // Reduce the number by removing the last digit
            }
            if (num > 0) {  // If we find a common prefix (i.e., num is still positive after the loop)
                // Calculate the number of digits in the common prefix (log10 gives the number of digits minus 1)
                result = max(result, static_cast<int>(log10(num)) + 1);  
            }
        }

        return result;  // Return the length of the longest common prefix
    }
};

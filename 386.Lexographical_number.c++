class Solution {
public:
    void solve(int curr, int n, vector<int> &result) {
        if (curr > n) return; 
        result.push_back(curr); 

        for (int append = 0; append <= 9; append++) {
            int newNum = curr * 10 + append;
            if (newNum > n) return; 
            solve(newNum, n, result); 
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result; 
        for (int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, result);
        }
        return result; 
    }
};


//Explaination:

class Solution {
public:
    // Recursive function to generate numbers in lexicographical order
    void solve(int curr, int n, vector<int> &result) {
        if (curr > n) return; // Base case: If current number exceeds n, stop recursion
        result.push_back(curr); // Add the current number to the result

        // Try appending digits from 0 to 9 to the current number
        for (int append = 0; append <= 9; append++) {
            int newNum = curr * 10 + append;
            
            if (newNum > n) return; // If the new number exceeds n, stop exploring further (Added this check)
            solve(newNum, n, result); // Recursively explore the new number
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result; // To store the result
        
        // Start the DFS from numbers 1 to 9
        for (int startNum = 1; startNum <= 9; startNum++) {
            solve(startNum, n, result); 
        }

        return result; // Returning the result (Added this return statement)
    }
};

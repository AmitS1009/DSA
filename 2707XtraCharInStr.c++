class Solution {
public:

    int solve(int i, string& s, unordered_set<string>& st, int &n){
      if(i >= n) return 0;

      int result = 1 + solve(i+1, s, st, n);

      for(int j=i; j<n; j++){
        string curr = s.substr(i, j-i+1);
        if(st.count(curr)){
          result = min(result, solve(j+1, s, st, n));
        }
      }
      return result;
    } 

    int minExtraChar(string s, vector<string>& dict) {
      int n = s.length();
      unordered_set<string> st(begin(dict), end(dict));

      return solve(0, s, st, n);
    }
};


// this whole is fine but giving TLE : So, 

class Solution {
public:
    int t[51];
    int solve(int i, string& s, unordered_set<string>& st, int &n){
      if(i >= n) return 0;
      if(t[i] != -1) return t[i];

      int result = 1 + solve(i+1, s, st, n);

      for(int j=i; j<n; j++){
        string curr = s.substr(i, j-i+1);
        if(st.count(curr)){
          result = min(result, solve(j+1, s, st, n));
        }
      }
      return t[i] = result;
    } 

    int minExtraChar(string s, vector<string>& dict) {
      int n = s.length();
      memset(t, -1, sizeof(t));
      unordered_set<string> st(begin(dict), end(dict));

      return solve(0, s, st, n);
    }
};

// its TC : O(n*n*n), SC : O(no.of Char in Dict)
// We can store it into map as well , its not necessary to stoeru in a array


class Solution {
public:
    int solve(int i, string& s, unordered_set<string>& st, int &n,  unordered_map<int, int> mp){
      if(i >= n) return 0;
      if(mp.count(i)) return mp[i];

      int result = 1 + solve(i+1, s, st, n, mp);

      for(int j=i; j<n; j++){
        string curr = s.substr(i, j-i+1);
        if(st.count(curr)){
          result = min(result, solve(j+1, s, st, n, mp));
        }
      }
      return t[i] = result;
    } 

    int minExtraChar(string s, vector<string>& dict) {
      int n = s.length();
      unordered_map<int, int> mp;
      unordered_set<string> st(begin(dict), end(dict));

      return solve(0, s, st, n, mp);
    }
};

// its TC will be O((2^n)*n*n): very large


// Explaination : 

class Solution {
public:
    // Recursive function to solve the problem
    int solve(int i, string& s, unordered_set<string>& st, int &n, unordered_map<int, int> mp) {
        // Base case: if we've reached the end of the string, return 0 (no extra chars needed)
        if (i >= n) return 0;
        
        // Check if we've already computed the result for index i
        if (mp.count(i)) return mp[i];

        // Start with the worst case: every character from index i is an extra character
        int result = 1 + solve(i + 1, s, st, n, mp);  

        // Check for all substrings starting from index i
        for (int j = i; j < n; j++) {
            // Get the current substring from index i to j
            string curr = s.substr(i, j - i + 1);
            // If the current substring exists in the dictionary
            if (st.count(curr)) {
                // Recursively solve for the next index after the current substring
                result = min(result, solve(j + 1, s, st, n, mp));
            }
        }
        
        // Store the result in the map and return it
        return mp[i] = result;
    }

    // Main function to find the minimum extra characters needed
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();  // Length of the string
        unordered_map<int, int> mp;  // Memoization map to store results of subproblems
        unordered_set<string> st(begin(dict), end(dict));  // Create a set from the dictionary for O(1) lookups

        // Call the recursive solve function starting from index 0
        return solve(0, s, st, n, mp);
    }
};


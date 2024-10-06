class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        // Ensure that s1 is always the longer or equal length string
        if(s1.length() < s2.length()) {
            swap(s1, s2); // Swap so that s1 is always longer or equal in length
        }

        // Vectors to store the words of the two sentences
        vector<string> vec1, vec2;

        // Tokenize the first string into individual words
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) {  // Read each word separated by spaces
            vec1.push_back(token); // Add to the vector
        }

        // Tokenize the second string into individual words
        stringstream ss2(s2);
        while(ss2 >> token) {  // Read each word separated by spaces
            vec2.push_back(token); // Add to the vector
        }

        // Two pointer approach to compare the beginning and the end of the sentences
        int i = 0, j = vec1.size() - 1; // Pointers for the first sentence's start and end
        int k = 0, l = vec2.size() - 1; // Pointers for the second sentence's start and end

        // Compare words from the beginning while they match
        while(k < vec2.size() && vec2[k] == vec1[i]) {
            i++;  // Move the pointer for s1
            k++;  // Move the pointer for s2
        }

        // Compare words from the end while they match
        while(l >= k && vec2[l] == vec1[j]) {
            j--;  // Move the pointer for s1
            l--;  // Move the pointer for s2
        }

        // If all words in the shorter sentence match either from start or end, return true
        // l < k means all remaining words in the second sentence (vec2) are matched
        return l < k;
    }
};

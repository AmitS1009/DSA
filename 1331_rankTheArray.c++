class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> sorted_a = a;   // Create a copy of the array to sort
        sort(sorted_a.begin(), sorted_a.end());   // Sort the copied array
        
        // Map to store ranks of elements
        unordered_map<int, int> rank_map;
        int rank = 1;
        
        // Assign rank to elements in sorted order, skipping duplicates
        for(int i = 0; i < sorted_a.size(); i++) {
            if(rank_map.find(sorted_a[i]) == rank_map.end()) {
                rank_map[sorted_a[i]] = rank++;
            }
        }
        
        // Create the result array with the ranks of original array elements
        vector<int> result;
        for(int i = 0; i < a.size(); i++) {
            result.push_back(rank_map[a[i]]);
        }
        
        return result;
    }
};

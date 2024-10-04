class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        // Sort the players by their skill levels
        sort(skill.begin(), skill.end());

        // Initialize pointers
        int i = 0;
        int j = n - 1;

        // Sum of the first and last player's skill, which will act as a baseline
        int s = skill[i] + skill[j];

        long long chem = 0;

        while (i < j) {
            // Calculate the current pair's skill sum
            int currSkill = skill[i] + skill[j];
            
            // If the current pair's skill sum does not match the baseline, return -1
            if (currSkill != s) return -1;

            // Accumulate the chemistry (product of their skills)
            chem += (long long)skill[i] * (long long)skill[j];
            
            // Move the pointers
            i++;
            j--;
        }

        // Return the total accumulated chemistry
        return chem;
    }
};

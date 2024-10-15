// Wrong : 

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int cnt1 = 0, swap = 0;
        int j = 1; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt1++;
                while (j < n && s[j] == '0') {
                    swap += cnt1;
                    j++;
                }
            }
        }
        return swap;
    }
};

// Corrct  : 

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long cnt1 = 0, swap = 0; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                swap += cnt1;
            }
            else cnt1++;
        }
        return swap;
    }
};

Brute Force : 

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.size()) return false;
        if((s+s).find(goal) != string :: npos) return true;
        return false;
    }
};

Optimal : 

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.size()) return false;
        if((s+s).find(goal) != string :: npos) return true;
        return false;
    }
};

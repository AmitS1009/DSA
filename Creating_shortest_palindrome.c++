// giving MLE

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

       
        for(int i=0; i<s.length(); i++){

            if(s.substr(0, s.length()-i) == rev.substr(i)){
                return rev.substr(0,i)+s;
            }
        }
        return rev+s;
        
    }
};

Optimal :

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(begin(rev), end(rev));

       
        for(int i=0; i<s.length(); i++){

            if(! memcmp(s.c_str(), rev.c_str()+i, s.length()-i)){
                return rev.substr(0,i)+s;
            }
        }
        return rev+s;
        
    }
};


this is imp here :  memcmp(s.c_str(), rev.c_str()+i, s.length()-i, it return '0' , if both string are same.

#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";
    string longest = "";
    
    for (int i = 0; i < s.length(); ++i) {
        // Odd-length palindromes (single center character)
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.length() > longest.length()) {
            longest = oddPalindrome;
        }
        
        // Even-length palindromes (two center characters)
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.length() > longest.length()) {
            longest = evenPalindrome;
        }
    }
    
    return longest;
}

int main() {
    string s = "babad";
    cout << "The longest palindromic substring is: " << longestPalindrome(s) << endl;
    return 0;
}

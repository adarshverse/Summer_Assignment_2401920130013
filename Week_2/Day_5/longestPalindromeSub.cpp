// Longest Palindrome Substring

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string maxP = "";
        int i = 0;
        while (i < n) {
            int j = n - 1;
            while (j >= i) {
                if (s[i] == s[j]) {
                    if (isPalindrome(s, i, j)) {
                        string curr = s.substr(i, j - i + 1);
                        if (curr.size() > maxP.size()) {
                            maxP = curr;
                        }
                        break; 
                    }
                }
                j--;
            }
            i++;
        }

        return maxP;
    }
};
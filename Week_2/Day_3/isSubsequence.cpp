// Is Subsequence

#include<iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int occurance = s.size();
        int j = 0;
        for (int i = 0;i < t.size();i++) {
            if (s[j]==t[i]) {
                occurance--;
                j++;
            }
        }
        if(occurance != 0) return false;
        else return true;
    }
};
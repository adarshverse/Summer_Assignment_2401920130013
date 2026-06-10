// Repeated Substring Pattern

#include<iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        ss = ss.substr(1,ss.size()-2);
        if (ss.find(s) != -1) return true;
        else return false;

    }
};
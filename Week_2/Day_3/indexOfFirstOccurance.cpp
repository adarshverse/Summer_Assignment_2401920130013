// Find the index of the first occurance in a string

#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        for (int i = 0;i <= haystack.size()-needle.size();i++) {
            if (haystack.substr(i,needle.size())== needle) return i;
        }
        return -1;
    }
};
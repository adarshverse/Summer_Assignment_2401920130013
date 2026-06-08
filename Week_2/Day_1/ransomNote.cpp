// RansomeNote

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        unordered_map<char,int> np;
        for (int i = 0;i < ransomNote.size();i++) {
            mp[ransomNote[i]]++;
        }
        for (int i = 0;i < magazine.size();i++) {
            np[magazine[i]]++;
        }
        for (auto &itr : mp) {
            if (itr.second > np[itr.first]) return false;
        }
        return true;
    }
};
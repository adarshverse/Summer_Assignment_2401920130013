// Permutation in String

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        if (hash1 == hash2)
            return true;
        int j = 0;
        for (int i = s1.size(); i < s2.size(); i++) {
            hash2[s2[i] - 'a']++;
            hash2[s2[j] - 'a']--;
            j++;
            if (hash1 == hash2) return true;
        }
        return false;
    }
};
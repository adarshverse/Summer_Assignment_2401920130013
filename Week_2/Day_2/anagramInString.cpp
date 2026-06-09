// Find all the anagram in a String

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if (m>n) return ans;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for (int i=0;i<m;i++) {
            v1[p[i]-'a']++;
            v2[s[i]-'a']++;
        }
        if (v1==v2){
            ans.push_back(0);
        }
        for (int i=m;i<n;i++) {
            v2[s[i]-'a']++;
            v2[s[i-m]-'a']--;
            if (v1==v2){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};
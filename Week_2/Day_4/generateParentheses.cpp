// Generate Parentheses

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void generate(vector<string>& ans,string s,int start,int close,int n) {
        if (close == n) {
            ans.push_back(s);
            return;
        }
        if (start < n) generate(ans,s+"(",start+1,close,n);
        if (close < start) generate(ans,s+")",start,close+1,n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generate(ans,s,0,0,n);
        return ans;
    }
};
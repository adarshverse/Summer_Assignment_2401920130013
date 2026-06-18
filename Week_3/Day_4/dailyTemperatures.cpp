// Daily Temperature

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<int> s;
        ans[n-1] = 0;
        s.push(n-1);
        for (int i = n-2;i >= 0;i--) {
            while (s.size() > 0 && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (s.size()==0) ans[i] = 0;
            else ans[i] = s.top()-i;
            s.push(i);
        }
        return ans;
    }
};
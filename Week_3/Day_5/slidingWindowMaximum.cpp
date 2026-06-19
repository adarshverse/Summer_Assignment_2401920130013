// Sliding Window Maximum

#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int n = nums.size();
        stack<int> s;
        int ngi[n];
        ngi[n - 1] = n;
        s.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (s.size() > 0 && nums[s.top()] <= nums[i]) { 
                s.pop();
            } 
            if (s.size() == 0)
                ngi[i] = n;
            else
                ngi[i] = s.top();
            s.push(i);
        }
        vector<int>ans;
        int j = 0;
        for (int i = 0;i<=n-k;i++) {
            if (j < i) j = i;

            int mx = nums[j];
            while (j < i + k) {
                mx = nums[j];
                if (ngi[j] >= i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;        
    }
};
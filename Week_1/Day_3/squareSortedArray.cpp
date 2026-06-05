// Square of Sorted Array

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int idx = n-1;
        vector<int> ans(n);
        while (st <= end) {
            if (abs(nums[st]) > abs(nums[end])) {
                ans[idx] = abs(nums[st]) * abs(nums[st]);
                st++;
            }
            else {
                ans[idx] = nums[end] * nums[end];
                end--;
            }
            idx--;
        }
        return ans;
    }
};
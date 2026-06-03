// Container with most water

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int minHeight = INT_MAX;
        int maxArea = INT_MIN;
        int currArea = 0;
        int st = 0;
        int end = n-1;
        int width = 0;
        while (st < end) {
            minHeight = min(height[st],height[end]);
            width = end - st;
            currArea = minHeight * width;
            maxArea = max(currArea,maxArea);
            if (height[st] > height[end]) {
                end--;
            }
            else {
                st++;
            }
        }       
        return maxArea;  
    }
};
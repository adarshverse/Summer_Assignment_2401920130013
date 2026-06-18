// Largest Rectangle in Histogram

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int nsi[n];
        stack<int>s;
        nsi[n-1] = n;
        s.push(n-1);
        for (int i = n-2;i >= 0;i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) nsi[i] = n;
            else nsi[i] = s.top();
            s.push(i);
        }

        int psi[n];
        stack<int> g;
        psi[0] = -1;
        g.push(0);
        for (int i = 1;i < n;i++) {
            while (g.size() > 0 && heights[g.top()] >= heights[i]) {
                g.pop();
            }
            if (g.size() == 0) psi[i] = -1;
            else psi[i] = g.top();
            g.push(i);
        }

        int maxArea = 0;
        for (int i = 0;i < n;i++) {
            int height = heights[i];
            int breadth = nsi[i]-psi[i]-1;
            int area = height * breadth;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};
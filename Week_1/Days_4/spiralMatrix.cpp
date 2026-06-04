// Spiral Matrix

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size();
        int n = matrix[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = m-1;
        int maxc = n-1;
        while (minr <= maxr && minc <= maxc) {
            for (int j = minc;j <= maxc;j++) {
                v.push_back(matrix[minr][j]);
            }
            if(minr > maxr || minc > maxc) break;
            minr++;
            for (int i = minr;i <= maxr;i++) {
                v.push_back(matrix[i][maxc]);
            }
            if(minr > maxr || minc > maxc) break;
            maxc--;
            for (int j = maxc;j >= minc ;j--) {
                v.push_back(matrix[maxr][j]);
            }
            if(minr > maxr || minc > maxc) break;
            maxr--;
            for (int i = maxr;i >= minr;i--) {
                v.push_back(matrix[i][minc]);
            }
            minc++;
        }
        return v;
    }
};
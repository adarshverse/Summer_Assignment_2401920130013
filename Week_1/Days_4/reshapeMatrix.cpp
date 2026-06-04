// Reshape the Matrix

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ans(r,vector<int>(c));
        if (rows * cols != r * c) {
            return mat;
        }
        else {
            int k = 0;
            int l = 0;
            for (int i = 0;i < r;i++) {
                for (int j = 0;j < c;j++) {
                    ans[i][j] = mat[k][l];
                    l++;
                    if (l == cols) {
                        l = 0;
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
// Matrix Diagonal Sum

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
       int rows = mat.size();
       int cols = mat[0].size();
       int ans = 0;
       for (int i = 0;i < rows;i++) {
        for (int j = 0;j <cols;j++) {
            if (i == j) {
                ans += mat[i][j];
            }
        }
       }
       for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                if (i+j==n-1 && i!=j) {
                    ans += mat[i][j];
                }
            }
       }
    return ans;
    }
};
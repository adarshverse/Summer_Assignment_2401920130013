// Binary Tree Zigzag Level Order Traversal

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    void order(TreeNode* root,int curr,int level,vector<int>& v) {
        if (root==NULL) return;
        if (curr == level) {
            v.push_back(root->val);
            return;
        }
        if (level % 2 != 0) {
            order(root->left,curr+1,level,v);
            order(root->right,curr+1,level,v);
        } else {
            order(root->right,curr+1,level,v);
            order(root->left,curr+1,level,v);
        }
    }

    void levelOrder(TreeNode* root,vector<vector<int>>& ans) {
        int n = height(root);
        for (int i = 1;i <= n;i++) {
            vector<int> v;
            order(root,1,i,v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root,ans);
        return ans;
    }
};
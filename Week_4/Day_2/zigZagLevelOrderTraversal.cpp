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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool LR = true;
        while (q.size()>0) {
            int n = q.size();
            vector<int> v(n);
            for (int i=0;i<n;i++) {
                TreeNode* node = q.front();
                q.pop();
                int index;
                if (LR) {
                    index = i;
                } else {
                    index = n-1-i;
                }
                v[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(v);
            LR = !LR;
        }
        return ans;
    }
};
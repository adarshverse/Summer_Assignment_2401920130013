// Validate Binary Search Tree

#include<iostream>

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
 TreeNode* prev = NULL;
        bool flag = true;
        void inOrder(TreeNode* root) {
            if(root==NULL) return ;
            inOrder(root->left);
            if (prev != NULL) {
                if(root->val <= prev->val) {
                    flag = false;
                    return;
                }
            }
            prev = root;
            inOrder(root->right);
        }
    bool isValidBST(TreeNode* root) {
       inOrder(root);
       return flag;
    }
};
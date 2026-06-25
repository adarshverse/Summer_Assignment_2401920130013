// Diameter of Binary Tree

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
    int level(TreeNode* root) {
        if (root== NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }

    void helper(TreeNode* root,int &dia) {
        if (root== NULL) return;
        int diameter = level(root->left) + level(root->right);
        dia = max(dia,diameter);
        helper(root->left,dia);
        helper(root->right,dia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(root,dia);
        return dia;
    }
};
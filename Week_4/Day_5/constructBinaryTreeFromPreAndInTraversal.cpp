// Construct Binary Tree From Preorder and Inorder Traversal

#include<iostream>
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
    TreeNode* helper(vector<int>& pre,int preLow,int preHi,vector<int>& in,int inLow,int inHi) {
        if (preLow > preHi) return NULL;
        TreeNode* root = new TreeNode(pre[preLow]);
        if (preLow == preHi) return root;
        int i = inLow;
        while (i < inHi) {
            if (in[i]==pre[preLow]) break;
            i++;
        }
        int leftCount = i - inLow;
        int rightCount = inHi - i;
        root->left = helper(pre,preLow+1,preLow+leftCount,in,inLow,i-1);
        root->right = helper(pre,preLow+1+leftCount,preHi,in,i+1,inHi);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
};
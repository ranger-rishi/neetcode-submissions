/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root)
    {
        if(root==nullptr)
        return root;
        TreeNode* x= root->left;
        TreeNode* y = root->right;
        root->right=helper(x);
        root->left=helper(y);
        return root;

    }
    TreeNode* invertTree(TreeNode* root) {
        root=helper(root);
        return root;
    }
};

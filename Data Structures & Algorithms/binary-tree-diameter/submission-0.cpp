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
int mx=-INT_MIN;
    int helper(TreeNode* node)
    {
        if(!node)
        return 0;
        int x= helper(node->right);
        int y = helper(node->left);
        mx=max(mx,1+x+y);
        return 1+max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mx=max(mx,1+helper(root->right)+helper(root->left));
        return mx-1;
    }
};

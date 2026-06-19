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
    int helper(TreeNode* root,int mx)
    {
        if(!root)
        return 0 ;
        if(root->val>=mx)
        {
            return 1+helper(root->right,root->val)+helper(root->left,root->val);
        }
        else
        {
            return helper(root->right,mx)+helper(root->left,mx);
        }
    }
    int goodNodes(TreeNode* root) {
        int y = helper(root,-101);
        return y ;
    }
};

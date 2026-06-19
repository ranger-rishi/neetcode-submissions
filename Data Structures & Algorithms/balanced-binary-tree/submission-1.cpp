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
    int helper(TreeNode* root)
    {
        if(root==nullptr)
        return 0 ;
        else cout<<root->val<<" "<<endl;
        int x= helper(root->left);
        int y = helper(root->right);
        cout<<x<<" "<<y<<endl;
        if(abs(y-x)>1)
        return 1e6;
        else
        return 1+max(y,x);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
        return true;
        return abs(helper(root->right)-helper(root->left))<=1 && helper(root->right)<1e6 && helper(root->left)<1e6;
    }
};

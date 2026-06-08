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
//this is so easy 
//we need to implement a O(n) solution 
class Solution {
    int maxi=INT_MIN;
public:
    int helper(TreeNode* root)
    {
        if(root==nullptr)
        return 0;
        int x=helper(root->right);
        int y = helper(root->left);
        maxi=max(root->val+x+y,maxi);
        maxi=max( root->val+max(max(x,y),0),maxi);   
        return root->val+max(max(x,y),0);          
    }
    int maxPathSum(TreeNode* root) {
        int x=helper(root);
        return maxi;
    }
};

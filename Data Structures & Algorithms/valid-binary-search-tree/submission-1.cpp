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
    bool helper(TreeNode* root,int x, int y )
    {
       if(!root)
       return true;
       else
       {
            if(root->val>x && root->val<y)
            {
                return helper(root->right,root->val,y) && helper(root->left,x,root->val);
            }
            else
            return false;
       }
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,INT_MIN,+INT_MAX);
    }
};

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
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
        return true;
        if(!root && subRoot || !subRoot && root)
        return false;
        if(root->val != subRoot->val)
        return false;
        else 
        return check(root->right, subRoot->right) && check(root->left,subRoot->left);
    }
    bool helper(TreeNode* root,TreeNode* subRoot) {
        if(!root && !subRoot)
        return true;
        if(!root && subRoot || !subRoot && root)
        return false;
        if((check(root,subRoot)))
        return true;
        else
        return helper(root->right,subRoot)  || helper(root->left,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};

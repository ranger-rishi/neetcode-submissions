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
unordered_map<TreeNode*,int> m1;
    int make_map(TreeNode* root)
    {
        if(!root)
        return 0;
        else 
        return m1[root]=make_map(root->left)+make_map(root->right)+1;
    }
    int search(TreeNode* root,int k)
    {
        if(!root)
        return -1;
        if(root->left)
        {
            if(m1[root->left]+1==k)
            {
                return root->val;
            }
            else if(m1[root->left]+1<k)
            {
                return search(root->right,k-m1[root->left]-1);
            }
            else
            {
                return search(root->left,k);
            }
        }
        else
        {
            if(k==1)
            return root->val;
            else
            return search(root->right,k-1);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        //we can make a map of the no. of nodes in this 
        int x= make_map(root);
        return search(root,k);
    }
};

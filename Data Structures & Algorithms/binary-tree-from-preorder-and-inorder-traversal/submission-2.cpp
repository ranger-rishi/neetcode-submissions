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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int i , int j , int k , int l)
    {
        if(i>j || k>l)
        return nullptr;
        // if(j==i || k==l)
        // return new TreeNode(inorder[i]);
        else
        {
            TreeNode* x= new TreeNode(preorder[k]);
            int m;
            for(m=i;m<=j;m++)
            {
                if(x->val==inorder[m])
                break;
            }
            cout<<m<<" ";
            x->right=build(preorder,inorder,m+1,j,k+m-i+1,l);
            x->left=build(preorder,inorder,i,m-1,k+1,k+m-i);
            return x;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(preoder.size()==0)
        // return nullptr;
        TreeNode* x= new TreeNode(preorder[0]);
        if(preorder.size()==1)
        return x;
        int i;
        for(i= 0 ;i<preorder.size();i++)
        {
            if(inorder[i]==x->val)
            break;
        }
        x->left=build(preorder,inorder,0,i-1,1,i);
        x->right=build(preorder,inorder,i+1,inorder.size()-1,i+1,inorder.size()-1);
        return x;
    }
};

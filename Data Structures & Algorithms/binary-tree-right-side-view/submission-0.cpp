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
    void populate(vector<vector<int>>& v1, TreeNode* root,int lvl)
    {
        if(root==nullptr)
        return ;
        if(lvl==0)
        {
            vector<int> v2= {root->val};
            v1.push_back(v2);
            populate(v1,root->left,1);
            populate(v1,root->right,1);
        }
        else if(v1.size()==lvl)
        {
            vector<int> v2= {root->val};
            v1.push_back(v2);
            populate(v1,root->left,lvl+1);
            populate(v1,root->right,lvl+1);
        }
        else
        {
            v1[lvl].push_back(root->val);
            populate(v1,root->left,lvl+1);
            populate(v1,root->right,lvl+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> v1;
        populate(v1,root,0);
        vector<int> v2;
        for(int i = 0 ;i<v1.size();i++)
        {
            v2.push_back(v1[i][v1[i].size()-1]);
        }
        return v2;
    }
};

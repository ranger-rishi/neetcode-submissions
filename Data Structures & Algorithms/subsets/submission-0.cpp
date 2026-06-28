class Solution {
public:
    void populate(vector<vector<int>> &ans, vector<int>& nums,vector<int> ass,int i)
    {
        if(i==nums.size())
        ans.push_back(ass);
        else
        {            
            populate(ans,nums,ass,i+1);
            ass.push_back(nums[i]);
            populate(ans,nums,ass,i+1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ass={};
        populate(ans,nums,ass,0);
        return ans;
    }
};

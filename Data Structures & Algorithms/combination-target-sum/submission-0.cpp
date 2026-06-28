class Solution {
public:
    void populate(vector<vector<int>>& ans,vector<int> ass, vector<int>& nums, int t,int l)
    {
        if(t<0)
        return;
        if(t==0)
        {
            ans.push_back(ass);
            return;
        }
        for( int i = l ;i<nums.size();i++)
        {
            ass.push_back(nums[i]);
            populate(ans,ass,nums,t-nums[i],i);
            ass.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ass={};
        populate(ans,ass,nums,target,0);
        return ans;
    }
};

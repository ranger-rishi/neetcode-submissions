class Solution {
public:
    void populate(vector<vector<int>>& ans, vector<int> ass, unordered_map<int,int> m1, vector<int>& nums)
    {
        if(ass.size()==nums.size())
        ans.push_back(ass);
        for(int i= 0 ;i<nums.size();i++)
        {
            
            if(m1[nums[i]]==1)
            continue;
            else
            {
                ass.push_back(nums[i]);
                m1[nums[i]]=1;
                populate(ans,ass,m1,nums);
                ass.pop_back();
                m1[nums[i]]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ass={};
        unordered_map<int,int> m1;
        for(int i= 0 ;i<nums.size();i++)
        m1[nums[i]]=0;
        populate(ans,ass,m1,nums);
        return ans;
    }
};

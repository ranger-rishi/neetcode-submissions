class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m1;
        int n=nums.size();
        for(int i = 0 ;i<n;i++)
        {
            if(m1.find(nums[i])==m1.end())
            {m1[nums[i]]++;}
            else
            return true;
        }
            return false;
    }
};
        
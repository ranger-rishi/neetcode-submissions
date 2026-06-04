class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,vector<int>> m1;
        int n= nums.size();
        for(int i = 0 ;i<n;i++)
        {
             m1[nums[i]].push_back(i);   
        }
        for(int i=0;i<n;i++)
        {
            if(m1[t-nums[i]].size()!=0)
            {
                if(m1[t-nums[i]].size()==1 && m1[t-nums[i]][0]==i)
                continue;
                else
                {
                    vector<int> v1;
                    v1.push_back(min(i,m1[t-nums[i]][m1[t-nums[i]].size()-1]));
                    v1.push_back(max(i,m1[t-nums[i]][m1[t-nums[i]].size()-1]));
                    return v1;
                }
            }
        }
    }
};

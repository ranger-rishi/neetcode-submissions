class Solution {
public:
    static void two_sum(int t,vector<int>& nums,set<vector<int>>& ans)
    {
        int target=-1*nums[t];
        int n = nums.size();
        unordered_map<int,vector<int>> m1;
        for(int i =0;i<n;i++)
        {
            if(i!=t)
            m1[nums[i]].push_back(i);
        }
        for(int i = 0 ;i<n;i++)
        {
            if(i!=t)
            {
                if(m1[target-nums[i]].size()!=0)
                {
                    for(int j=0;j<m1[target-nums[i]].size();j++)
                    {
                        if(m1[target-nums[i]][j]==i)
                        continue;
                        else
                        {
                            vector<int> v= {nums[t],nums[i],target-nums[i]};
                            sort(v.begin(),v.end());
                            ans.insert(v);
                        }
                    }
                }
            }
        }

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        //n^2 is acceptable
        //for each element in nums i can perform a two sum, but this time
        //i'll have to collect all the indices instead of just one, also i'll 
        //have to make sure that the same three numbers are not there therefore
        //so lets say i have to produce 1 then i'll go and run two sum on -1 and get
        // list of indices, next up i can run this on another element
        //okay so append to a set everytime you see a triplet (in sorted order of indices)
        set<vector<int>> ans;
        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            two_sum(i,nums,ans);
        }
        vector<vector<int>> answer;
        for(auto& x:ans)
        {
            answer.push_back(x);
        }
        return answer;
    }
};

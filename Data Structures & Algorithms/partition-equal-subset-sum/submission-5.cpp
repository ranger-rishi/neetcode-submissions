class Solution {
public:
    bool check(vector<int>& nums,int i, int sum1,int sum2)
    {
        if(i==nums.size())
        return sum1==sum2;
        return check(nums,i+1,sum1+nums[i],sum2) || check(nums,i+1,sum1,sum2+nums[i]);

    }
    int dfs(vector<vector<long long>>& memo, vector<int>& nums, int i,int target)
    {
        if(target==0)
        return 1;
        if(i==nums.size())
        return 0;
        if(target<0)
        return 0;
        if(memo[i][target]!=-1)
        return memo[i][target];
        
        
        
        // if(target-nums[i]>=0)
        memo[i][target]=dfs(memo, nums,i+1,target-nums[i])
        +dfs(memo,nums,i+1,target);
        return memo[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i = 0 ;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        return false;
        else
        {
            int target=sum/2;
            vector<vector<long long >> memo(nums.size(),vector<long long>(target+1,-1));
            return dfs(memo, nums,0,target)!=0;
        }
    }
};

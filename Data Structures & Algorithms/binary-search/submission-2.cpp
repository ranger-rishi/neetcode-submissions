class Solution {
public:
    int helper(vector<int>& nums,int target, int i,int j)
    {
        if(i>j)
        return -1;
        int m = (j-i)/2+i;
        if(nums[m]<target)
        {
            return helper(nums,target,m+1,j);
        }
        else if(nums[m]>target)
        return helper(nums,target,i,m-1);
        else
        return m;
    }
    int search(vector<int>& nums, int target) {
        return helper(nums,target,0,nums.size()-1);
    }
};

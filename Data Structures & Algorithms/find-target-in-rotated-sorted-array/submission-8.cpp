class Solution {
public:
    int helper2(vector<int>& nums, int a , int b, int target)
    {
        if(a>=b)
        return nums[a]==target?a:-1;
        int mid = (a+b)/2;
        if(nums[mid]>target)
        {
            return helper2(nums,a,mid-1,target);
        }        
        else if(nums[mid]<target)
        return helper2(nums,mid+1,b,target);
        else
        return mid;
    }
    int helper(vector<int>& nums, int a , int b , int target)
    {
        if(nums[a]<nums[b])
        {
            //monotonic
            return helper2(nums,a,b,target);
        }
        else
        {
            if(a>=b)
            return nums[a]==target?a:-1;
            int mid = (a+b)/2;
            if(nums[mid]==target)
            return mid;
            if(nums[mid]>=nums[a])
            {
                //in the left part 
                if(target>nums[mid])
                {
                    //search in the left part, but before the right part
                    return helper(nums,mid+1,b,target);
                }
                else
                {
                    //search inthe left of the mid or the right part 
                    if(target>nums[a])
                    return helper(nums,a,mid-1,target);
                    else if(target<nums[a])
                   return helper(nums,mid+1,b,target);
                    else return a;
                }
            }
            else
            {
                // mid in the right part 
                if(target<nums[mid])
                {
                    //surely in the right part before mid
                    return helper(nums,a,mid-1,target);
                }
                else
                {
                    // if the target is greater than the mid element then it can either be in the 
                    // right of the rightmost or the left part 
                    if(target>=nums[a])
                    {
                        return helper(nums,a,mid-1,target);
                    }
                    else
                    {
                        return helper(nums,mid+1,b,target);
                    }
                }
            }
            
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int cur_min=1;
        int cur_max=1;
        for(auto x:nums)
        {
            int temp=cur_min*x;
            cur_min=min(x,min(cur_min*x,cur_max*x));
            cur_max=max(x,max(temp,cur_max*x));
            res=max(res,cur_max);
        }
        return res;
    }
};

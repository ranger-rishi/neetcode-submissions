class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //without using the divison operation we could just maintain the product of the previous elements 
        // and maintain the product of the 
        int n;
        n=nums.size();
        vector<int> pre(n+1,1);
        for(int i =1 ;i<=n;i++)
        {
            pre[i]=pre[i-1]*nums[i-1];
        }
        vector<int> post(n+1,1);
        for(int i = n-1; i>=0 ;i --)
        {
            post[i]=post[i+1]*nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=pre[i]*post[i+1];
        }
        return ans;
    }
};

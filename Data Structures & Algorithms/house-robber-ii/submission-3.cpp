class Solution {
public:
    int rob(vector<int>& nums) {
       int n= nums.size();
       vector<vector<int>> dp1(n+1,vector<int>(2));
       vector<vector<int>> dp2(n+1,vector<int>(2));
       dp1[1][0]=0;
       dp1[1][1]=nums[0];
       if(n==1)
       return nums[0];
       for(int i= 2;i<=n-1;i++)
       {
            dp1[i][0]=max(dp1[i-1][1],dp1[i-1][0]);
            dp1[i][1]=dp1[i-1][0]+nums[i-1];
       } 
       dp2[2][0]=0;
       dp2[2][1]=nums[1];
       for(int i= 3;i<=n;i++)
       {
            dp2[i][0]=max(dp2[i-1][1],dp2[i-1][0]);
            dp2[i][1]=dp2[i-1][0]+nums[i-1];
       } 
    //    cout<<dp2[n][0];
       return max(max(dp1[n-1][0],dp1[n-1][1]),max(dp2[n][0],dp2[n][1]));
    }
};

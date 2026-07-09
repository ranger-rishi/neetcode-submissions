class Solution {
public:
    // bool valid(int a, int b, int c , int d)
    // {
    //     return a<c && a>=0 && b>=0 && b<d;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=m-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(j==n-1 && i==m-1)
                dp[i][j]=1;
                else if(j==n-1)
                dp[i][j]=dp[i+1][j];
                else if(i==m-1)
                dp[i][j]=dp[i][j+1];
                else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    
};

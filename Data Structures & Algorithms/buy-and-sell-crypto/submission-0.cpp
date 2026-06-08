class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int k = prices[n-1];
        int n = prices.size();  
        vector<int> post(n,-1);
        int maxi=-1;
        post[n-1]=-INT_MIN+100;
        for(int i=n-2;i>=0;i--)
        {
            post[i]=max(post[i+1],prices[i+1]);
        }
        for(int i = 0 ;i<n;i++)
        {
            int profit=post[i]-prices[i];
            maxi=max(max(profit,maxi),0);
        }
        return maxi;
    }
};

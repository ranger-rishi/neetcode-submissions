class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //previous maximum height //post maximum height
        vector<int> prev(n+1,-1);
        prev[0]=-1;
        for(int i = 1 ;i<n;i++)
        {
            prev[i]=max(prev[i-1],height[i-1]);
        }
        vector<int> post(n+1,-1);
        post[n-1]=-1;
        for(int i = n-2;i>=0;i--)
        {
            post[i]=max(post[i+1],height[i+1]);
        }
        int score=0;
        for(int i = 0 ;i<n;i++)
        {
            score+=max(min(post[i],prev[i])-height[i],0);
        }
        return score;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s1;
        int n = t.size();
        if(n==1)
        {
            return {0};
        }
        vector<int> ans(n);
        ans[n-1]=0;
        s1.push(n-1);
        for(int i = n-2;i>=0;i--)
        {
            while(!s1.empty() && t[i]>=t[s1.top()])
            {
               s1.pop();
            }
            if(!s1.empty() && t[i]<t[s1.top()])
            {
                ans[i]=s1.top()-i;
            }
            else{
            ans[i]=0;
            }
            s1.push(i);
        }
        return ans;
    }
};

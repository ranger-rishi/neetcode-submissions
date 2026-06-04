class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
        int n= nums.size();
        int maxim= -1;
        for(int i = 0 ;i<n;i++)
        {
            m1[nums[i]]++;
            maxim=max(maxim,m1[nums[i]]);
        }
        vector<vector<int>> v1(n+1);
        vector<int> ans;
        for(auto x:m1)
        {
            v1[x.second].push_back(x.first);
        } 
        int t= k;
        for(int i=maxim;i>=0;i--)
        {
            int j = 0;
            while(j<v1[i].size())
            {
                if(t>0)
                {
                    ans.push_back(v1[i][j]);
                    j++;
                    t--;
                }
                else
                break;
            }
            if(t==0)
            break;
        }
        return ans;
    }
};

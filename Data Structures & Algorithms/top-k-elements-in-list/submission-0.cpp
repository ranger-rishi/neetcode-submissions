class Solution {
public:
    static bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.first==p2.first)
        return false;
        return p1.first>p2.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m1;
        int n= nums.size();
        for(int i = 0 ;i<n;i++)
        {
            m1[nums[i]]++;
        }
        vector<pair<int,int>> v1;
        int i = 0 ;
        for(auto it : m1)
        {
            pair<int,int> p3={it.second,it.first};
            v1.push_back(p3);
        }
        sort(v1.begin(),v1.end(),comp);
        vector<int> ans;
        for(i=1;i<=k;i++)
        ans.push_back(v1[i-1].second);
        return ans;
    }
};

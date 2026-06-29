class Solution {
public:
    void populate(vector<vector<int>>& ans, vector<int>& ass, set<int>& s1, unordered_map<int,int>& m1, int target, set<int>::iterator it, unordered_map<int,int> m2)
    {
        if(target<0)
        return;
        if(target==0)
        {ans.push_back(ass);
            return;
        }
        while(it!=s1.end())
        {
            int x= *it;
            if(m2[x]==m1[x]-1)
            {
                ass.push_back(x);
                m2[x]=m1[x];
                auto it2=it;
                it2++;
                populate(ans,ass,s1,m1,target-x,it2,m2);
                m2[x]--;
                ass.pop_back();
            }
            else
            {
                ass.push_back(x);
                m2[x]++;
                populate(ans,ass,s1,m1,target-x,it,m2);
                m2[x]--;
                ass.pop_back();
            }
            it++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //maybe we can pass a map alongwith the which keeps the count of every particular element in the set 
        // and we start with the same element and check if the map is overloaded or not , if it is then don't and simply continue;
        unordered_map<int,int> m1;
        set<int> s1;
        for(int i= 0 ;i<candidates.size();i++)
        {
            m1[candidates[i]]++;
            s1.insert(candidates[i]);
        }
        auto it= s1.begin();
        vector<vector<int>> ans;
        vector<int> ass={};
        unordered_map<int,int> m2;
        for(auto x:s1)
        m2[x]=0;
        populate(ans,ass,s1,m1,target,it,m2);
        return ans;
    }
};

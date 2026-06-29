class Solution {
public:
    void populate(vector<vector<int>>& ans, vector<int> ass, set<int>& s1, unordered_map<int,int>& m1, unordered_map<int,int> m2, set<int>::iterator it )
    {
        while(it!=s1.end())
        {
            int x= m1[*it];
            int y = m2[*it];
            if(x==y+1)
            {
                m2[*it]++;
                ass.push_back(*it);
                auto it2=it;
                populate(ans,ass,s1,m1,m2,++it2);
                ass.pop_back();
                m2[*it]--;
            }
            else
            {
                m2[*it]++;
                ass.push_back(*it);
                populate(ans,ass,s1,m1,m2,it);
                ass.pop_back();
                m2[*it]--;
            }   
            it++;
        }
        ans.push_back(ass);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // all possible subsets , oaky :)
        // again make a set and then start asking questions, advance the iterator if the map is full else keep it on the same
        set<int> s1;
        unordered_map<int,int> m1;
        for(int i= 0 ;i<nums.size();i++)
        {
            s1.insert(nums[i]);
            m1[nums[i]]++;
        }
        unordered_map<int,int> m2;
        vector<vector<int>> ans;
        vector<int> ass;
        for(int i = 0 ;i<nums.size();i++)
        {
            m2[nums[i]]=0;
        }
        populate(ans,ass,s1,m1,m2,s1.begin());
        return ans;
    }
};

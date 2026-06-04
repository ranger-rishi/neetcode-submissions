class Solution {
public:
    static bool comp(vector<pair<char,int>>& v1, vector<pair<char,int>>& v2)
    {
        string s1="";
        string s2="";
        for(int i = 0 ;i<v1.size();i++)
        {
            s1+=v1[i].first;
        }
        for(int i =0;i<v2.size();i++)
        {
            s2+=v2[i].first;
        }
        if(s1>=s2)
        return false;
        else
        return true;
    }
    string order(vector<pair<char,int>> v1)
    {
        string s1="";
        for(int i = 0;i<v1.size();i++)
        {
            s1+=v1[i].first;
        }
        return s1;
    }
    string reorder(vector<pair<char,int>>& v1)
    {
        vector<char> v(v1.size(),' ');
        for(int i= 0 ;i<v1.size();i++)
        {
            v[v1[i].second]=v1[i].first;
        }
        string s1="";
        for(int i =0 ;i<v1.size();i++)
        {
            s1+=v[i];
        }
        return s1;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //solution 1 : sort the characters and have the index pair
        //and then reshuffle and append to the list 
        int n = strs.size();
        vector<vector<pair<char,int>>> v1(strs.size());
        for(int i = 0 ;i<n;i++)
        {
            
            for(int j =0;j<strs[i].size();j++)
            {
                v1[i].push_back({strs[i][j],j});
            }
            sort(v1[i].begin(),v1[i].end());
        }
        sort(v1.begin(),v1.end(),comp);
        int it =1;
        vector<pair<char,int>> start= v1[0];
        vector<vector<string>> ans;
        ans.push_back({reorder(start)});
        int index=0;
        while(it<n)
        {
            if(order(v1[it])==order(start))
            {
                ans[index].push_back(reorder(v1[it]));
                it++;
            }
            else
            {
                start=v1[it];
                ans.push_back({reorder(start)});
                index++;
                it++;
            }
        }
        return ans;
    }
};

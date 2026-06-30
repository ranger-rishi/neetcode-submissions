class Solution {
public:
    bool check(string s)
    {
        if(s.size()==1)
        return true;
        string s2="";
        for(int i = 0 ;i<s.size();i++)
        {
            s2=s[i]+s2;
        }
        return s2==s;
    }
    void populate(vector<vector<string>>& ans, int i , vector<string>& ass, const vector<vector<bool>> dp,const string s,
                    const vector<vector<string>>& subs)
    {
        if(i==s.size()){
        ans.push_back(ass);
        return;}
        for(int j=i;j<s.size();j++)
        {
            if(dp[i][j])
            {
                ass.push_back(subs[i][j]);
                populate(ans,j+1,ass,dp,s,subs);
                ass.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n= s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        vector<vector<string>> subs(n,vector<string>(n,""));
        for(int i = 0 ;i<s.size();i++) {
            for(int j = i;j<s.size();j++) {
                string s1=s.substr(i,j-i+1);
                subs[i][j]=s1;
                dp[i][j]=check(s1);
            }
        }
        vector<string> ass={};
        populate(ans,0,ass,dp,s,subs);
        return ans;
    }
};

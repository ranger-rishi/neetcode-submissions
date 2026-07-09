class Solution {
public:
    unordered_map<string,int> mp;
    
    bool check(string& s, int i,vector<int>& memo)
    {
        if(memo[i]==0)
        return true;
        if(memo[i]==1)
        return false;
        if(i==s.size())
        return true;
        bool f=false;
        for(int k=i;k<s.size();k++)
        {
            if(mp.find(s.substr(i,k-i+1))!=mp.end())
            {
                f= f|check(s,k+1,memo);
                cout<<f<<endl;
            }
        }
        memo[i]=f?0:1;
        return f;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // catsincars 
        // umm maybe you can just 
        // pass it and see if it returns true anytime 
        // yeah you could just recurse you know;
        for(int i= 0 ;i<wordDict.size();i++)
        {
            mp[wordDict[i]]=1;
        }
        vector<int> memo(s.size()+1,-1);
        return check(s,0,memo);
    }
};

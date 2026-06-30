class Solution {
public:
    void populate(vector<vector<string>>& ans, vector<string> ass, vector<vector<int>>& mp,int i , const int n)
    {
        if(i==n)
        {
            ans.push_back(ass);
            return;
        }
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(mp[i][j]==0)
            {
                flag=1;
                int t=i+1;
                int block=1;
                vector<pair<int,int>> pq;
                while(t<=n-1)
                {   if(mp[t][j]!=1){
                    mp[t][j]=1;
                    pq.push_back({t,j});}
                    if(j-block>=0 && mp[t][j-block]!=1){
                    mp[t][j-block]=1;pq.push_back({t,j-block});}
                    if(j+block<=n-1 && mp[t][j+block]!=1){
                    mp[t][j+block]=1;pq.push_back({t,j+block});}
                    block++;t++;
                }
                string s= "";
                for(int l=0;l<n;l++)
                {
                    if(l==j)
                    s+='Q';
                    else
                    s+='.';
                }
                ass.push_back(s);
                populate(ans,ass,mp,i+1,n);
                ass.pop_back();
                while(!pq.empty())
                {
                    mp[pq[pq.size()-1].first][pq[pq.size()-1].second]=0;
                    pq.pop_back();
                }
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> mp(n,vector<int>(n,0));
        vector<vector<string>> ans;
        vector<string> ass;
        populate(ans,ass,mp,0,n);
        return ans;
    }
};

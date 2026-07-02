class Solution {
public:
    int dfs(int i , vector<int>& mp ,vector<vector<int>>& adj, int& count,int parent)
    {
        count--;
        for(auto x:adj[i] )
        {
            if(x==parent)
            continue;
            if(mp[x]==1)
            return 0;
            else
            {
                mp[x]=1;
                // count--;
                int z= dfs(x,mp,adj,count,i);
                if(z==0)
                return 0;
                else continue;
            }
        }
        return 1;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        //okay so we start from any node and check if every other node is travesed or not 
        int count= n;
        // lets do dfs from 0 
        // if we encounter any node twice then we return 0 from it else we return 1;
        vector<vector<int>> adj(n);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> mp(n,-1);
        mp[0]=1;
        int x= dfs(0,mp,adj,count,-1);
        if(x==1 && count==0)
        return true;
        else
        return false;
    }
};

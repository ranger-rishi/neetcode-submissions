class Solution {
public:
    void bfs(int i, vector<vector<int>>& adj, vector<int>& mp)
    {
        mp[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto l:adj[x])
            {
                if(mp[l]==-1)
                {
                    mp[l]=1;
                    q.push(l);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int count=0;
        vector<int> mp(n,-1);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i= 0 ;i<n;i++)
        {
            if(mp[i]==-1)
            {
                count++;
                cout<<1<<endl;
                bfs(i,adj,mp);
                if(n>1)
                cout<<mp[1]<<endl;
            }
        }
        return count;
    }
};

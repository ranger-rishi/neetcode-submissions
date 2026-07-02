class Solution {
public:
    void dfs(vector<pair<int,int>>& ans,vector<vector<int>>& adj,int i , int parent,vector<int>& mark,int& cycle)
    {
        mark[i]=1;
        for(auto& x:adj[i])
        {
            if(x==parent)
            continue;
            else if(mark[x]==1)
            {
                cycle=1;
                mark[x]=1;
                ans.push_back({x,i});
                return;
            }
            else
            {
                mark[x]=1;
                if(cycle!=1)ans.push_back({x,i});
                dfs(ans,adj,x,i,mark,cycle);
                if(cycle==0)ans.pop_back();
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<pair<int,int>,int> mp;
        int n= edges.size();
        vector<vector<int>> adj(edges.size()+1);
        for(int i= 0 ;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            mp[{edges[i][0],edges[i][1]}]=i;
        }
        vector<int> mark(n+1,-1);
        vector<pair<int,int>> ans;
        mark[1]=1;
        int cycle=0;
        dfs(ans,adj,1,-1,mark,cycle);
        int start= ans[ans.size()-1].second;
        cout<<start<<endl;
        vector<int> ass(2,-1);
        int prev=0;
        if(ans.size()==0)
        cout<<1<<endl;
        for(int i= 0 ;i<ans.size();i++)
        {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        int flag=1;
        for(auto x:ans)
        {
            if(x.second!=start && flag==1)
            continue;
            if(x.second==start){
                flag=0;
            continue;}
            if(mp.find({x.first,x.second})!=mp.end())
            {
                if(mp[{x.first,x.second}]>=prev)
                {
                    ass[0]=x.first;
                    ass[1]=x.second;
                    prev=mp[{x.first,x.second}];
                }
            }
            if(mp.find({x.second,x.first})!=mp.end())
            {
                if(mp[{x.second,x.first}]>=prev)
                {
                    ass[0]=x.second;
                    ass[1]=x.first;
                    prev=mp[{x.second,x.first}];
                }
            }
        }
        return ass;
    }
};

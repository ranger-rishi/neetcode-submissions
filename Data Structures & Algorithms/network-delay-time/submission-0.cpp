class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //initialize the minimum distance as INT_MAX for each
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:times)
        {
            adj[x[0]].push_back({x[1],x[2]});
            // adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<int,int>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            pair<int,int> pr=pq.top();
            pq.pop();
            if(dist[pr.second]<pr.first) continue;
            else
            dist[pr.second]=pr.first;
            for(auto x:adj[pr.second])
            {
                if(dist[x.first]>dist[pr.second]+x.second)
                {
                    dist[x.first]=dist[pr.second]+x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int maxi=-1;
        for(int i =1;i<dist.size();i++)
        {
            maxi=max(maxi,dist[i]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};

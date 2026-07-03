class Solution {
public:
    void dfs(vector<string>& path, map<string,map<string,int>>& adj, int total,int& click)
    {
        if(total==0){
            click=1;
        return ;
        }
        string s= path[path.size()-1];
        for(auto x:adj[s])
        {
            if(x.second==0)
            continue;
            else{
                path.push_back(x.first);
                adj[s][x.first]--;
                total--;
                dfs(path,adj,total,click);
                if(click)
                return;
                total++;
                adj[s][x.first]++;
                path.pop_back();
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,map<string,int>> adj;
        int total=tickets.size();
        for(auto x:tickets)
        {
            adj[x[0]][x[1]]++;
        }
        vector<string> path;
        path.push_back("JFK");
        int click=0;
        dfs(path,adj,total,click);
        return path;
    }
};

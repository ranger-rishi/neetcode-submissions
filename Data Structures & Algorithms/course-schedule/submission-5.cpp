class Solution {
public:
    bool bfs(int i, vector<vector<int>>& adj, int numCourses,vector<int> check)
    {
        check[i]=1;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int l= q.front();
            q.pop();
            for(auto x:adj[l])
            {
                if(check[x]==1 && adj[x].size()!=0){
cout<<x<<endl;    return false;}            else
                {
                    check[x]=1;
                    q.push(x);
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //we just have to detect cycles in our graph
        vector<vector<int>> adj(numCourses);
        for(auto x:prerequisites)
        {
            int z=x[0];
            int y= x[1];
            adj[y].push_back(z);
        }
        vector<int> check(numCourses,-1);
        for(int i = 0 ;i<numCourses;i++)
        {
            if(!bfs(i,adj,numCourses,check))
            return false;
        }
        return true;
    }
};

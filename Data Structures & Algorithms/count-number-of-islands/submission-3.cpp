class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i , int j , vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        if(i>vis.size()-1 || j>vis[0].size()-1)
        return;
        if(grid[i][j]=='1')
        {
            if(i>0)
            {
                if(grid[i-1][j]=='1' && vis[i-1][j]==0)
                bfs(grid,i-1,j,vis);
            }
            if(j>0)
            {
                if(grid[i][j-1]=='1' && vis[i][j-1]==0)
                bfs(grid,i,j-1,vis);
            }
            if(i<vis.size()-1)
            {
                if(grid[i+1][j]=='1' && vis[i+1][j]==0)
                bfs(grid,i+1,j,vis);
            }
            if(j<vis[0].size()-1)
            {
                if(grid[i][j+1]=='1' && vis[i][j+1]==0)
                bfs(grid,i,j+1,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int x;
        if(n==1 && m==1)
        return x=grid[0][0]=='0'?0:1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int sum=0;
        //bfs
        for(int i= 0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    bfs(grid,i,j,vis);
                    sum++;
                }
            }
        }
        return sum;
    }
};

class Solution {
public:
    int calc(vector<vector<int>>& grid, int i , int j , vector<vector<int>>& vis)
    {
        if(grid[i][j]==0)
        return 0 ;
        int x=0;
        int y = 0;
        int z= 0;
        int w=0;
        vis[i][j]=1;
        if(i>0)
        {
            if(vis[i-1][j]==0)
            x= calc(grid,i-1,j,vis);
        }
        if(j>0)
        {
            if(vis[i][j-1]==0)
            y=calc(grid,i,j-1,vis);
        }
        if(j<grid[0].size()-1)
        {
            if(vis[i][j+1]==0)
            z=calc(grid,i,j+1,vis);
        }
        if(i<grid.size()-1)
        {
            if(vis[i+1][j]==0)
            w=calc(grid,i+1,j,vis);
        }
        
        return 1+x+y+z+w;



    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int area=0;
        for(int i = 0 ;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                {
                    area=max(area,calc(grid,i,j,vis));
                }
            }
        }
        return area;
    }
};

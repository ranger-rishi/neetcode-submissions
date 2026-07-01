class Solution {
public:
    bool valid(int x, int y , int n, int m )
    {
        return x<n && x>=0 && y>=0 && y<m;
    }
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& values,int i , int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        values[i][j]=0;
        pair<int,int> p= {i,j};
        queue<pair<int,int>> q;
        q.push(p);
        while(!q.empty())
        {
            pair<int,int> pr= q.front();
            q.pop();
            for(int l=0;l<4;l++)
            {
                int x=dx[l]+pr.first;
                int y =dy[l]+pr.second;
                if(valid(x,y,n,m) && grid[x][y]!=0 && values[x][y]>values[pr.first][pr.second]+1)
                {
                    values[x][y]=values[pr.first][pr.second]+1;
                    q.push({x,y});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>> values(n,vector<int>(m,INT_MAX));
        for(int i= 0 ;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    bfs(grid,values,i,j);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j = 0 ;j<m;j++)
            {
                // cout<<values[i][j]<<endl;
                if(grid[i][j]==1 && values[i][j]==INT_MAX)
                return -1;
                else if(grid[i][j]==1 || grid[i][j]==2)
                maxi=max(maxi,values[i][j]);
                else continue;
            }
        }
        return maxi;
    }
};

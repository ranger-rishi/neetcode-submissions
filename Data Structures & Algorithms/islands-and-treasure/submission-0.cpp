class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // we have to do bfs from every treasure chest 
        for(int i = 0 ;i<grid.size();i++)
        {
            for(int j = 0 ;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    // do bfs
                    pair<int,int> p={i,j};
                    queue<pair<int,int>> q;
                    q.push(p);
                    while(!q.empty())
                    {
                        pair<int,int> pr=q.front();
                        q.pop();
                        if(pr.first>0)
                        {
                            if(grid[pr.first-1][pr.second]>grid[pr.first][pr.second]+1)
                            {
                                grid[pr.first-1][pr.second]=grid[pr.first][pr.second]+1;
                                q.push({pr.first-1,pr.second});
                            }
                        }
                        if(pr.first<grid.size()-1)
                        {
                            if(grid[pr.first+1][pr.second]>grid[pr.first][pr.second]+1)
                            {
                                grid[pr.first+1][pr.second]=grid[pr.first][pr.second]+1;
                                q.push({pr.first+1,pr.second});
                            }
                        }
                        if(pr.second>0)
                        {
                            if(grid[pr.first][pr.second-1]>grid[pr.first][pr.second]+1)
                            {
                                grid[pr.first][pr.second-1]=grid[pr.first][pr.second]+1;
                                q.push({pr.first,pr.second-1});
                            }
                        }
                        if(pr.second<grid[0].size()-1)
                        {
                            if(grid[pr.first][pr.second+1]>grid[pr.first][pr.second]+1)
                            {
                                grid[pr.first][pr.second+1]=grid[pr.first][pr.second]+1;
                                q.push({pr.first,pr.second+1});
                            }
                        }
                    }
                }
            }
        }
    }
};

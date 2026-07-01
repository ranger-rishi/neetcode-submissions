class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> visp(heights.size(),vector<int>(heights[0].size(),-1));
        vector<vector<int>> visa(heights.size(),vector<int>(heights[0].size(),-1));
        for(int i= 0 ;i<heights.size();i++)
        {
            for(int j= 0 ;j<heights[0].size();j++)
            {
                if((i==0 || j==0) && visp[i][j]==-1)
                {
                    visp[i][j]=1;
                    pair<int,int> p ={i,j};
                    queue<pair<int,int>> q;
                    q.push(p);
                    while(!q.empty())
                    {
                        pair<int,int> pr=q.front();
                        q.pop();
                        if(pr.first>0 && heights[pr.first][pr.second]<=heights[pr.first-1][pr.second] && visp[pr.first-1][pr.second]==-1)
                        {
                            visp[pr.first-1][pr.second]=1;
                            q.push({pr.first-1,pr.second});
                        }
                        if(pr.first<heights.size()-1 && heights[pr.first][pr.second]<=heights[pr.first+1][pr.second] && visp[pr.first+1][pr.second]==-1)
                        {
                            visp[pr.first+1][pr.second]=1;
                            q.push({pr.first+1,pr.second});
                        }
                        if(pr.second>0 && heights[pr.first][pr.second]<=heights[pr.first][pr.second-1] && visp[pr.first][pr.second-1]==-1)
                        {
                            visp[pr.first][pr.second-1]=1;
                            q.push({pr.first,pr.second-1});
                        }
                        if(pr.second<heights[0].size()-1 && heights[pr.first][pr.second]<=heights[pr.first][pr.second+1] && visp[pr.first][pr.second+1]==-1)
                        {
                            visp[pr.first][pr.second+1]=1;
                            q.push({pr.first,pr.second+1});
                        }
                    }
                }
                if((i==heights.size()-1 || j==heights[0].size()-1) && visa[i][j]==-1)
                {
                    visa[i][j]=1;
                    pair<int,int> p ={i,j};
                    queue<pair<int,int>> q;
                    q.push(p);
                    while(!q.empty())
                    {
                        pair<int,int> pr=q.front();
                        q.pop();
                        if(pr.first>0 && heights[pr.first][pr.second]<=heights[pr.first-1][pr.second] && visa[pr.first-1][pr.second]==-1)
                        {
                            visa[pr.first-1][pr.second]=1;
                            q.push({pr.first-1,pr.second});
                        }
                        if(pr.first<heights.size()-1 && heights[pr.first][pr.second]<=heights[pr.first+1][pr.second] && visa[pr.first+1][pr.second]==-1)
                        {
                            visa[pr.first+1][pr.second]=1;
                            q.push({pr.first+1,pr.second});
                        }
                        if(pr.second>0 && heights[pr.first][pr.second]<=heights[pr.first][pr.second-1] && visa[pr.first][pr.second-1]==-1)
                        {
                            visa[pr.first][pr.second-1]=1;
                            q.push({pr.first,pr.second-1});
                        }
                        if(pr.second<heights[0].size()-1 && heights[pr.first][pr.second]<=heights[pr.first][pr.second+1] && visa[pr.first][pr.second+1]==-1)
                        {
                            visa[pr.first][pr.second+1]=1;
                            q.push({pr.first,pr.second+1});
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i= 0 ;i<heights.size();i++)
        {
            for(int j =0 ;j<heights[0].size();j++)
            {
                if(visa[i][j]==1 && visp[i][j]==1)
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};

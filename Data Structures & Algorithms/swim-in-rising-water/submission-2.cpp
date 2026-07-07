class Solution {
public:
    bool valid(int m , int y , int n)
    {
        return m>=0 && y>=0 && y<n && m<n;
    }
    int swimInWater(vector<vector<int>>& grid) {
        //umm we check at each edge and if the water level is <=current+1, and the time 
        // taken to reach there is greater than current+1 then we push that value alongwith the coordinates there 
        // and we always check if the current values of the node is greater than the 
        // minimum time taken to reach that node or not 
        // if it is then you just delete that from the priority queue
        // return the value of time[n-1][n-1]
        vector<vector<int>> v1(grid.size(),vector<int>(grid.size()));
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j =0 ;j<n;j++)
            {
                v1[i][j]=INT_MAX;
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        v1[0][0]=grid[0][0];
        while(!pq.empty())
        {
            pair<int,pair<int,int>> x=pq.top();
            vector<int> dx={0,0,-1,1};
            vector<int> dy={1,-1,0,0};
            pq.pop();
            if(v1[x.second.first][x.second.second]<x.first)
            continue;
            for(int i=0;i<4;i++)
            {
                int m = x.second.first+dx[i];
                int y= x.second.second+dy[i];
                if(valid(m,y,n))
                {
                    if(v1[m][y]>(x.first>=grid[m][y]?x.first:x.first+grid[m][y]-x.first))
                    {v1[m][y]=(x.first>grid[m][y]?x.first:x.first+grid[m][y]-x.first);
                    pq.push({v1[m][y],{m,y}});}
                }
            }
        }
        for(int i= 0 ;i<n;i++)
        {
            for(int j =0 ;j<n;j++)
            {
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
        return v1[n-1][n-1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++)
        {
            if(pq.size()<k)
            {
                pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            }
            else
            {
                if(pq.top().first>points[i][0]*points[i][0]+points[i][1]*points[i][1])
                {
                    pq.pop();
                    pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
                }
                else
                continue;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> a={pq.top().second.first,pq.top().second.second};
            ans.push_back(a);
            pq.pop();
        }
        return ans;
    }
};

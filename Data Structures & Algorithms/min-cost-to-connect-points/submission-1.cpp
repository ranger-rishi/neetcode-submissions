class Solution {
private:

        map<pair<int,int>,int> rank;
        map<pair<int,int>,pair<int,int>> parent;
        multiset<pair<int,pair<pair<int,int>,pair<int,int>>>> edges1;
        // multiset<pair<int,pair<pair<int,int>,pair<int,int>>>> edges2;
        bool connected(pair<int,int> p1, pair<int,int> p2) 
        {
            if(get_parent(p1)==get_parent(p2))
            return true;
            return false;
        }
        template<typename T>
        void connect(T x)
        {
            
            
                pair<int,int> p1=get_parent(x.second.first);
                pair<int,int> p2 = get_parent(x.second.second);
                if(rank[p1]>rank[p2])
                {
                    parent[p2]=p1;
                    rank[p1]++;
                }
                else
                {
                    parent[p1]=p2;
                    rank[p2]++;
                }
                
            
        }
        pair<int,int> get_parent(pair<int,int> p)
        {
            if(parent[p]==p)
            return p;
            else 
            return parent[p]=get_parent(parent[p]);
        }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //umm in n^2 we could make all possible distances and then in umm then we could
        // sort those edges and use minimum spanning tree and add the weight of each edge that we have

        for(int i = 0 ;i<points.size();i++)
        {
            rank[{points[i][0],points[i][1]}]=0;
            parent[{points[i][0],points[i][1]}]={points[i][0],points[i][1]};
            for(int j = i+1;j<points.size();j++)
            {
                edges1.insert({abs(points[i][1]-points[j][1])+abs(points[i][0]-points[j][0]),{{points[i][0],points[i][1]},{points[j][0],points[j][1]}}});
            }
        }
        //so we have got the edges in sorted order 
        long long sum=0;
        int f=0;
        for (auto x:edges1)
        {
            if(connected(x.second.first,x.second.second))
            {
                // edges.erase(x);
                continue;
            }
            // edges2.insert(x);
            connect(x);
            sum+=x.first;
        }
        return sum;
    }
};

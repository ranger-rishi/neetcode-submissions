class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2)
    {
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v1= intervals;
        sort(v1.begin(),v1.end(), comp);
        int it=1;
        vector<vector<int>> v2;
        int start= v1[0][0];
        int end= v1[0][1];
        int rmax=v1[0][1];
        if(it==intervals.size())
        return intervals;
        while(it<v1.size())
        {
            
            while(it<v1.size() && v1[it][0]<=rmax)
            {
                rmax=max(rmax,v1[it][1]);
                it++;
            }
            v2.push_back({start,rmax});    
            if(it==v1.size())
            break;
            else
            {
                start= v1[it][0];
                end=v1[it][1];
                rmax=v1[it][1];
            }
                              
        }
        return v2;
    }
};

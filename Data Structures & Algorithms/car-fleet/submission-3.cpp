class Solution {
public:
    //this is stupid , this is not even correct, i need to implement some other solution
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        int n=sp.size();
        vector<pair<int,int>> fleet(n);
        stack<pair<int,int>> s1;
        for(int i = 0;i<n;i++)
        {
            fleet[i].first=pos[i];
            fleet[i].second=sp[i];
        }
        sort(fleet.begin(),fleet.end());
        for(int i=0;i<n;i++)
        {
            if(!s1.empty() && 
            (s1.top().second>fleet[i].second && 
            fleet[i].second*(fleet[i].first-s1.top().first)*1.0/(s1.top().second-fleet[i].second)+
            fleet[i].first<=target))
            {
                while(!s1.empty() && 
            (s1.top().second>fleet[i].second && 
            fleet[i].second*(fleet[i].first-s1.top().first)*1.0/(s1.top().second-fleet[i].second)+
            fleet[i].first<=target))
                s1.pop();
                s1.push(fleet[i]);
            }
            else
            s1.push(fleet[i]);
        }
        return s1.size();
    }
};

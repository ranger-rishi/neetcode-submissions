class Solution {
public:
    int search(int st,int end,vector<int>& piles,int h)
    {
        if(st==end)
        return st;
        int m = (st+end)/2;
        int hours=0;
        for(int i = 0 ;i<piles.size();i++)
        {
            hours+=ceil(piles[i]*1.0/m);
        }
        cout<<m<<" "<<hours<<endl;
        if(hours>h)
        return search(m+1,end,piles,h);
        if(hours<=h)
        return search(st,m,piles,h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //[1,4,3,2] h = 9 let k = 2, 1+2+2+1=6
        int maxi=-1;
        for(int i = 0 ;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        return search(1,maxi,piles,h);
    }
};

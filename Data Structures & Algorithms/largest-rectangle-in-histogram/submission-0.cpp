class Solution {
public:
    // [ 2 3 1 4 2 1 4 ]
    // [1 4]
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==1)
        return heights[0];
        vector<int> presmall(n);
        vector<int> postsmall(n);
        stack<int> s1;
        s1.push(0);
        presmall[0]=-1;
        postsmall[n-1]=-1;
        for(int i= 1 ;i<n;i++)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i])
            {
                s1.pop();
            }
            if(s1.empty())
            {
                presmall[i]=-1;
            }
            else
            presmall[i]=s1.top();
            s1.push(i);
        }
        while(!s1.empty())
        s1.pop();
        s1.push(n-1);
        for(int i = n-2;i>=0;i--)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i])
            {
                s1.pop();
            }
            if(s1.empty())
            postsmall[i]=-1;
            else
            postsmall[i]=s1.top();
            s1.push(i);
        }
        int area=-1;
        for(int i = 0 ;i<n;i++)
        {
            int x = presmall[i]==-1?0:presmall[i]+1;
            int y = postsmall[i]==-1?n-1:postsmall[i]-1;
            area=max(area,(y-x+1)*heights[i]);
        }
        return area;
    }
};

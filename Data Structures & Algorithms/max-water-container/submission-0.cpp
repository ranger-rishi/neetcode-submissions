class Solution {
public:
    int maxArea(vector<int>& heights) {
        //for each bar we can store the previous highest bar with its index,
        int n = heights.size();
        int pt1=0;
        int pt2=n-1;
        int maxi=-1;
        while(pt2>pt1)
        {
            maxi=max(maxi,(pt2-pt1)*(min(heights[pt1],heights[pt2])));
            if(heights[pt1]>heights[pt2])
            pt2--;
            else
            pt1++;
        }
        return maxi;
    }
};

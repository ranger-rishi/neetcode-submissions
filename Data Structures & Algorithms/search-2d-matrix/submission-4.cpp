class Solution {
public:
    int helper(vector<vector<int>>& matrix, int target, int j,int i)
    {
        int m = (j-i)/2+i;
        if(j<i)
        return false;
        int row=m/matrix[0].size();
        int col=m%matrix[0].size();
        if(target==matrix[row][col])
        return true;
        if(target<matrix[row][col])
        return helper(matrix,target,row*matrix[0].size()+col-1,i);
        else
        return helper(matrix,target,j,row*matrix[0].size()+col+1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //it's just a matter of time you've been runnin' so higgggh , this might take a while
        //to figure out now, so don't you rush it hold your head up high from the ground
        // 01 02 04 08
        // 10 11 12 13
        // 14 20 30 40
        // that means this is just a monotonic list
        return helper(matrix,target,matrix.size()*matrix[0].size()-1,0);
    }
};

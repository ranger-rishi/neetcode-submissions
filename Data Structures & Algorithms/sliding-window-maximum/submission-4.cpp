class Solution {
public:
    //dp solution goes hard
    // [ 1 2 3 -1 -2]
    // [ 2 3 -1]
    // [ 2 3 | -1 ] you have the left max of -1 and the  right max of 2,3
    // okay i am not going to implement it 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftmax(n);
        // leftmax[0]=nums[0];
        for(int i=  0 ;i<n ;i ++)
        {
            if(i%k==0)
            {
                leftmax[i]=nums[i];
            }
            else
            leftmax[i]=max(leftmax[i-1],nums[i]);
        }
        // cout<<leftmax[1];
        vector<int> rightmax(n);
        rightmax[n-1]=nums[n-1];
        int rem= n%k-1;
        for(int i = n-2;i>=0;i--)
        {
            while(rem>0 && i>=0)
            {
                rightmax[i]=max(nums[i],rightmax[i+1]);
                i--;
                rem--;
            }
            if(i<0)
            break;
            if((i+1)%k==0)
            rightmax[i]=nums[i];
            else
            rightmax[i]=max(nums[i],rightmax[i+1]);
        }
        cout<<rightmax[0];
        vector<int> ans;
        for(int i = 0;i<n-k+1;i++)
        {
            ans.push_back(max(rightmax[i],leftmax[i+k-1]));
        }
        return ans;
    }
};

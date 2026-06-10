class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        map<int,int> m1;
        for(int i = 0 ;i<k;i++)
        {
            m1[INT_MAX-(nums[i]+10000)]++;
        }
        vector<int> ans;
        ans.push_back(INT_MAX-m1.begin()->first-10000);
        int n = nums.size();
        for(int i = 1; i<n-k+1;i++)
        {
            m1[INT_MAX-nums[i-1]-10000]--;
            if(m1[INT_MAX-nums[i-1]-10000]==0)
            m1.erase(m1.find(INT_MAX-nums[i-1]-10000));
            m1[INT_MAX-nums[i+k-1]-10000]++;
            ans.push_back(INT_MAX-m1.begin()->first-10000);
        }
        return ans;
    }
};

// #include <cmath>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
        return 0;
        if(nums.size()==1)
        return 1;
        int it1 = 0;
        int maxi = 0 ;
        int it2=1;
        int k = 0;
        while(it2<n)
        {
            if(nums[it2]==nums[it2-1])
            {it2++;
            k++;
            continue;
            }
            if(nums[it2]-nums[it1]==it2-it1-k)
            {
                it2++;
                continue;
            }
            else
            {
               
                maxi=max(maxi,it2-it1-k);
                 k=0;
                it1=it2;
                it2=it1+1;
            }
        }
        maxi=max(maxi,it2-it1-k);
        return maxi;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int it=0;
        while(true)
        {
            int x= nums[it];
            if(x==-1)
            {
                return it;
            }
            else{
                nums[it]=-1;
            it=x;
            }
        }
    }
};

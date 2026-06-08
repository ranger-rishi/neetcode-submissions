class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int pt1=0;
        int pt2=n-1;
        while(pt1!=pt2)
        {
            int x=numbers[pt1]+numbers[pt2];
            if(x<target)
            {
                pt1++;
            }
            if(x>target)
            {
                pt2--;
            }
            if(x==target)
            return {pt1+1,pt2+1};
        }
    }
};

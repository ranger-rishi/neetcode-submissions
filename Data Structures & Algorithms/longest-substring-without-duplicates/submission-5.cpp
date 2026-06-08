class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char,int> m1;
        int pt1=0;
        int pt2=0;
        int maxi=0;
        while(pt1<n && pt2<n)
        {
            if(m1.find(s[pt1])==m1.end())
            {
                m1[s[pt1]]=pt1;
                maxi=max(pt1-pt2+1,maxi);
                pt1++;
            }
            else
            {
                pt2=max(m1[s[pt1]]+1,pt2);
                m1[s[pt1]]=pt1;
                maxi=max(pt1-pt2+1,maxi);
                pt1++;
            }
        }
        return maxi;
    }
};

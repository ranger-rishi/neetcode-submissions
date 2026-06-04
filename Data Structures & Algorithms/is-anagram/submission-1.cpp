class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> m1,m2;
        int n = s.size();
        int m = t.size();
        if(m!=n)
        return false;
        for(int i= 0 ;i<n;i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i = 0 ;i<n;i++)
        {
            if(m1[s[i]]==m2[s[i]])
            continue;
            else
            return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //solution 2 using a map 
        int n = strs.size();
        if(n==0)
        return {};
        unordered_map <string , vector<string> > m1;
        for(int i = 0 ;i<n;i++)
        {
            string s1= strs[i];
            sort(s1.begin(),s1.end());
            m1[s1].push_back(strs[i]);            
        }
        vector<vector<string>> ans;
        for(auto& x:m1)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};

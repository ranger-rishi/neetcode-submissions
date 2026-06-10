class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()==0)
        return "";
         unordered_map<int,int> m1;
         for(int i = 0 ;i<t.size();i++)
         {
            m1[t[i]]++;
         }             
         int req=m1.size();
         int curr=0;
         int n =s.size();
         unordered_map<int,int> m2;
         int r1=-1;
         int r2=-1;
         int pt1=0,pt2=0;
         while(pt1<=pt2 && pt2<n)
         {
            m2[s[pt2]]++;
            if(m2[s[pt2]]==m1[s[pt2]])
            curr++;
            while(curr==req)
            {
                if(pt2-pt1<r2-r1 || r1==-1 ||r2==-1)
                {
                    r2=pt2;
                    r1=pt1;
                }
                pt1++;
                m2[s[pt1-1]]--;
                if(m2[s[pt1-1]]<m1[s[pt1-1]])
                curr--;
            }
            pt2++;

         }
         if(r1==-1&& r2==-1)
         return "";
         else
         return s.substr(r1,r2-r1+1);
    }
};

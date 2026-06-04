class Solution {
public:
//can we do huffman encoding here ?? 

    string encode(vector<string>& strs) {
        string ans="";
        if(strs.size()==0)
        return "f";
        for(int i = 0;i<strs.size();i++)
        {
            string s1= strs[i];
            for(char ch: strs[i])
            {
                int x= (int)ch;
                if(ch/100 ==0)
                {
                    if(ch/10==0)
                    {
                        if(ch==0)
                        ans+="000";
                        else
                        {
                            ans+="00";
                            ans+=to_string(x);
                        }
                    }
                    else
                    {
                        ans+="0";
                        ans+=to_string(x);
                    }
                }
                else
                ans+=to_string(x);
            }
            if(s1.size()==0)
            ans+="258";
            ans+="257";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> s1;
        if(s=="f")
        return s1;
        int n = s.size();
        string s2="";
        for(int i =0;i<n;i+=3)
        {
            if(s[i]=='2' && s[i+1]=='5' && s[i+2]=='8')
            {continue;}
             if(s[i]=='2' && s[i+1]=='5' && s[i+2]=='7')
             {s1.push_back(s2);s2="";continue;}
             int y = stoi(s.substr(i,3));
             s2+=(char)y;

        }
        return s1;


    }
};

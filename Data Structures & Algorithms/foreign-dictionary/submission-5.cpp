class Solution {
public:
    unordered_map<char,set<char>> mp;   
    string foreignDictionary(vector<string>& words) {
        vector<int> in_deg(257,0);
        int n = words.size();
        int it =0;
        int maxi=0;
        for(int i= 0 ;i<n;i++)
        maxi=max(maxi,(int)words[i].size());
        vector<vector<int>> compared(n,vector<int>(n,-1));
        set<char> s1;
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<words[i].size();j++)
            {
                s1.insert(words[i][j]);
                in_deg[words[i][j]]=0;
            }
        }
        int total_chars=s1.size();
        // set<int> zero_deg;
        // for(auto x:s1)
        // {
        //     zero_deg.insert(x);
        // }
        for(int i =0 ;i<maxi;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(compared[j][j+1]==-1)
                {
                    if((words[j].size()>i) && (words[j+1].size()<=i))
                    return "";
                    else if(words[j].size()>i && words[j+1].size()>i )
                    {
                        if(words[j][i]!=words[j+1][i])
                        {
                            // cout<<words[j][i]<<" "<<words[j+1][i]<<endl;
                            // in_deg[words[j+1][i]]++;
                            s1.erase(words[j+1][i]);
                            if(mp[words[j][i]].insert(words[j+1][i]).second) in_deg[words[j+1][i]]++;
                            compared[j][j+1]=1;
                        }
                        else
                        continue;
                    }
                    else if(words[j].size()>i && words[j+1].size()<=i)
                    {
                        compared[j][j+1]=1;
                    }
                    else 
                    continue;
                }
            }            
        }
        string s="";
        queue<char> q;
        for(auto x:s1)
        q.push(x);
        while(!q.empty())
        {
            char ch= q.front();
            q.pop();
            s+=ch;
            for(auto x:mp[ch])
            {
                if(in_deg[x]==1)
                {
                    in_deg[x]=0;
                    q.push(x);
                }
                else
                in_deg[x]--;
            }
        }
        if(s.size()==total_chars)
        {
            return s;
        }
        return "";
    }
};

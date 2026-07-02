class Solution {
public:
    bool valid(string a, string b)
    {
        int count=0;
        for(int i= 0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            count++;
        }
        return count==1;
    }
    void generate(map<string,vector<string>>& mp,vector<string>& wordList, string beginWord, string endWord)
    {
        for(int i= 0 ;i<wordList.size();i++)
        {
            for(int j = i+1;j<wordList.size();j++)
            {
                if(valid(wordList[i],wordList[j]))
                {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
            if(valid(beginWord,wordList[i]))
            {
                mp[wordList[i]].push_back(beginWord);
                mp[beginWord].push_back(wordList[i]);
            }
            // if(valid(endWord,wordList[i]))
            // {
            //     mp[wordList[i]].push_back(endWord);
            //     mp[endWord].push_back(wordList[i]);
            // }
        }        
    }
    void bfs(string beginWord,map<string,vector<string>>& mp, map<string,int>& m1,string endWord)
    {
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(s==endWord)
            break;
            for(auto x:mp[s])
            {
                if(m1[x]>m1[s]+1)
                {
                    q.push(x);
                    m1[x]=m1[s]+1;
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //this is actually pretty easy
        map<string,vector<string>> mp;
        generate(mp,wordList,beginWord,endWord);
        map<string,int> m1;
        for(int i=0;i<wordList.size();i++)
        {
            m1[wordList[i]]=INT_MAX;
        }
        m1[beginWord]=1;
        m1[endWord]=INT_MAX;
        bfs(beginWord,mp,m1,endWord);
        return m1[endWord]==INT_MAX?0:m1[endWord];
    }
};

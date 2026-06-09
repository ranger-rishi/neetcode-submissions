class Solution {
public:
    pair<char,int> find_max(unordered_map<int,int>& m1)
    {
        int maxi= -1;
        char element='A';
        for(auto& x:m1)
        {
            if(x.second>maxi)
            {
                element=x.first;
                maxi=x.second;
            }
        }
        return {element,maxi};
    }
    int characterReplacement(string s, int k) 
    {
        //upper english characters, replacement on any of the characters atmost k times, 
        // what we wanna do is return the lenght of the longest substring containting the
        //same letter you can get after performing above operation
        // s= "AABBCDEFGGGGH" k = 1 , so here our answer would obviously be 5, 
        // now how do we do this we take everysubstring and check for the most occuring element
        // in that substring but that would be O(n^2) , so we use two pointers,
        // we advance the pointer1 and check if it is possible to do our removal operation there
        // yeah just advance the previous pointer,, that's it
        int n= s.size();
        unordered_map<int,int> m1 ;
        int pt1=0,pt2=0;
        if(n==1)
        return 1;
        char max_char=s[0];
        int max_freq=1;
        m1[max_char]++;
        int maxi=-1;
        while(pt1>=pt2 && pt1<n && pt2<n)
        {
            int length =pt1-pt2+1;
            if(max_freq>=length-k)
            {
                pt1++;
                m1[s[pt1]]++;
                if(m1[s[pt1]]>max_freq)
                {
                    max_char=s[pt1];
                    max_freq=m1[s[pt1]];
                }
                maxi=max(length,maxi);
            }
            else
            {
                m1[s[pt2]]--;
                if(max_char==s[pt2])
                {
                    max_char=find_max(m1).first;
                    max_freq=find_max(m1).second;
                }
                pt2++;
            }
        }
        return maxi;
    }
};

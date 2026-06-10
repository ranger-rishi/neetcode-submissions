class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> s1;
        int n = s.size();
        for(int i = 0 ;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]== '[')
            {
                s1.push(i);
            }
            else
            {
                if(s1.empty())
                return false;
                int x= s1.top();
                if((s[x]=='(' && s[i]==')') ||(s[x]=='{' && s[i]=='}') ||(s[x]=='[' && s[i]==']')  )
                s1.pop();
                else
                return false;
            }
        }
        if(s1.size()!=0)
        return false;
        return true;
    }
};

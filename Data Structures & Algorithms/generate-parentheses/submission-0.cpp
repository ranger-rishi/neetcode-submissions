class Solution {
public:
    void populate(vector<string>& ans, string ass, int no , int n,int top)
    {
        if(no==n)
        {
            while(top--)
            ass.push_back(')');
            ans.push_back(ass);
            return;
        }
        else
        {
            // case 1: add another '('
            ass.push_back('(');
            no++;
            top++;
            populate(ans,ass,no,n,top);
            ass.pop_back();
            top--;
            no--;
            if(top!=0)
            {
                ass.push_back(')');
                top--;
                populate(ans,ass,no,n,top);
                ass.pop_back();
                top++;
            }
            else
            return;

        }
    }
    vector<string> generateParenthesis(int n) {
        string ass;
        vector<string> ans;
        int no=0;
        int top=0;
        populate(ans,ass,no,n,top);
        return ans;
    }
};

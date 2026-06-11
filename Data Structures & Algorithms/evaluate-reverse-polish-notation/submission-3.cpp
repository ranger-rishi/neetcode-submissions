class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // ((1+2) * 3)-4 =5--> now how do we do it 
        // what to do, lets say that we're given this string and it doesn't seem to have uniform
        //spacing so what do we do, we elminitate the ' ' character, get to the poitn
        // we keep pushing things on the stack till the top element is an operand, 
        //if it as operand then we solve and push that value back and if we encounter a closed par
        //-entheses then we take out the previous element and add it at the top , this is so easy
        stack<string> s1;
        int n = tokens.size();
        for(int i = 0 ;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="*"|| tokens[i]=="/"||tokens[i]=="-")
            {
                int y= stoi(s1.top());
                s1.pop();
                int x =stoi(s1.top());
                s1.pop();
                int ans;
                if(tokens[i]=="+")
                {
                    ans=x+y;
                }
                else if(tokens[i]=="*")
                {
                    ans=x*y;
                }
                else if(tokens[i]=="/")
                {
                    ans=x/y;
                }
                else
                ans=x-y;
                s1.push(to_string(ans));
            }
            else
            s1.push(tokens[i]);  
            cout<<s1.top()<<endl;          
        }
        return stoi(s1.top());
    }
};

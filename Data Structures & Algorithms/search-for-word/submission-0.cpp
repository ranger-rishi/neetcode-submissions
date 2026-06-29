class Solution {
public:
    bool check(vector<vector<char>>& board,int i , int j , int n ,string word, vector<vector<int>> m1)
    {
        if(n==word.size()-1)
        return true;
        bool check1=false,check2=false,check3=false,check4=false;
        if(i!=0)
        {
            if(board[i-1][j]==word[n+1] && m1[i-1][j]!=1){
                m1[i-1][j]=1;
            check1= check(board,i-1,j,n+1,word,m1);
            m1[i-1][j]=0;
            }
        }
        if(j!=0)
        {
            if(board[i][j-1]==word[n+1] && m1[i][j-1]!=1){
                m1[i][j-1]=1;
            check2= check(board,i,j-1,n+1,word,m1);
            m1[i][j-1]=0;
            }
        }
        if(i!=board.size()-1)
        {
            if(board[i+1][j]==word[n+1] && m1[i+1][j]!=1){
                m1[i+1][j]=1;
            check3= check(board,i+1,j,n+1,word,m1);
            m1[i+1][j]=0;
            }
        }
        if(j!=board[0].size()-1)
        {
            if(board[i][j+1]==word[n+1] && m1[i][j+1]!=1){
                m1[i][j+1]=1;
            check4= check(board,i,j+1,n+1,word,m1);
            m1[i][j+1]=0;
            }
        }
        return check1 || check2 || check3 || check4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> m1(board.size(),vector<int>(board[0].size(),0));
        // for(int i= 0 ;i<board.size();i++)
        // {
        //     for(int j = 0 ;j<board[i].size();j++)
        //     m1[{i,j}]=0;
        // }
        bool state=false;
        for(int i =0 ;i <board.size();i++)
        {
            for(int j=  0 ;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    m1[i][j]=1;
                    state=check(board,i,j,0,word,m1);
                    if(state==true)
                    return true;
                    m1[i][j]=0;
                }
            }
        }
        return state;
    }
};

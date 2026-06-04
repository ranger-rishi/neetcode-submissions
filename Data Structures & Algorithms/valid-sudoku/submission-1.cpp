class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0;i<9;i++)
        {
            vector<int> v1(10,-1);
            for(int j = 0 ;j<9;j++)
            {
                if(board[i][j]=='.')
                continue;
                if(v1[board[i][j]-'0']!=-1)
                return false;
                v1[board[i][j]-'0']=1;
            }
        }
        for(int i = 0;i<9;i++)
        {
            vector<int> v1(10,-1);
            for(int j = 0 ;j<9;j++)
            {
                if(board[j][i]=='.')
                continue;
                if(v1[board[j][i]-'0']!=-1)
                return false;
                v1[board[j][i]-'0']=1;
            }
        }
        for(int i = 0 ;i<9;i++)
        {
            int row= i/3*3;
            int col = i%3*3;
            vector<int> v1(10,-1);
            for(int j = 0;j<9;j++)
            {
                if(board[row+j/3][col+j%3]=='.')
                continue;
                if(v1[board[row+j/3][col+j%3]-'0']!=-1)
                return false;
                v1[board[row+j/3][col+j%3]-'0']=1;
            }
        }
        return true;
    }
};

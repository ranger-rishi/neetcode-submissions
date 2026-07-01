class Solution {
public:
    bool valid(int a, int b, int c ,int d, int e, int f)
    {
        return a+c>=0 && a+c<e && b+d>=0 && b+d<f;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> mark(board.size(),vector<int>(board[0].size(),0));
        for(int j=0;j<board[0].size();j++)
        {
            int i = 0;
            if(board[i][j]=='O' && mark[i][j]==0)
            {
                mark[i][j]=1;
                pair<int,int> p={i,j};
                vector<int> dx={0,0,1,-1};
                vector<int> dy={1,-1,0,0};
                queue<pair<int,int>> q;
                q.push(p);
                while(!q.empty())
                {
                    pair<int,int> pr=q.front();
                    q.pop();
                    for(int l = 0 ; l<4;l++)
                    {
                        if(valid(pr.first,pr.second,dx[l],dy[l],board.size(),board[0].size()) && 
                        board[pr.first+dx[l]][pr.second+dy[l]]=='O' && mark[pr.first+dx[l]][pr.second+dy[l]]==0 )
                        {
                            mark[pr.first+dx[l]][pr.second+dy[l]]=1;
                            q.push({pr.first+dx[l],pr.second+dy[l]});
                        }
                    }
                }
            }
            i=board.size()-1; 
            if(board[i][j]=='O' && mark[i][j]==0)
            {
                mark[i][j]=1;
                pair<int,int> p={i,j};
                vector<int> dx={0,0,1,-1};
                vector<int> dy={1,-1,0,0};
                queue<pair<int,int>> q;
                q.push(p);
                while(!q.empty())
                {
                    pair<int,int> pr=q.front();
                    q.pop();
                    for(int l = 0 ; l<4;l++)
                    {
                        if(valid(pr.first,pr.second,dx[l],dy[l],board.size(),board[0].size()) && 
                        board[pr.first+dx[l]][pr.second+dy[l]]=='O' && mark[pr.first+dx[l]][pr.second+dy[l]]==0 )
                        {
                            mark[pr.first+dx[l]][pr.second+dy[l]]=1;
                            q.push({pr.first+dx[l],pr.second+dy[l]});
                        }
                    }
                }
            }           
        }
        for(int i=0;i<board.size();i++)
        {
            int j = 0;
            if(board[i][j]=='O' && mark[i][j]==0)
            {
                mark[i][j]=1;
                pair<int,int> p={i,j};
                vector<int> dx={0,0,1,-1};
                vector<int> dy={1,-1,0,0};
                queue<pair<int,int>> q;
                q.push(p);
                while(!q.empty())
                {
                    pair<int,int> pr=q.front();
                    q.pop();
                    for(int l = 0 ; l<4;l++)
                    {
                        if(valid(pr.first,pr.second,dx[l],dy[l],board.size(),board[0].size()) && 
                        board[pr.first+dx[l]][pr.second+dy[l]]=='O' && mark[pr.first+dx[l]][pr.second+dy[l]]==0 )
                        {
                            mark[pr.first+dx[l]][pr.second+dy[l]]=1;
                            q.push({pr.first+dx[l],pr.second+dy[l]});
                        }
                    }
                }
            }
            j=board[0].size()-1; 
            if(board[i][j]=='O' && mark[i][j]==0)
            {
                mark[i][j]=1;
                pair<int,int> p={i,j};
                vector<int> dx={0,0,1,-1};
                vector<int> dy={1,-1,0,0};
                queue<pair<int,int>> q;
                q.push(p);
                while(!q.empty())
                {
                    pair<int,int> pr=q.front();
                    q.pop();
                    for(int l = 0 ; l<4;l++)
                    {
                        if(valid(pr.first,pr.second,dx[l],dy[l],board.size(),board[0].size()) && 
                        board[pr.first+dx[l]][pr.second+dy[l]]=='O' && mark[pr.first+dx[l]][pr.second+dy[l]]==0 )
                        {
                            mark[pr.first+dx[l]][pr.second+dy[l]]=1;
                            q.push({pr.first+dx[l],pr.second+dy[l]});
                        }
                    }
                }
            }           
        }
        vector<vector<char>> ans(board.size(),vector<char>(board[0].size(),'0'));
        for(int i= 0 ;i<board.size();i++)
        {
            for(int j= 0 ;j<board[0].size();j++)
            {
                if(mark[i][j]==0)
                board[i][j]='X';
            }            
        }
    }
};

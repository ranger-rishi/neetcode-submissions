class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        queue<pair<int,char>> q;
        unordered_map<int,int> m1;
        for(int i= 0 ;i<tasks.size();i++)
        {
            m1[tasks[i]]++;
        }
        for(auto x:m1)
        {
            pq.push({x.second,x.first});
        }
        int num=0;
        int nr=0;
        while(nr!=0 || !pq.empty())
        {
            if(q.size()==n+1)
            {
                if(q.front().first!=-1)
                {
                pq.push(q.front());
                q.pop();
                nr--;
                }
                else{
                    q.pop();
                }
                
            }
            if(pq.empty())
            {
                num++;
                q.push({-1,'#'});
                continue;
            }            
            pair<int,char> y= pq.top();
            num++;
            if(y.first>1)
            {q.push({y.first-1,y.second});nr++;}
            else
            q.push({-1,'#'});
            pq.pop();
        }
        return num;
    }
};

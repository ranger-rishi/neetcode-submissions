class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int i= 0 ;i<n;i++){
            pq.push(stones[i]);
        }
        // if(!pq.size())
        // return 0 ;
        while(pq.size()>1)
        {
            int x= pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x==y)
            continue;
            else
            pq.push(abs(x-y));
        }
        if(pq.size())
        return pq.top();
        return 0;
    }
};

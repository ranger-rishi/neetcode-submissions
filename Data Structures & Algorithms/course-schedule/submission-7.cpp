class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //kahn's algorithm
        // all the courses which don't have any dependencies
        // if we haven't covered all courses but our queue is 0 that means its wrong else it's right
        vector<int> dpnd(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i= 0 ;i<prerequisites.size();i++)
        {
            dpnd[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        int num=numCourses;
        for(int i=0;i<numCourses;i++)
        {
            if(dpnd[i]==0)
            {
                cout<<1<<endl;
                q.push(i);
                num--;
            }
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(auto y :adj[x])
            {
                dpnd[y]--;
                if(dpnd[y]==0){
                    q.push(y);
                    num--;
                }
            }
        }
        cout<<num<<endl;
        if(num!=0)
        return false;
        else
        return true;
    }
};

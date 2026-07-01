class Twitter {
public:
    // we may have a seperate tree storing the posts for each of them and when we are retrieving the posts,
    // iterate though everyone of them and just go gogog o
    unordered_map<int,vector<pair<int,int>>> m1;
        unordered_map<int,set<int>> m2;
        long long counter;
    Twitter() {
        
         counter=0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(m1.find(userId)==m1.end())
        {
            vector<pair<int,int>> q;
            q.push_back({counter,tweetId});
            counter++;
            m1[userId]=q;
        }
        else
        {
            m1[userId].push_back({counter,tweetId});
            counter++;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<pair<pair<pair<int,int>,int>,int>> p1;
        vector<int> ans;
        //initial build;
        if(m1.count(userId) && m1[userId].size() != 0)
        p1.push_back({{{m1[userId][m1[userId].size()-1]},userId},m1[userId].size()-1});
        for(auto x:m2[userId])
        {
            if(m1.count(x) && m1[x].size() != 0 )
            p1.push_back({{m1[x][m1[x].size()-1],x},m1[x].size()-1});
        }
        priority_queue<pair<pair<pair<int,int>,int>,int>> pq(p1.begin(),p1.end());
        while(!pq.empty() && ans.size()<10)
        {
            pair<pair<pair<int,int>,int>,int> pr=pq.top();
            pq.pop();
            ans.push_back(pr.first.first.second);
            int id=pr.second;
            id--;
            int user=pr.first.second;
            if(id>=0)
            pq.push({{{m1[user][id]},user},id});
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)
        return;
        m2[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m2[followerId].erase(followeeId);
    }
};

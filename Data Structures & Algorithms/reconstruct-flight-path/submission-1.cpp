class Solution {
public:
    map<string, multiset<string>> adj;
    vector<string> ans;

    void dfs(string u) {
        while (!adj[u].empty()) {
            auto it = adj[u].begin();      // smallest destination
            string v = *it;
            adj[u].erase(it);              // consume the ticket
            dfs(v);
        }

        ans.push_back(u);                  // add after all edges are used
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto &t : tickets)
            adj[t[0]].insert(t[1]);

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
class TimeMap {
public:
    map<string, set<pair<int,string>>> m1;

    void set(string key, string value, int timestamp) {
        timestamp = 10000000 - timestamp;
        m1[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto mit = m1.find(key);

        if (mit == m1.end())
            return "";

        timestamp = 10000000 - timestamp;

        auto it = mit->second.lower_bound({timestamp, ""});

        if (it == mit->second.end())
            return "";

        return it->second;
    }
};
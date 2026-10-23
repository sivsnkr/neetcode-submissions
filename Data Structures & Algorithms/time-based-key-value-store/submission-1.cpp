class TimeMap {
    unordered_map<string, vector<pair<int,string>>> st;
public:
    TimeMap() {
        st.clear();
    }
    
    void set(string key, string value, int timestamp) {
        st[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &kst = st[key];
        if(kst.empty()) return "";

        auto lit = lower_bound(kst.begin(), kst.end(), make_pair(timestamp + 1, ""));
        if(lit == kst.begin()) return "";
        lit--;
        return lit->second;
    }
};

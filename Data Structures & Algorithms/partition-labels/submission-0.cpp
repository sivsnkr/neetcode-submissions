class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.length();

        for(int i = n - 1; i >= 0; i--) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            }
        }

        vector<int> res;
        int cm = 0;
        int l = 0;
        for(int i = 0; i < n; i++) {
            cm = max(cm, mp[s[i]]);
            if(cm == i) {
                res.push_back(i - l + 1);
                l = i + 1;
                cm = i + 1;
            }
        }

        return res;
    }
};

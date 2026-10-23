class Solution {
    bool ispos(unordered_map<char,int> &cnt, int k) {
        int mxc = 0;
        int tot = 0;
        for(auto &it : cnt) {
            mxc = max(mxc, it.second);
            tot += it.second;
        }

        if(tot - mxc > k) return false;
        return true;
    }
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, res = 0;
        unordered_map<char, int> cnt;
        while(j < s.length()) {
            cnt[s[j]]++;
            while(!ispos(cnt, k)) {
                cnt[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};

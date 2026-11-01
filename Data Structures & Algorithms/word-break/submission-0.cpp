class Solution {
    vector<int> mem;
    bool rec(string &s, int i, vector<string> &wordDict) {
        if(i == s.length()) return true;

        if(mem[i] != -1) return mem[i];

        for(int it = i; it < s.length(); it++) {
            string ss = s.substr(i, it - i + 1);
            if(binary_search(wordDict.begin(), wordDict.end(), ss) && rec(s, it + 1, wordDict)) return mem[i] = true;
        }

        return mem[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        mem.assign(s.length(), -1);
        return rec(s, 0, wordDict);
    }
};

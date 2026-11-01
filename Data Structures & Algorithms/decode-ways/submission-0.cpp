class Solution {
    vector<int> mem;
    int rec(string &s, int i) {
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;

        if(mem[i] != -1) return mem[i];

        int val = rec(s, i + 1);
        if(i < s.length() - 1) {
            string subs = s.substr(i, 2);
            if(subs >= "10" && subs <= "26") {
                val += rec(s, i + 2);
            }
        }

        return mem[i] = val;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        mem.assign(n, -1);
        return rec(s, 0);
    }
};

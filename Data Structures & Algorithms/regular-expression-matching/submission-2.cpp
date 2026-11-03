class Solution {
    vector<vector<int>> mem;
    bool rec(int i, int j, string &s, string &p) {
        if(j == p.length()) {
            if(i == s.length()) return true;
            return false;
        }

        if(mem[i][j] != -1) return mem[i][j];

        bool res = false;

        if(j + 1 < p.length() && p[j + 1] == '*') {
            res = rec(i, j + 1, s, p);
        }else if(p[j] == '.') {
            if(i == s.length()) res = false;
            else res = rec(i + 1, j + 1, s, p);
        }else if(p[j] == '*') {
            for(int it = i; it <= s.length(); it++) {
                res = res || rec(it, j + 1, s, p);
                if(it < s.length() && p[j - 1] != '.' && s[it] != p[j - 1]) break;
            }
        } else {
            if(i < s.length() && s[i] == p[j]) res = rec(i + 1, j + 1, s, p);
            else res = false;
        }

        return mem[i][j] = res;
    }
public:
    bool isMatch(string s, string p) {
        mem.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return rec(0, 0, s, p);
    }
};

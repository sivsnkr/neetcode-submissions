class Solution {
    vector<vector<vector<int>>> mem;
    bool rec(int i, int j, int ci, string &s1, string &s2, string &s3) {
        if(ci == s3.length()) {
            if(i == s1.length() && j == s2.length()) return true;
            return false;
        }

        if(mem[i][j][ci] != -1) return mem[i][j][ci];

        bool res = false;
        if(i < s1.length() && s1[i] == s3[ci]) {
            res = rec(i + 1, j, ci + 1, s1, s2, s3);
        }

        if(j < s2.length() && s2[j] == s3[ci]) {
            res = res || rec(i, j + 1, ci + 1, s1, s2, s3);
        }

        return mem[i][j][ci] = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        mem.assign(s1.length() + 1, vector<vector<int>>(s2.length() + 1, vector<int>(s3.length() + 1, -1)));
        return rec(0, 0, 0, s1, s2, s3);
    }
};

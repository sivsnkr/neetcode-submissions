class Solution {
    void calres(pair<int,int> &res, int i, int j) {
        if(res.first == -1) {
            res = make_pair(j, i);
        }else if(res.second - res.first + 1 < i - j + 1) {
            res = make_pair(j, i);
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        pair<int,int> res = make_pair(-1, -1);

        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(i == j) {
                    dp[j][i] = 1;
                    calres(res, i, j);
                    continue;
                }else if(i - j == 1) {
                    dp[j][i] = (s[i] == s[j]);
                    if(dp[j][i])
                        calres(res, i, j);
                    continue;
                }

                if(s[i] == s[j]) {
                    dp[j][i] = dp[j + 1][i - 1];
                }else {
                    dp[j][i] = 0;
                }

                if(dp[j][i]) calres(res, i, j);
            }
        }

        return s.substr(res.first, res.second - res.first + 1);
    }
};

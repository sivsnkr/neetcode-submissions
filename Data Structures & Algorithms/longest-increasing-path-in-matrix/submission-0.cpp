class Solution {
    vector<int> io {-1, 1, 0, 0};
    vector<int> jo {0, 0, -1, 1};

    bool isvalidInd(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }

    int rec(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &dp, vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(!isvalidInd(i, j, n, m) || vis[i][j] == 1) return 0;
        if(vis[i][j] == 2) return dp[i][j];

        vis[i][j] = 1;

        int res = 0;
        for(int it = 0; it < 4; it++) {
            int ni = i + io[it], nj = j + jo[it];
            if(isvalidInd(ni, nj, n, m) && matrix[ni][nj] > matrix[i][j]) {
                res = max(res, rec(ni, nj, vis, dp, matrix));
            }
        }

        vis[i][j] = 2;

        return dp[i][j] = res + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int mx = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    mx = max(mx, rec(i, j, vis, dp, matrix));
                }
            }
        }

        return mx;
    }
};

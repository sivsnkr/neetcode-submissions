class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> atl(n, vector<bool>(m, 0));
        vector<vector<bool>> pas(n, vector<bool>(m, 0));

        queue<tuple<char, int, int>> qu;
        for(int i = 0; i < n; i++) {
            qu.emplace('P', i, 0);
            pas[i][0] = 1;
        }

        for(int j = 0; j < m; j++) {
            qu.emplace('P', 0, j);
            pas[0][j] = 1;
        }

        for(int i = 0; i < n; i++) {
            qu.emplace('A', i, m - 1);
            atl[i][m - 1] = 1;
        }

        for(int j = 0; j < m; j++) {
            qu.emplace('A', n - 1, j);
            atl[n - 1][j] = 1;
        }

        vector<int> ipos {-1, 0, 0, 1};
        vector<int> jpos {0, -1, 1, 0};

        while(!qu.empty()) {
            auto [ch, i, j] = qu.front();
            qu.pop();

            for(int it = 0; it < 4; it++) {
                int ni = i + ipos[it];
                int nj = j + jpos[it];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m) { 
                    if(ch == 'A' && atl[ni][nj]) continue;
                    else if(ch == 'P' && pas[ni][nj]) continue;

                    if(heights[ni][nj] >= heights[i][j]) {
                        if(ch == 'A') atl[ni][nj] = true;
                        else pas[ni][nj] = true;
                        qu.emplace(ch, ni, nj);
                    }
                }
            }
        }

        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(atl[i][j] && pas[i][j]) {
                    res.emplace_back(vector<int>{i, j});
                }
            }
        }

        return res;
    }
};

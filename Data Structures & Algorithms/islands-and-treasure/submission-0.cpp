class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> qu;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    qu.emplace(0, i, j);
                }
            }
        }

        vector<int> ipos {-1, 0, 0, 1};
        vector<int> jpos {0, -1, 1, 0};

        while(!qu.empty()) {
            auto [dist, i, j] = qu.front();
            qu.pop();

            for(int it = 0; it < 4; it++) {
                int ni = i + ipos[it];
                int nj = j + jpos[it];

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == INT_MAX) {
                    grid[ni][nj] = dist + 1;
                    qu.emplace(dist + 1, ni, nj);
                }
            }
        }
    }
};

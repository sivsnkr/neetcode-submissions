class Solution {
    pair<int,int> getcor(int val, int n, int m) {
        int i = val / m;
        int j = val % m;

        return make_pair(i, j);
    }

    int getval(pair<int,int> cor, int m) {
        return m * cor.first + cor.second;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mxv = 50 * 50;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(mxv, vector<int>(mxv, INT_MAX));
        dist[0][grid[0][0]] = grid[0][0];
        pq.emplace(grid[0][0], 0, grid[0][0]);

        vector<int> ip {-1, 1, 0, 0};
        vector<int> jp {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [wt, no, mxc] = pq.top();
            pq.pop();

            if(dist[no][mxc] < wt) continue;

            auto [i, j] = getcor(no, n, m);
            for(int it = 0; it < 4; it++) {
                int ni = i + ip[it], nj = j + jp[it];
                if(ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    int mxval = max(mxc, grid[ni][nj]);
                    int diffval = mxval - mxc;
                    int val = getval(make_pair(ni, nj), m);
                    if(dist[val][mxval] > wt + diffval) {
                        dist[val][mxval] = wt + diffval;
                        pq.emplace(dist[val][mxval], val, mxval);
                    }
                }
            }
        }

        int fval = getval(make_pair(n - 1, m - 1), m);
        return *min_element(dist[fval].begin(), dist[fval].end());
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].emplace_back(j, dist);
                graph[j].emplace_back(i, dist);
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, 0);
        int res = 0;

        pq.emplace(0, 0);
        dist[0] = 0;
        while(!pq.empty()) {
            auto [wt, no] = pq.top();
            pq.pop();

            if(vis[no]) continue;
            vis[no] = 1;
            res += wt;

            for(auto [child, weight] : graph[no]) {
                if(!vis[child] && dist[child] > weight) {
                    dist[child] = weight;
                    pq.emplace(dist[child], child);
                }
            }
        }

        return res;
    }
};

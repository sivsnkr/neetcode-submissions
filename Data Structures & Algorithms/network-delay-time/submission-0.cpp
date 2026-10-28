class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for(auto &it : times) {
            graph[it[0]].emplace_back(it[1], it[2]);
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> vis(n + 1, 0);
        pq.emplace(0, k);
        dist[k] = 0;
        dist[0] = 0;

        while(!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            vis[node] = 1;
            if(dist[node] < weight) continue;

            for(auto [child, cw] : graph[node]) {
                if(!vis[child] && dist[child] > cw + weight) {
                    dist[child] = cw + weight;
                    pq.emplace(dist[child], child);
                }
            }
        }

        int mx = *max_element(dist.begin(), dist.end());
        return mx == INT_MAX ? -1 : mx;
    }
};

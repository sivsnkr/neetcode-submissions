class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for(auto &it : flights) {
            graph[it[0]].emplace_back(it[1], it[2]);
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[src][0] = 0;

        pq.emplace(0, src, 0);
        for(auto [child, weight] : graph[src]) {
            dist[child][0] = weight;
            pq.emplace(weight, child, 0);
        }

        while(!pq.empty()) {
            auto [wt, no, stops] = pq.top();
            pq.pop();

            if(stops > k) continue;
            if(dist[no][stops] < wt) continue;

            for(auto [child, weight] : graph[no]) {
                if(stops + 1 <= k && dist[child][stops + 1] > weight + wt) {
                    dist[child][stops + 1] = weight + wt;
                    pq.emplace(dist[child][stops + 1], child, stops + 1);
                }
            }
        }

        int mi = *min_element(dist[dst].begin(), dist[dst].end());

        return mi == INT_MAX ? -1 : mi;
    }
};

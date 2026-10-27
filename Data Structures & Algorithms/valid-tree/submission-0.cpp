class Solution {
    bool hascycle(int root, int par, vector<vector<int>> &graph, vector<bool> &vis) {
        if(vis[root]) return true;
        vis[root] = 1;

        bool res = false;
        for(int i : graph[root]) {
            if(i != par) {
                res = res || hascycle(i, root, graph, vis);
            }
        }

        return res;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return true;
        vector<vector<int>> graph(n);
        for(auto &it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, 0);
        bool res = hascycle(0, -1, graph, vis);
        for(int i = 1; i < n; i++) {
            if(!vis[i]) return false;
        }
        return !res;
    }
};

class Solution {
    vector<int> par, rank;
    int findpar(int root) {
        if(par[root] == root) return root;
        return par[root] = findpar(par[root]);
    }

    void join(int u, int v) {
        int paru = findpar(u);
        int parv = findpar(v);

        if(rank[paru] > rank[parv]) {
            par[parv] = paru;
        } else if(rank[paru] < rank[parv]) {
            par[paru] = parv;
        }else {
            rank[paru]++;
            par[parv] = paru;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.assign(n + 1, 0);
        iota(par.begin(), par.end(), 0);
        rank.assign(n + 1, 1);

        for(auto &it : edges) {
            int u = it[0], v = it[1];
            int pu = findpar(u), pv = findpar(v);
            if(pu == pv) return it;
            join(u, v);
        }
        return vector<int>();
    }
};

class Solution {
    bool rec(int root, vector<vector<int>> &graph, vector<int> &vis) {
        if(vis[root] == 2) return true;

        vis[root] = 1;
        for(int i : graph[root]) {
            if(vis[i] == 1) {
                return false;
            }else if(vis[i] == 2) continue;
            else if(!rec(i, graph, vis)) {
                return false;
            }
        }
        vis[root] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses, 0);

        for(auto &it : prerequisites) {
            graph[it[0]].push_back(it[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0 && !rec(i, graph, vis)) {
                return false;
            }
        }

        return true;
    }
};

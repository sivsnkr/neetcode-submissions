class Solution {
    int getind(string a, string b) {
        for(int i = 0; i < min(a.length(), b.length()); i++) {
            if(a[i] != b[i]) return i;
        }
        if(a.length() > b.length()) return -1;
        return INT_MAX;
    }

    bool topo(int root, vector<vector<int>> &graph, vector<int> &vis, stack<int> &st) {
        vis[root] = 1;
        for(int child : graph[root]) {
            if(vis[child] == 1) return false;
            else if(vis[child] == 2) continue;
            else if(!topo(child, graph, vis, st)) {
                return false;
            }
        }

        st.emplace(root);
        vis[root] = 2;

        return true;
    }
public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1) return words[0];

        int n = 26;
        vector<vector<int>> graph(n);
        unordered_set<int> charset;

        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                int ind = getind(words[i], words[j]);
                if(ind == -1) return "";
                if(ind == INT_MAX) continue;
                graph[words[i][ind] - 'a'].push_back(words[j][ind] - 'a');
            }

            for(char c : words[i]) {
                charset.emplace(c - 'a');
            }
        }

        vector<int> vis(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0 && !graph[i].empty() && !topo(i, graph, vis, st)) {
                return "";
            }
        }

        string res = "";
        while(!st.empty()) {
            int tp = st.top();
            charset.erase(tp);
            st.pop();
            res += (tp + 'a');
        }

        while(!charset.empty()) {
            int val = *charset.begin();
            charset.erase(charset.begin());
            res += (val + 'a');
        }

        return res;
    }
};

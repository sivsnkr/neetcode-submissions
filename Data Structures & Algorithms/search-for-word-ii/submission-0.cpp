class Solution {
    struct Node {
        vector<Node*> childs;
        bool end;

        Node() {
            childs = vector<Node*>(26, NULL);
            end = false;
        }
    };
    Node* head;
    void rec(int i, int j, int len, vector<vector<char>> &board, vector<vector<bool>> &vis, Node* cur) {
        int n = board.size(), m = board[0].size();
        if(i < 0 || j < 0 || i == n || j == m || vis[i][j] || len == 0) return;
        vis[i][j] = 1;
        if(cur->childs[board[i][j] - 'a'] == NULL) {
            cur->childs[board[i][j] - 'a'] = new Node();
        }

        vector<int> ip{-1, 1, 0, 0};
        vector<int> jp{0, 0, -1, 1};

        for(int it = 0; it < 4; it++) {
            int ni = i + ip[it], nj = j + jp[it];
            rec(ni, nj, len - 1, board, vis, cur->childs[board[i][j] - 'a']);
        }

        vis[i][j] = 0;
    }

    bool startsWith(string &prefix) {
        Node* ch = head;
        for(char c : prefix) {
            if(ch->childs[c - 'a'] == NULL) {
                return false;
            }
            ch = ch->childs[c - 'a'];
        }
        return true;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        head = new Node();
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rec(i, j, 10, board, vis, head);
            }
        }

        vector<string> res;
        for(string &te : words) {
            if(startsWith(te)) {
                res.push_back(te);
            }
        }
        return res;

    }
};

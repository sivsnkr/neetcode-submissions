class Solution {
    void rec(int op, int cl, string &buf, vector<string> &res) {
        if(op == 0 && cl == 0) {
            res.push_back(buf);
            return;
        }

        if(op > 0) {
            buf += '(';
            rec(op - 1, cl, buf, res);
            buf.pop_back();
        }

        if(cl > op) {
            buf += ')';
            rec(op, cl - 1, buf, res);
            buf.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string buf = "";
        vector<string> res;
        rec(n, n, buf, res);
        return res;
    }
};

class Solution {
    void rec(int target, int i, vector<int> &c, vector<vector<int>> &res, vector<int> &buf) {
        if(target < 0) return;
        if(target == 0) {
            res.push_back(buf);
            return;
        }

        if(i == c.size()) {
            return;
        }

        // incude i
        buf.push_back(c[i]);
        rec(target - c[i], i + 1, c, res, buf);
        buf.pop_back();

        if(c[i] > target) return;
        
        int j = i;
        while(j < c.size() && c[j] == c[i]) j++;
        rec(target, j, c, res, buf);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> buf;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        rec(target, 0, candidates, res, buf);
        return res;
    }
};

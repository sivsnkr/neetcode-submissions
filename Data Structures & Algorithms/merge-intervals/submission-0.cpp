class Solution {
    bool iover(vector<int> &a, vector<int> &b) {
        if(a[1] < b[0] || a[0] > b[1]) return false;
        return true;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        int r = 0, n = intervals.size();
        while(r < n) {
            vector<int> cur = intervals[r];
            int it = r;
            while(it < n && iover(cur, intervals[it])) {
                cur[0] = min(cur[0], intervals[it][0]);
                cur[1] = max(cur[1], intervals[it][1]);
                it++;
            }

            res.push_back(cur);
            r = it;
        }

        return res;
    }
};

class Solution {
    bool isoverlapping(vector<int> &i1, vector<int> &i2) {
        if(i2[1] < i1[0] || i2[0] > i1[1]) return false;
        return true;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int l;
        for(l = 0; l < n; l++) {
            if(intervals[l][1] < newInterval[0]) res.push_back(intervals[l]);
            else break;
        }
        int i;
        for(i = l; i < n; i++) {
            if(isoverlapping(intervals[i], newInterval)) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }else break;
        }
        res.push_back(newInterval);
        for(int it = i; it < n; it++) {
            res.push_back(intervals[it]);
        }
        return res;
        // bool found = false;
        // vector<int> ci = newInterval;
        // for(auto &it : intervals) {
        //     if(!isoverlapping(it, newInterval)) {
        //         if(!found) {
        //             res.push_back(it);
        //         }else {
        //             res.push_back(ci);
        //             found = false;
        //             res.push_back(it);
        //         }
        //     }else {
        //         ci[0] = min(ci[0], it[0]);
        //         ci[1] = max(ci[1], it[1]);
        //         found = true;
        //     }
        // }

        // if(found) res.push_back(ci);

        // return res;
    }
};

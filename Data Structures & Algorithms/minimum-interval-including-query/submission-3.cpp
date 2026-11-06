class Solution {
    bool isover(vector<int> &it, int val) {
        if(val >= it[0] && val <= it[1]) return true;
        return false;
    }
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size(), q = queries.size();
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> qu;
        for(int i = 0; i < queries.size(); i++) {
            qu.emplace_back(queries[i], i);
        }
        sort(qu.begin(), qu.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> res(queries.size());
        int i = 0, j = 0;
        while(j < queries.size()) {
            // while(i < n && intervals[i][1] < qu[j].first) i++;
            while(i < n && intervals[i][0] <= qu[j].first) {
                pq.emplace(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top().second < qu[j].first) pq.pop();

            if(pq.empty()) {
                res[qu[j].second] = -1;
            }else {
                res[qu[j].second] = pq.top().first;
            }
            j++;
        }

        return res;
    }
};

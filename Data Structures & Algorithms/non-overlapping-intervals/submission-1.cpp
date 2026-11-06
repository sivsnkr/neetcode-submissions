class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), res = 0;

        for(int i = 0; i < n; i++) {
            while(!pq.empty() && intervals[i][0] >= pq.top()) pq.pop();
            if(pq.empty()) {
                pq.emplace(intervals[i][1]);
                res++;
            }else {
                if(pq.top() > intervals[i][1]) { 
                    pq.pop();
                    pq.emplace(intervals[i][1]);
                }
            }
        }

        return n - res;
    }
};

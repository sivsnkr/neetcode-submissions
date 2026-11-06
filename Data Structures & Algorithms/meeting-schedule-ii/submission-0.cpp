/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) -> bool{
            if(a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });

        int res = 0;
        for(auto &it : intervals) {
            while(!pq.empty() && pq.top() <= it.start) pq.pop();
            pq.emplace(it.end);
            res = max(res, (int)pq.size());
        }
        return res;
    }
};

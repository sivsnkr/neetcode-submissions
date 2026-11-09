class CountSquares {
private:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;

    long getKey(int x, int y) const {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

public:
    CountSquares() {
    }

    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        ptsCount[key]++;
        pts.push_back(point);
    }

    int count(vector<int> point) const {
        int res = 0;
        int px = point[0], py = point[1];

        for (const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            if (abs(py - y) != abs(px - x) || x == px || y == py) continue;
            auto p1 = ptsCount.find(getKey(x, py));
            auto p2 = ptsCount.find(getKey(px, y));
            if (p1 != ptsCount.end() && p2 != ptsCount.end()) {
                res += p1->second * p2->second;
            }
        }
        return res;
    }
};
class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        while(!left.empty()) left.pop();
        while(!right.empty()) right.pop();
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) {
            left.emplace(num);
        }else if(num > left.top()) {
            right.emplace(num);
        }

        int n = left.size(), m = right.size();

        if((abs(n - m) > 1 && (n + m) % 2) || (n != m && (n + m) % 2 == 0)) {
            if(left.size() > right.size()) {
                int tp = left.top();
                left.pop();
                right.emplace(tp);
            }else {
                int tp = right.top();
                right.pop();
                left.emplace(tp);
            }
        }
    }
    
    double findMedian() {
        int n = left.size(), m = right.size();
        if((n + m) % 2) {
            if(n > m) return left.top();
            return right.top();
        }
        int le = left.top();
        int re = right.top();

        return ((double)le + re) / 2;
    }
};

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) {
        while(!pq.empty()) pq.pop();
        k = _k;
        for(int i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if(pq.size() >= k) {
            if(pq.top() < val) {
                pq.pop();
                pq.emplace(val);
            }
        } else {
            pq.emplace(val);
        }
        

        return pq.top();
    }
};

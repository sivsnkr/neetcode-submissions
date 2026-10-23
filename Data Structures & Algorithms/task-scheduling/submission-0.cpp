class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        for(char c : tasks) {
            cnt[c - 'A']++;
        }

        priority_queue<int> pq;

        for(int i = 0; i < 26; i++) {
            if(cnt[i]) pq.emplace(cnt[i]);
        }
        int res = 0;

        while(!pq.empty()) {
            vector<int> tcnt;
            int i;
            for(i = 0; i <= n && !pq.empty(); i++) {
                int tp = pq.top();
                pq.pop();
                if(tp - 1 > 0) tcnt.push_back(tp - 1);
                res++;
            }

            if(tcnt.size() > 0)
                res += (n + 1 - i);

            for(int i : tcnt) pq.emplace(i);
        }

        return res;
    }
};

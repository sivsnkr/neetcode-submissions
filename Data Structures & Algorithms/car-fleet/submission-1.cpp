class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> ps;
        for(int i = 0; i < n; i++) ps.emplace_back(position[i], speed[i]);
        sort(ps.begin(), ps.end());
        
        stack<pair<int,int>> st;
        int res = 0;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty()) {
                auto [tpp, tps] = st.top();
                if((long long)(target - ps[i].first) * tps > (long long)ps[i].second * (target - tpp)) st.pop();
                else break;
            }
            if(st.empty()) res++;
            st.emplace(ps[i]);
        }

        return res;
    }
};

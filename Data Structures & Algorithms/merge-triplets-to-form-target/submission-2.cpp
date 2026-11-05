class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        set<int> res;
        for(int i = 0; i < n; i++) res.insert(i);

        for(int i = 0; i < 3; i++) {
            if(res.empty()) return false;
            vector<int> te;
            for(int it : res) {
                if(triplets[it][i] > target[i]) te.push_back(it);
            }
            for(int it : te) res.erase(it);
        }

        vector<int> tt(3, INT_MIN);
        for(int i = 0; i < 3; i++) {
            for(int it : res) {
                tt[i] = max(tt[i], triplets[it][i]);
            }
        }

        for(int i = 0; i < 3; i++) {
            if(target[i] != tt[i]) return false;
        }

        return true;
    }
};

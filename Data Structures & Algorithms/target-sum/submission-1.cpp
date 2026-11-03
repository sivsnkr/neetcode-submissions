class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int> cnt;
        cnt[0] = 1;

        for(int i : nums) {
            unordered_map<int,int> te;
            for(auto it : cnt) {
                te[it.first + i] += it.second;
                te[it.first - i] += it.second;
            }

            cnt = te;
        }

        return cnt[target];
    }
};

class Solution {
    vector<vector<int>> mem;
    int rec(int l, int r, vector<int> &nums) {
        if(l > r) return false;

        if(mem[l][r] != -1) return mem[l][r];

        int res = 0;

        for(int it = l; it <= r; it++) {
            int val = nums[it] * nums[l - 1] * nums[r + 1];
            res = max(res, val + rec(l, it - 1, nums) + rec(it + 1, r, nums));
        }

        return mem[l][r] = res;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        mem.assign(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return rec(1, nums.size() - 2, nums);
    }
};

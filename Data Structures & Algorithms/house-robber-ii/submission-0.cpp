class Solution {
    int getval(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            if(i - 2 >= 0) {
                dp[i] = max(dp[i], dp[i - 2] + nums[i]);
            }else {
                dp[i] = max(dp[i], nums[i]);
            }
        }

        return dp.back();
    }
public:
    int rob(vector<int>& nums) {
        int val = nums[0];
        if(nums.size() == 1) return nums[0];
        int lval = nums.back();
        if(nums.size() == 2) return max(val, lval);

        nums.erase(nums.begin());
        int val1 = getval(nums);
        nums.insert(nums.begin(), val);
        nums.pop_back();
        int val2 = getval(nums);

        return max(val1, val2);
    }
};

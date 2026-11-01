class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if(nums[0] > 0) {
            dp[0][0] = nums[0];
        }else if(nums[0] < 0) {
            dp[0][1] = nums[0];
        }

        int res = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] > 0) {
                dp[i][0] = max(nums[i], nums[i] * dp[i - 1][0]);
                dp[i][1] = min(nums[i], nums[i] * dp[i - 1][1]);
            }else if(nums[i] < 0) {
                dp[i][0] = max(nums[i], nums[i] * dp[i - 1][1]);
                dp[i][1] = min(nums[i], nums[i] * dp[i - 1][0]);
            }

            res = max(res, dp[i][0]);
        }

        return res;
    }
};

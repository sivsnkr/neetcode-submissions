class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if(totSum % 2 != 0) return false;
        int dsum = totSum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(dsum + 1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int tar = 1; tar <= dsum; tar++) {
                dp[i][tar] = dp[i - 1][tar];
                if(nums[i - 1] <= tar && !dp[i][tar]) {
                    dp[i][tar] = dp[i - 1][tar - nums[i - 1]];
                }
            }
        }

        return dp[n][dsum];
    }
};

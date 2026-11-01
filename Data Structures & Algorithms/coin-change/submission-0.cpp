class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int amt = 1; amt <= amount; amt++) {
            for(int i : coins) {
                if(amt >= i && dp[amt - i] != INT_MAX) {
                    dp[amt] = min(dp[amt], dp[amt - i] + 1);
                }
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};

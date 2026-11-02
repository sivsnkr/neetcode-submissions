class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        int n = coins.size();

        for(int i : coins) {
            for(int amt = 1; amt <= amount; amt++) {
                if(amt >= i)
                    dp[amt] += dp[amt - i];
            }
        }

        return dp[amount];
    }
};

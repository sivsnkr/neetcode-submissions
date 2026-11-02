class Solution {
    vector<int> mem;
    int rec(int i, vector<int> &prices) {
        if(i >= prices.size()) return 0;

        if(mem[i] != -1) return mem[i];

        int res = rec(i + 1, prices);

        for(int it = i + 1; it < prices.size(); it++) {
            int profit = prices[it] - prices[i];
            res = max(res, profit + rec(it + 2, prices));
        }

        return mem[i] = res;
    }
public:
    int maxProfit(vector<int>& prices) {
        mem.assign(prices.size(), -1);
        return rec(0, prices);
    }
};

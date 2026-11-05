class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(cost.begin(), cost.end(), 0) > accumulate(gas.begin(), gas.end(), 0)) return -1;

        int res = 0, csum = 0;

        for(int i = 0; i < gas.size(); i++) {
            int val = gas[i] - cost[i];
            if(csum < 0) {
                csum = 0;
                res = i;
            }
            csum += val;
        }

        return res;
    }
};

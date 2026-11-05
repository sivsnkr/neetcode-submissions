class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, csum = 0;
        for(int i : nums) {
            if(csum < 0) {
                csum = 0;
            }
            csum += i;

            res = max(res, csum);
        }
        return res;
    }
};

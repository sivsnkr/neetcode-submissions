class Solution {
public:
    int jump(vector<int>& nums) {
        int cm = 0, gm = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            gm = max(gm, i + nums[i]);
            if(i == cm) {
                if(i != nums.size() - 1)
                    res++;
                cm = gm;
            }
        }
        return res;
    }
};

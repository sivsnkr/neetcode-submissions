class Solution {
public:
    bool canJump(vector<int>& nums) {
        int wm = 0, cm = 0;
        // int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            wm = max(wm, i + nums[i]);
            if(i == cm) {
                if(wm == cm && i != nums.size() - 1) return false;
                cm = wm;
                // res++;
            }
        }

        return cm >= nums.size() - 1;
    }
};

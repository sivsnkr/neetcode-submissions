class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i : nums) {
            if(i < 0) i = -i;
            int val = nums[i - 1];
            if(val < 0) return i;
            nums[i - 1] = -val;
        }
        return 0;
    }
};
